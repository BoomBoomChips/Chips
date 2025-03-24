# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.15)

project(Chips)

# 如果支持，请为 MSVC 编译器启用热重载。
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()



#-----------------------------------------
# 全局配置选项
#-----------------------------------------
# 设置C++标准（推荐C++17或更高）
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)  # 禁用编译器扩展（如gcc的-std=gnu++17）

# 输出目录配置
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#-----------------------------------------
# 第三方依赖管理
#-----------------------------------------
# 选项示例：是否使用系统安装的库
option(USE_SYSTEM_JSON "Use system-installed JSON library" OFF)

# 1. 使用find_package查找系统库
#find_package(OpenSSL REQUIRED)  # 查找OpenSSL
#
## 2. 使用FetchContent获取第三方库
#include(FetchContent)
#if(NOT USE_SYSTEM_JSON)
#    FetchContent_Declare(
#        json
#        GIT_REPOSITORY https://github.com/nlohmann/json.git
#        GIT_TAG        v3.11.2
#    )
#    FetchContent_MakeAvailable(json)
#endif()

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(ChipsThirdPartyDir ${PROJECT_SOURCE_DIR}/3rdparty)

#-----------------------------------------
# 第三方依赖管理 Qt
#-----------------------------------------
include(qt.cmake)
set(CMAKE_PREFIX_PATH ${ChipsThirdPartyDir}/qt6.7.0-x64)
qt_standard_project_setup()

set(QtDllDir "${ChipsThirdPartyDir}/qt6.7.0-x64/bin")
set(QtPluginDir "${ChipsThirdPartyDir}/qt6.7.0-x64/plugins")
set(QtDll 
    "${QtDllDir}/Qt6Cored.dll"
    "${QtDllDir}/Qt6Widgetsd.dll"
    "${QtDllDir}/Qt6Guid.dll"
)

find_package(QT NAMES Qt6 Qt5 REQUIRED)
find_package(Qt${QT_VERSION_MAJOR}
    COMPONENTS
        Core
        Gui
        Qml
        Quick
        Widgets
        REQUIRED
)

add_library(qt_global INTERFACE)
#target_include_directories()
target_link_libraries(qt_global INTERFACE 
    Qt6::Core 
    Qt6::Gui 
    Qt6::Widgets
)

#-----------------------------------------
# 子目录包含
#-----------------------------------------
# 核心库
#add_subdirectory(src/core)

# GUI模块（条件编译）
#option(BUILD_GUI "Build GUI components" ON)
#if(BUILD_GUI)
#    find_package(Qt6 COMPONENTS Core Widgets REQUIRED)
#    add_subdirectory(src/gui)
#endif()


# 主程序
add_subdirectory(src/app)
#include(src/app/CMakeLists.txt)

# 测试模块
#enable_testing()
#add_subdirectory(tests)

#-----------------------------------------
# 安装规则
#-----------------------------------------
# 安装可执行文件
#install(TARGETS ${PROJECT_NAME}
#    RUNTIME DESTINATION bin
#    BUNDLE  DESTINATION bin
#)

# 安装资源文件
#install(DIRECTORY resources/
#    DESTINATION share/${PROJECT_NAME}
#    PATTERN ".gitkeep" EXCLUDE
#)

#-----------------------------------------
# 包配置（可选）
#-----------------------------------------
#include(CPackConfig.cmake)

#-----------------------------------------
# 自定义目标
#-----------------------------------------
# 代码格式化目标
#find_program(CLANG_FORMAT "clang-format")
#if(CLANG_FORMAT)
#    file(GLOB_RECURSE ALL_SOURCE_FILES
#        src/*.cpp
#        src/*.h
#        tests/*.cpp
#    )
#    add_custom_target(format
#        COMMAND ${CLANG_FORMAT} -i --style=file ${ALL_SOURCE_FILES}
#        COMMENT "Formatting source code..."
#    )
#endif()

#-----------------------------------------
# 拷贝依赖文件
#-----------------------------------------
message("-----------------------------------------")
message("拷贝依赖文件")
message("-----------------------------------------")
file(COPY ${QtDll} DESTINATION ${CMAKE_BINARY_DIR}/bin)
file(COPY ${QtPluginDir} DESTINATION ${CMAKE_BINARY_DIR}/bin)


# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.16)
project (
	Chips
	VERSION 1.0.0
    DESCRIPTION "跨平台C++客户端程序"
    LANGUAGES CXX
)

# 如果支持，请为 MSVC 编译器启用热重载。
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

#-----------------------------------------
# 全局配置选项
#-----------------------------------------
# 设置C++标准（推荐C++17或更高）
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)  # 禁用编译器扩展（如gcc的-std=gnu++17）

# 提高编译速度
set(BUILD_SHARED_LIBS ON)
set(CMAKE_BUILD_PARALLEL_LEVEL 24)
if(NOT CMAKE_GENERATOR)
    set(CMAKE_GENERATOR "Ninja" CACHE INTERNAL "" FORCE)
endif()

# 输出目录配置
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR}/bin)

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
#========= Qt =========
#-----------------------------------------

include(qt.cmake)
set(CMAKE_PREFIX_PATH "${ChipsThirdPartyDir}/qt6.7.0-x64")
qt_standard_project_setup()

set(QtDir ${ChipsThirdPartyDir}/qt6.7.0-x64)
set(QtIncludeDir "${ChipsThirdPartyDir}/qt6.7.0-x64/include")
set(QtBinDir "${ChipsThirdPartyDir}/qt6.7.0-x64/bin")
set(QtLibDir "${ChipsThirdPartyDir}/qt6.7.0-x64/lib")
set(QtPluginDir "${ChipsThirdPartyDir}/qt6.7.0-x64/plugins")

if(CMAKE_BUILD_TYPE STREQUAL "Debug" OR "RelWithDebinfo")
    set(LINK_QT_DLLS 
    "${QtBinDir}/Qt6Cored.dll"
    "${QtBinDir}/Qt6Widgetsd.dll"
    "${QtBinDir}/Qt6Guid.dll"

    "${QtPluginDir}/platforms/qdirect2dd.dll"
    "${QtPluginDir}/platforms/qminimald.dll"
    "${QtPluginDir}/platforms/qoffscreend.dll"
    "${QtPluginDir}/platforms/qwindowsd.dll"
    )

    set(LINK_QT_LIBS
    "${QtBinDir}/Qt6Cored.lib"
    "${QtBinDir}/Qt6Widgetsd.lib"
    "${QtBinDir}/Qt6Guid.lib"

    #"${QtPluginDir}/platforms/qdirect2dd.lib"
    #"${QtPluginDir}/platforms/qminimald.lib"
    #"${QtPluginDir}/platforms/goffscreend.lib"
    #"${QtPluginDir}platforms/qwindowsd.lib"
    )
else()
    set(LINK_QT_DLLS 
    "${QtBinDir}/Qt6Core.dll"
    "${QtBinDir}/Qt6Widgets.dll"
    "${QtBinDir}/Qt6Gui.dll"

    "${QtPluginDir}/platforms/qdirect2d.dll"
    "${QtPluginDir}/platforms/qminimal.dll"
    "${QtPluginDir}/platforms/qoffscreen.dll"
    "${QtPluginDir}/platforms/qwindows.dll"
    )

    set(LINK_QT_LIBS
    "${QtBinDir}/Qt6Core.lib"
    "${QtBinDir}/Qt6Widgets.lib"
    "${QtBinDir}/Qt6Gui.lib"

    #"${QtPluginDir}/platforms/qdirect2dd.lib"
    #"${QtPluginDir}/platforms/qminimald.lib"
    #"${QtPluginDir}/platforms/goffscreend.lib"
    #"${QtPluginDir}platforms/qwindowsd.lib"
    )
endif()

# 启用 Qt 的自动处理功能
set(CMAKE_AUTOMOC ON)    # 处理 Qt 的 moc（元对象编译器）
set(CMAKE_AUTOUIC ON)    # 处理 .ui 文件（关键配置）
set(CMAKE_AUTORCC ON)    # 处理资源文件（可选）

#set(AUTOGEN_BUILD_DIR ${CMAKE_CURRENT_BINARY_DIR})
#message(autogen${AUTOGEN_BUILD_DIR})

find_package(QT NAMES Qt6 Qt5 REQUIRED)
find_package(Qt${QT_VERSION_MAJOR}
    COMPONENTS
        Core
        Gui
        Widgets
        SVG
        REQUIRED
)

#-----------------------------------------
#============= Boost =============
#-----------------------------------------

#-----------------------------------------
#============= Osg =============
#-----------------------------------------
set(CMAKE_PREFIX_PATH "${ChipsThirdPartyDir}/OpenSceneGraph-3.6.5-VC2022-64")
set(OSG_DIR "${ChipsThirdPartyDir}/OpenSceneGraph-3.6.5-VC2022-64")
set(OsgInclude "${OSG_DIR}/include")
set(OsgBin "${OSG_DIR}/bin")
set(OsgLib "${OSG_DIR}/lib")
set(OsgPluginDir "${OSG_DIR}/bin/osgPlugins-3.6.5")

#target_include_directories(OSG_365 PUBLIC)

if(CMAKE_BUILD_TYPE STREQUAL "Debug" OR "RelWithDebInfo")
set(OSG_LINK_DLLS
    ${OsgBin}/osgd.dll
    ${OsgBin}/osgGAd.dll
    ${OsgBin}/osgViewerd.dll
    ${OsgBin}/osgUtild.dll
    ${OsgBin}/osgDBd.dll
    ${OsgBin}/osgTextd.dll
    ${OsgBin}/openThreadsd.dll
    ${OsgBin}/osgManipulatord.dll
    ${OsgBin}/zlibd.dll
    ${OsgBin}/osgUId.dll
    ${OsgBin}/osgUtild.dll
    ${OsgBin}/osgWidgetd.dll
)
set(OSG_LINK_LIB
    ${OsgLib}/osgd.lib
    ${OsgLib}/osgGAd.lib
    ${OsgLib}/osgViewerd.lib
    ${OsgLib}/osgUtild.lib
    ${OsgLib}/osgDBd.lib
    ${OsgLib}/osgTextd.lib
    ${OsgLib}/openThreadsd.lib
    ${OsgLib}/osgManipulatord.lib
    ${OsgLib}/osgUId.lib
    ${OsgLib}/osgUtild.lib
    ${OsgLib}/osgWidgetd.lib
)
else(CMAKE BUILD TYPE STREQUAL "Release")
set(OSG_LINK_DLLS
    ${OsgBin}/osg.dll
    ${OsgBin}/osgGA.dll
    ${OsgBin}/osgViewer.dll
    ${OsgBin}/osgUtil.dll
    ${OsgBin}/osgDB.dll
    ${OsgBin}/osgText.dll
    ${OsgBin}/OpenThreads.dll
    ${OsgBin}/osgManipulator.dll
    ${OsgBin}/zlib.dll
    ${OsgBin}/osgUI.dll
    ${OsgBin}/osgUtil.dll
    ${OsgBin}/osgWidget.dll
)
set(OSG_LINK_LIB
    ${OsgLib}/osg.lib
    ${OsgLib}/osgGA.lib
    ${OsgLib}/osgViewer.lib
    ${OsgLib}/osgUtil.lib
    ${OsgLib}/osgDB.lib
    ${OsgLib}/osgText.lib
    ${OsgLib}/OpenThreads.lib
    ${OsgLib}/osgManipulator.lib
    ${OsgLib}/osgUI.lib
    ${OsgLib}/osgUtil.lib
    ${OsgLib}/osgWidget.lib
)
endif()


#-----------------------------------------
#============= Occt =============
#-----------------------------------------
set(OCCT_DIR ${ChipsThirdPartyDir}/occt-vc144-64)
set(OcctInclude ${OCCT_DIR}/inc)

#set(CMAKE_PREFIX_PATH ${OCCT_DIR})
#find_package(OpenCASCADE COMPONENTS
#    FoundationClasses 
#    ModelingData
#    DataExchange
#    REQUIRED
#)

if(CMAKE_BUILD_TYPE STREQUAL "Debug" OR "RelWithDebinfo")
    set(OcctBinDir ${OCCT_DIR}/win64/vc14/bind)
    set(OcctLibDir ${OCCT_DIR}/win64/vc14/libd)
else()
    set(OcctBinDir ${OCCT_DIR}/win64/vc14/bin)
    set(OcctLibDir ${OCCT_DIR}/win64/vc14/lib)
endif()

set(LINK_OCCT_LIBS
    "${OcctLibDir}/TKBin.lib"
    "${OcctLibDir}/TKBO.1ib"
    "${OcctLibDir}/TKBRep.lib"
    "${OcctLibDir}/TKernel.lib"
    "${OcctLibDir}/TKG2d.lib"
    "${OcctLibDir}/TKG3d.lib"
    "${OcctLibDir}/TKGeomAlgo.lib"
    "${OcctLibDir}/TKGeomBase.lib"
    "${OcctLibDir}/TKMath.lib"
    "${OcctLibDir}/TKMesh.lib"
    "${OcctLibDir}/TKOffset.lib"
    "${OcctLibDir}/TKPrim.lib"
    "${OcctLibDir}/TKShHealing.lib"
    "${OcctLibDir}/TKTopAlgo.lib"
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


set(SubProjInc 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/
    ${CMAKE_CURRENT_SOURCE_DIR}/src/gui
    ${CMAKE_CURRENT_SOURCE_DIR}/src/render
)

message(=====${CMAKE_CURRENT_SOURCE_DIR}/src/gui======)
set(SubProjLib ChipsGuiLib)

# 主程序
add_subdirectory(src/gui)
add_subdirectory(src/app)
add_subdirectory(src/render)
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
file(COPY ${LINK_QT_DLLS} DESTINATION ${CMAKE_BINARY_DIR}/bin)
file(COPY ${QtPluginDir} DESTINATION ${CMAKE_BINARY_DIR}/bin)
file(COPY ${OSG_LINK_DLLS} DESTINATION ${CMAKE_BINARY_DIR}/bin)
file(COPY ${OsgPluginDir} DESTINATION ${CMAKE_BINARY_DIR}/bin)

#收集库
#file(GLOB_OSGRENDER_DYNAMIC_LIB
##TODO:只饰选要用的0SG动态库$ÃOSG_BIN_PATH}/*${dynamic library_ext}*#TODO:只筛选要用的0CC动志库${ОCC_BIN_PATH}/*${dynamic library_ext)*
#fiLe(GLOB_OSG_PLUGINS DYNAMIC_LIB
##TOD0:只筛选要用的0SG播件动态库
#${OSG_BIN_PLUGINS_PATH}/*${dynamic_library_ext}*
#)
#fiLe(GLOB RECURSE OSGRENDER RESOURCE
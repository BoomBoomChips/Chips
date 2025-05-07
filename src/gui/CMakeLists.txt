
# GUI模块CMake配置
cmake_minimum_required(VERSION 3.16)  # Qt6需要CMake 3.16+
project(gui)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(UI_FILES
    ChipsMainWindow.ui
    "components/ChipsRenderMdiArea.ui"
)

QT6_WRAP_UI(${UI_FILES})

source_group("components" FILES 
    "components/ChipsRenderMdiArea.h"
    "components/ChipsRenderMdiArea.cpp"
    "components/ChipsRenderMdiArea.ui"
)


# 声明GUI库目标
add_library(ChipsGui SHARED
    "components/ChipsRenderMdiArea.h"
    "components/ChipsRenderMdiArea.cpp"
    ChipsMainWindow.h
    ChipsMainWindow.cpp
    ${UI_FILES}
)



# 设置目标属性
set_target_properties(ChipsGui PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

message(autogendir${AUTOGEN_BUILD_DIR})

#target include_directories(TwEntity PRIVATE
#${GLM_PATH}
#${OCC_INCLUDE_PATH)
#)

# 设置包含目录
target_include_directories(ChipsGui 
  PRIVATE 
   ${OsgInclude}
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/ChipsGui_autogen/include>  # 自动生成目录
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>             # 原始头文件目录
)

# 定义导出宏（仅在构建此库时生效）
target_compile_definitions(ChipsGui PRIVATE
    CHIPS_EXPORTS  # 触发 dllexport
)

# 链接Qt库
target_link_libraries(ChipsGui PUBLIC
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Qt6::Svg        # 可选SVG支持

    ChipsRender
    ${OSG_LINK_LIB}
)

# 安装规则（可选）
install(TARGETS ChipsGui
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
)

install(DIRECTORY include/ DESTINATION include)

#--------------------------------------------------
# 可执行文件配置（如果生成独立GUI程序）
#--------------------------------------------------
#if(BUILD_GUI_APP)
#    add_executable(gui_app
#        main.cpp
#        ${PROJECT_SOURCE_DIR}/icons/app_icon.icns  # macOS图标
#    )
#
#    # 设置应用属性
#    set_target_properties(gui_app PROPERTIES
#        MACOSX_BUNDLE TRUE
#        MACOSX_BUNDLE_ICON_FILE app_icon.icns
#        WIN32_EXECUTABLE TRUE
#    )
#
#    # 链接GUI库
#    target_link_libraries(gui_app PRIVATE
#        gui_lib
#        Qt6::Core
#        Qt6::Widgets
#    )
#
#    # 安装规则
#    install(TARGETS gui_app
#        RUNTIME DESTINATION bin
#        BUNDLE  DESTINATION bin
#        MACOSX_BUNDLE_DESTINATION Applications
#    )
#endif()

#--------------------------------------------------
# 与父项目的集成配置
#--------------------------------------------------
# 导出头文件（供其他模块使用）
target_sources(ChipsGui PUBLIC
    FILE_SET HEADERS
    BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}
    FILES
        ChipsMainWindow.h
)

# 包含第三方UI组件（示例）
#qt_add_qml_module(qml_components
#    URI QmlComponents
#    VERSION 1.0
#    RESOURCE_PREFIX /components
#    QML_FILES
#        components/Button.qml
#        components/Slider.qml
#)


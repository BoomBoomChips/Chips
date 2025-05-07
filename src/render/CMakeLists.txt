
# GUI模块CMake配置
cmake_minimum_required(VERSION 3.16)  # Qt6需要CMake 3.16+
project(render)

# 声明GUI库目标
add_library(ChipsRender SHARED
    RenderArea.h
    RenderArea.cpp
    #${UI_FILES}
)

# 设置目标属性
set_target_properties(ChipsRender PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

# 设置包含目录
target_include_directories(ChipsRender 
  PRIVATE 
    #$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/ChipsRender_autogen/include>  # 自动生成目录
    #$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>             # 原始头文件目录
    ${OsgInclude}
)

#target_include_directories(TwRender 
#    PRIVATE
#    ${OSG INCLUDE_PATH}
#    ${GLM PATH}
#    $(BOOST INCLUDE PATH]
#    $(OSGRENDER CONMON_PATH}
#    $(OSGRENDER TWENTITY PATH}
#    )



# 定义导出宏（仅在构建此库时生效）
target_compile_definitions(ChipsRender PRIVATE
    MYLIB_EXPORTS  # 触发 dllexport
)

#set(CMAKE_PREFIX_PATH "${OsgLib}/lib")
#target_link_directories(ChipsRender PRIVATE
#    ${OsgLib}
#)
#message(osg ${OsgLib})



target_link_libraries(ChipsRender PRIVATE
    ${OSG_LINK_LIB}
)

#target_link_libraries(ChipsRender PRIVATE
#    ${OsgLib}/osgViewerd.lib
#    ${OsgLib}/osgTextd.lib
#    ${OsgLib}/opengl32.lib
#    ${OsgLib}/osgGAd.lib
#    ${OsgLib}/osgDBd.lib
#    ${OsgLib}/osgUtild.lib
#    ${OsgLib}/osgd.lib
#
#OpenThreadsd.lib
#kernel32.lib
#user32.lib
#gdi32.lib
#winspool.lib
#shell32.lib
#ole32.lib
#oleaut32.lib
#uuid.lib
#comdlg32.lib
#advapi32.lib
#    osgViewerd.lib
#osgTextd.lib
#opengl32.lib
#osgGAd.lib
#osgDBd.lib
#osgUtild.lib
#osgd.lib
#OpenThreadsd.lib
#kernel32.lib
#user32.lib
#gdi32.lib
#winspool.lib
#shell32.lib
#ole32.lib
#oleaut32.lib
#uuid.lib
#comdlg32.lib
#advapi32.lib
#    osgViewerd.lib
#osgTextd.lib
#opengl32.lib
#osgGAd.lib
#osgDBd.lib
#osgUtild.lib
#osgd.lib
#OpenThreadsd.lib
#kernel32.lib
#user32.lib
#gdi32.lib
#winspool.lib
#shell32.lib
#ole32.lib
#oleaut32.lib
#uuid.lib
#comdlg32.lib
#advapi32.lib
#    osgViewerd.lib
#osgTextd.lib
#opengl32.lib
#osgGAd.lib
#osgDBd.lib
#osgUtild.lib
#osgd.lib
#OpenThreadsd.lib
#kernel32.lib
#user32.lib
#gdi32.lib
#winspool.lib
#shell32.lib
#ole32.lib
#oleaut32.lib
#uuid.lib
#comdlg32.lib
#advapi32.lib
#)

# 安装规则（可选）
#install(TARGETS ChipsRender
#  LIBRARY DESTINATION lib
#  ARCHIVE DESTINATION lib
#  RUNTIME DESTINATION bin
#)
#
#install(DIRECTORY include/ DESTINATION include)

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
#target_sources(ChipsGuiLib PUBLIC
#    FILE_SET HEADERS
#    BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}
#    FILES
#        MainWindow.h
#        CustomWidget.h
#)

# 包含第三方UI组件（示例）
#qt_add_qml_module(qml_components
#    URI QmlComponents
#    VERSION 1.0
#    RESOURCE_PREFIX /components
#    QML_FILES
#        components/Button.qml
#        components/Slider.qml
#)

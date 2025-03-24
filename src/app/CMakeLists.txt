# CMakeList.txt: Chips 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#

project (
	Chips
	VERSION 1.0.0
    DESCRIPTION "跨平台C++客户端程序"
    LANGUAGES CXX
)
# 将源代码添加到此项目的可执行文件。

#find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
#find_package(Qt${QT_VERSION_MAJOR}
#    COMPONENTS
#        Core
#        Gui
#        Widgets
#)
#qt_standard_project_setup()

set(PROJECT_SOURCES
    main.cpp
    QtWidgetsApplication.ui
    QtWidgetsApplication.h
    QtWidgetsApplication.cpp
)

#file(GLOB_RECURSE SOURCES "*.cpp")
#file(GLOB_RECURSE HEADERS "*.h")
#file(GLOB_RECURSE FORMS "*.ui")
#file(GLOB_RECURSE RESOURCES "*.qrc")
#add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} ${FORMS} ${RESOURCES})
#target_link_libraries(${PROJECT_NAME}
#    PUBLIC
#        Qt::Core
#        Qt::Gui
#        Qt::Widgets
#)

qt_add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

set_target_properties(${PROJECT_NAME}
    PROPERTIES
        WIN32_EXECUTABLE TRUE
)

target_link_libraries(${PROJECT_NAME} PRIVATE qt_global)
target_link_libraries(${PROJECT_NAME}
    PUBLIC
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

#在构建 MyApp 后拷贝文件到输出目录
#add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
#    COMMAND ${CMAKE_COMMAND} -E copy
#
#        ${CMAKE_CURRENT_SOURCE_DIR}/config.json
#        $<TARGET_FILE_DIR:MyApp>/config.json
#        
#
#    COMMENT "Copying config file..."
#)
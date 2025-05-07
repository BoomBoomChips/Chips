# CMakeList.txt: Chips 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
project(Chips)

# 将源代码添加到此项目的可执行文件。
set(PROJECT_SOURCES
    main.cpp
)

source_group("main" FILES 
    main.cpp
)

qt_add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

set_target_properties(${PROJECT_NAME}
    PROPERTIES
        WIN32_EXECUTABLE TRUE
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${SubProjInc}
    ${OsgInclude}
    ${CMAKE_BINARY_DIR}/src/gui/ChipsGui_autogen/include
    #$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/ChipsGuiLib_autogen/include>  # 自动生成目录
    #$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>             # 原始头文件目录
)
message(inc ${CMAKE_BINARY_DIR}/src/gui/ChipsGuiLib_autogen)
message(inc ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME} PUBLIC 
    ChipsGui
    ChipsRender
    ${OSG_LINK_LIB}
)


#在构建 MyApp 后拷贝文件到输出目录
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
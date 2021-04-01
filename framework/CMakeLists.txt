cmake_minimum_required(VERSION 3.17)
project(framework)

add_subdirectory(component)

################################################
### 配置源码目录 SOURCEALL_DIR
################################################
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SOURCE_DIRECTORY)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/component COMPONENT_SOURCE_DIRECTORY)

add_definitions(-DZENITH_PLATFORM_WINDOWS -DIN_CHINA)

link_libraries(imm32)
link_libraries(${CMAKE_SOURCE_DIR}/library/glfw3.dll)

add_library(
        ${PROJECT_NAME} SHARED
        ${SOURCE_DIRECTORY}
        ${COMPONENT_SOURCE_DIRECTORY}
        ${CMAKE_SOURCE_DIR}/vendor/imgui/imgui.cpp
        ${CMAKE_SOURCE_DIR}/vendor/imgui/imgui_draw.cpp
        ${CMAKE_SOURCE_DIR}/vendor/imgui/imgui_demo.cpp
        ${CMAKE_SOURCE_DIR}/vendor/imgui/imgui_widgets.cpp
        ${CMAKE_SOURCE_DIR}/vendor/imgui/imgui_tables.cpp
        ${CMAKE_SOURCE_DIR}/vendor/imgui/backends/imgui_impl_glfw.cpp
        ${CMAKE_SOURCE_DIR}/vendor/imgui/backends/imgui_impl_opengl3.cpp
)

set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY  ../)

target_link_libraries(${PROJECT_NAME} PRIVATE tool)


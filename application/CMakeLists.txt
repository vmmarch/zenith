cmake_minimum_required(VERSION 3.17)
project(application)

################################################
### 配置源码目录 SOURCEALL_DIR
################################################
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SOURCE_DIR)

add_definitions(-D__ZENITH_PLATFORM_WINDOWS__ -D__IN_CHINA__)

link_libraries(imm32)
link_libraries(${CMAKE_SOURCE_DIR}/library/glfw3.dll)

add_library(
        ${PROJECT_NAME} SHARED
        ${SOURCE_DIR}
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


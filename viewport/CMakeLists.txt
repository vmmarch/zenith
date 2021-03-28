cmake_minimum_required(VERSION 3.17)
project(viewport)

add_definitions(-DZENITH_PLATFORM_WINDOWS)

link_libraries(imm32)
link_libraries(${CMAKE_SOURCE_DIR}/library/glfw3.dll)

add_library(
        ${PROJECT_NAME} SHARED
        glad.c
        viewport.h
        viewport.cpp
        ${CMAKE_SOURCE_DIR}/vendor/imgui/imgui.cpp
        ${CMAKE_SOURCE_DIR}/vendor/imgui/imgui_draw.cpp
        ${CMAKE_SOURCE_DIR}/vendor/imgui/imgui_demo.cpp
        ${CMAKE_SOURCE_DIR}/vendor/imgui/imgui_widgets.cpp
        ${CMAKE_SOURCE_DIR}/vendor/imgui/imgui_tables.cpp
        ${CMAKE_SOURCE_DIR}/vendor/imgui/backends/imgui_impl_glfw.cpp
        ${CMAKE_SOURCE_DIR}/vendor/imgui/backends/imgui_impl_opengl3.cpp
)

set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")


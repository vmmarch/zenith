cmake_minimum_required(VERSION 3.17)
project(viewport)

add_definitions(-DZENITH_PLATFORM_WINDOWS)

include_directories(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/include/SDL2/include)

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
)

target_link_libraries(${PROJECT_NAME} PRIVATE SDL2)

set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")


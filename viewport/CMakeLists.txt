cmake_minimum_required(VERSION 3.17)
project(viewport)

add_definitions(-DZENITH_PLATFORM_WINDOWS)

link_libraries(${CMAKE_SOURCE_DIR}/library/glfw3.dll)

add_library(${PROJECT_NAME} SHARED glad.c viewport.h viewport.cpp)

set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")


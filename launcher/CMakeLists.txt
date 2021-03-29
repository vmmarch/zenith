cmake_minimum_required(VERSION 3.17)
project(launcher)

aux_source_directory(${CMAKE_SOURCE_DIR} SOURCE_DIRECTORY)

set(CMAKE_CXX_STANDARD 20)
add_definitions(-DZENITH_PLATFORM_WINDOWS -DZENITH_BUILD_DLL -DIN_CHINA)

add_library(
        ${PROJECT_NAME} SHARED
        launcher.cpp
        launcher.h
)

set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY  ../)

target_link_libraries(${PROJECT_NAME} PRIVATE viewport)
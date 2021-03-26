cmake_minimum_required(VERSION 3.17)
project(launcher)

aux_source_directory(${CMAKE_SOURCE_DIR} SOURCE_DIRECTORY)

set(CMAKE_CXX_STANDARD 20)
add_definitions(-DZENITH_PLATFORM_WINDOWS -DZENITH_BUILD_DLL)

include_directories(${PROJECT_NAME} ../zenith)

add_library(
        ${PROJECT_NAME} SHARED
        launcher.cpp
        launcher.h
)

SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES PREFIX "")
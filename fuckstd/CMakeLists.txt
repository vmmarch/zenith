cmake_minimum_required(VERSION 3.17)
project(fuckstd)

set(CMAKE_CXX_STANDARD 14)

include_directories(SYSTEM fuckstd)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/io SOURCE_IO)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/tool SOURCE_TOOL)

add_executable(
		${PROJECT_NAME}
		main.cpp
)
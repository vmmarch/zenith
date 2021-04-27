cmake_minimum_required(VERSION 3.17)
project(fuckstd)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/arrays SOURCE_ARRAYS)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/io SOURCE_IO)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/tool SOURCE_TOOL)

add_library(
		${PROJECT_NAME} SHARED
		${SOURCE_IO}
		${SOURCE_ARRAYS}
		${SOURCE_TOOL}
)
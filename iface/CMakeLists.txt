cmake_minimum_required(VERSION 3.17)
project(iface)

################################################
### 配置源码目录 SOURCEALL_DIR
################################################
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SOURCE_DIRECTORY)

add_definitions(-DZENITH_PLATFORM_WINDOWS -DIN_CHINA)

add_library(
		${PROJECT_NAME} SHARED
		engine-iface-config.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE framework)

set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY  ../)
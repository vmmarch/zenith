cmake_minimum_required(VERSION 3.17)
project(tool)

################################################
### 配置源码目录 SOURCEALL_DIR
################################################
aux_source_directory(${CMAKE_CURRENT_LIST_DIR} SOURCE_DIRECTORY)

add_definitions(-D__ZENITH_PLATFORM_WINDOWS__ -D__IN_CHINA__)

add_library(
        ${PROJECT_NAME} SHARED
        ${SOURCE_DIRECTORY}
)

set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY  ../)

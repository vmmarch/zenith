cmake_minimum_required(VERSION 3.17)
project(tool)

################################################
### 配置源码目录 SOURCEALL_DIR
################################################
aux_source_directory(${CMAKE_CURRENT_LIST_DIR} SOURCE_DIRECTORY)

add_definitions(-DZENITH_PLATFORM_WINDOWS -DIN_CHINA)

add_library(
        ${PROJECT_NAME} SHARED
        ${SOURCE_DIRECTORY}
)

set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY  ../)

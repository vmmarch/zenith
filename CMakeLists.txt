cmake_minimum_required(VERSION 3.17)
project(zenith)

################################################
### for vendor dir.
################################################
include_directories(SYSTEM vendor/imgui)
include_directories(SYSTEM vendor/imgui/backends)

################################################
### for include dir.
################################################
include_directories(SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/framework)

add_subdirectory(framework framework_binary_dir)
add_subdirectory(tool tool_binary_dir)

################################################
### 配置源码目录 SOURCEALL_DIR
################################################
aux_source_directory(${CMAKE_SOURCE_DIR} SOURCE_DIRECTORY)

set(CMAKE_CXX_STANDARD 20)

add_definitions(-DZENITH_PLATFORM_WINDOWS -DIN_CHINA)

include_directories(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/launcher)

add_executable(${PROJECT_NAME} ${SOURCE_DIRECTORY})

target_link_libraries(${PROJECT_NAME} PRIVATE framework)

install(
	TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}
)


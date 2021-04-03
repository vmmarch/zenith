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
include_directories(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/application)
include_directories(${CMAKE_SOURCE_DIR}/vendor/spdlog/include)

add_subdirectory(application application_binary_dir)

################################################
### 配置源码目录 SOURCEALL_DIR
################################################
aux_source_directory(${CMAKE_SOURCE_DIR} SOURCE_DIRECTORY)

set(CMAKE_CXX_STANDARD 20)

add_definitions(-D__ZENITH_PLATFORM_WINDOWS__ -D__IN_CHINA__)

include_directories(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/launcher)

add_executable(${PROJECT_NAME} ${SOURCE_DIRECTORY})

target_link_libraries(${PROJECT_NAME} PRIVATE application)

install(
	TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}
)


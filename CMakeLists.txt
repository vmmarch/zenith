cmake_minimum_required(VERSION 3.17)
project(zenith)

add_subdirectory(launcher launcher_binary_dir)

################################################
### ÅäÖÃÔ´ÂëÄ¿Â¼ SOURCEALL_DIR
################################################
aux_source_directory(${CMAKE_SOURCE_DIR} SOURCE_DIRECTORY)
aux_source_directory(${CMAKE_SOURCE_DIR}/zenith SOURCE_FOR_ZENITH)

set(CMAKE_CXX_STANDARD 20)
add_definitions(-DZENITH_PLATFORM_WINDOWS)

include_directories(${PROJECT_NAME} SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/launcher)

add_executable(${PROJECT_NAME} ${SOURCE_DIRECTORY} ${SOURCE_FOR_ZENITH})

target_link_libraries(${PROJECT_NAME} PRIVATE launcher)

install(
	TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}
)


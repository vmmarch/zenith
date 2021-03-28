cmake_minimum_required(VERSION 3.17)
project(zenith)

include_directories(SYSTEM vendor/imgui)
include_directories(SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(launcher ${CMAKE_SOURCE_DIR}/viewport)

add_subdirectory(launcher launcher_binary_dir)
add_subdirectory(viewport viewport_binary_dir)
add_subdirectory(vendor/SDL2 sdl2_binary_dir)

################################################
### ÅäÖÃÔ´ÂëÄ¿Â¼ SOURCEALL_DIR
################################################
aux_source_directory(${CMAKE_SOURCE_DIR} SOURCE_DIRECTORY)

set(CMAKE_CXX_STANDARD 20)
add_definitions(-DZENITH_PLATFORM_WINDOWS)

include_directories(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/launcher)

add_executable(${PROJECT_NAME} ${SOURCE_DIRECTORY})

target_link_libraries(${PROJECT_NAME} PRIVATE launcher)

install(
	TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}
)


cmake_minimum_required(VERSION 3.17)
project(xuanming)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/xuanming SOURCE)

################################################
### for vendor dir.
################################################
include_directories(SYSTEM dependencies/imgui)
include_directories(SYSTEM dependencies/imgui/backends)

################################################
### for include dir.
#################################################
include_directories(SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}/api)
include_directories(SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}/project-include)

################################################
### 配置源码目录 SOURCEALL_DIR
################################################
aux_source_directory(${CMAKE_SOURCE_DIR} SOURCE_DIRECTORY)

set(CMAKE_CXX_STANDARD 20)

add_definitions(
		-D__XM_PLATFORM_WINDOWS__                   # 编译平台为Windows
		-D__XM_IN_CHINA__							# 引擎语言为中文
		-D__XM_RENDERAPI_OPENGL__		   		    # 引擎渲染API使用OpenGL
)

link_libraries(imm32)
link_libraries(${CMAKE_SOURCE_DIR}/library/glfw3.dll)

add_executable( ${PROJECT_NAME}
		${SOURCE}
		${CMAKE_SOURCE_DIR}/dependencies/imgui/imgui.cpp
		${CMAKE_SOURCE_DIR}/dependencies/imgui/imgui_draw.cpp
		${CMAKE_SOURCE_DIR}/dependencies/imgui/imgui_demo.cpp
		${CMAKE_SOURCE_DIR}/dependencies/imgui/imgui_widgets.cpp
		${CMAKE_SOURCE_DIR}/dependencies/imgui/imgui_tables.cpp
		${CMAKE_SOURCE_DIR}/dependencies/imgui/backends/imgui_impl_glfw.cpp
		${CMAKE_SOURCE_DIR}/dependencies/imgui/backends/imgui_impl_opengl3.cpp
)

install(
	TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}
)


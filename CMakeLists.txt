cmake_minimum_required(VERSION 3.17)
project(zenith)

################################################
### for vendor dir.
################################################
include_directories(SYSTEM vendor/imgui)
include_directories(SYSTEM vendor/imgui/backends)

################################################
### for include dir.
#################################################
include_directories(SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${PROJECT_NAME} ${CMAKE_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/application)

################################################
### 配置源码目录 SOURCEALL_DIR
################################################
aux_source_directory(${CMAKE_SOURCE_DIR} SOURCE_DIRECTORY)

set(CMAKE_CXX_STANDARD 20)

add_definitions(
		-D__ZENITH_PLATFORM_WINDOWS__                   # 编译平台为Windows
		-D__ZENITH_IN_CHINA__							# 引擎语言为中文
		-D__ZENITH_RENDERAPI_OPENGL__		   		    # 引擎渲染API使用OpenGL
)

link_libraries(imm32)
link_libraries(${CMAKE_SOURCE_DIR}/library/glfw3.dll)

add_executable(
		${PROJECT_NAME} main.cpp glad.c
		### =================================================================================
		### application
		application/application.cpp
		application/native-window.cpp

		### =================================================================================
		### render
		render/graphics-context.cpp
		render/render-api.cpp
		render/renderer.cpp
		render/render-command.cpp

		### render/camera
		render/camera/ortho-graphics-camera.cpp
		render/camera/ortho-graphics-camera-controller.cpp

		### render/model
		render/model/buf.cpp
		render/model/opengl-veca.cpp
		render/model/opengl-buf.cpp

		### =================================================================================
		### platform
		platform/opengl/opengl-context.cpp
		platform/opengl/render-impl-opengl.cpp
		platform/windows/window.cpp

		${CMAKE_SOURCE_DIR}/vendor/imgui/imgui.cpp
		${CMAKE_SOURCE_DIR}/vendor/imgui/imgui_draw.cpp
		${CMAKE_SOURCE_DIR}/vendor/imgui/imgui_demo.cpp
		${CMAKE_SOURCE_DIR}/vendor/imgui/imgui_widgets.cpp
		${CMAKE_SOURCE_DIR}/vendor/imgui/imgui_tables.cpp
		${CMAKE_SOURCE_DIR}/vendor/imgui/backends/imgui_impl_glfw.cpp
		${CMAKE_SOURCE_DIR}/vendor/imgui/backends/imgui_impl_opengl3.cpp
)

install(
	TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}
)


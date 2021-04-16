cmake_minimum_required(VERSION 3.17)
project(zenith)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/zenith SOURCE)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/zenith/init SOURCE_INIT)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/zenith/window SOURCE_WIN)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/zenith/event SOURCE_EVENT)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/zenith/platform SOURCE_PLATFORM)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/zenith/platform/windows SOURCE_PLATFORM_WINDOWS)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/zenith/platform/opengl SOURCE_PLATFORM_OPENGL)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/zenith/render SOURCE_RENDER)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/zenith/tool SOURCE_TOOL)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/zenith/layer SOURCE_LAYER)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/zenith/render/texture SOURCE_TEXTURE)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/zenith/render/shader SOURCE_SHADER)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/zenith/models SOURCE_MODELS)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/zenith/scene/3d/camera SOURCE_SCENE_3D_CAMERA)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/zenith/render/2d/texture SOURCE_RENDER_2D_CAMERA)

################################################
### for modules dir.
################################################
include_directories(SYSTEM modules)
include_directories(SYSTEM modules/imgui)
include_directories(SYSTEM modules/imgui/backends)

################################################
### for include dir.
#################################################
include_directories(SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(SYSTEM include/api)

################################################
### for src dir.
#################################################
include_directories(zenith)

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
link_libraries(${CMAKE_CURRENT_SOURCE_DIR}/lib/glfw3.dll)

add_executable( ${PROJECT_NAME}
		${SOURCE}
		${SOURCE_INIT}
		${SOURCE_WIN}
		${SOURCE_EVENT}
		${SOURCE_PLATFORM}
		${SOURCE_PLATFORM_WINDOWS}
		${SOURCE_PLATFORM_OPENGL}
		${SOURCE_RENDER}
		${SOURCE_TOOL}
		${SOURCE_LAYER}
		${SOURCE_TEXTURE}
		${SOURCE_SHADER}
		${SOURCE_MODELS}
		${SOURCE_SCENE_3D_CAMERA}
		${SOURCE_RENDER_2D_CAMERA}
		${CMAKE_CURRENT_SOURCE_DIR}/modules/imgui/imgui.cpp
		${CMAKE_CURRENT_SOURCE_DIR}/modules/imgui/imgui_draw.cpp
		${CMAKE_CURRENT_SOURCE_DIR}/modules/imgui/imgui_demo.cpp
		${CMAKE_CURRENT_SOURCE_DIR}/modules/imgui/imgui_widgets.cpp
		${CMAKE_CURRENT_SOURCE_DIR}/modules/imgui/imgui_tables.cpp
		${CMAKE_CURRENT_SOURCE_DIR}/modules/imgui/backends/imgui_impl_glfw.cpp
		${CMAKE_CURRENT_SOURCE_DIR}/modules/imgui/backends/imgui_impl_opengl3.cpp
)

install(
	TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}
)

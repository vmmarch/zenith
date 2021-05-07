cmake_minimum_required(VERSION 3.17)
project(zenith)

# ---------------------------------------------
# 发布时需要将Release设置为ON
# ---------------------------------------------
set(DEBUG ON)

# ---------------------------------------------
# 开启例子测试
# ---------------------------------------------
set(EXAMPLE ON)

if(EXAMPLE MATCHES ON)
    add_subdirectory(example/line)
    add_subdirectory(example/grid)
endif()

add_subdirectory(fuckstd)

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
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/zenith/scene/3d/camera SOURCE_SCENE_3D_CAMERA)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/zenith/render/2d/texture SOURCE_RENDER_2D_CAMERA)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/zenith/buf SOURCE_BUF)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/zenith/sandbox SOURCE_SANDBOX)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/zenith/example SOURCE_EXAMPLE)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/zenith/load SOURCE_LOAD)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/zenith/japi SOURCE_JAPI)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/zenith/importer SOURCE_IMPORTER)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/zenith/importer/obj SOURCE_IMPORTER_OBJ)


include_directories(SYSTEM fuckstd)

# ---------------------------------------------------------------------------------------
# for modules dir.
# ---------------------------------------------------------------------------------------
include_directories(SYSTEM modules)
include_directories(SYSTEM modules/imgui)
include_directories(SYSTEM modules/imgui/backends)

# ---------------------------------------------------------------------------------------
# for include dir.
# ---------------------------------------------------------------------------------------
include_directories(SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(SYSTEM include/api)
include_directories(SYSTEM zenith/sys_include)

# ---------------------------------------------------------------------------------------
# for jvm dir.
# ---------------------------------------------------------------------------------------
include_directories(SYSTEM include/jvm/win64)

# ---------------------------------------------------------------------------------------
# for src dir.
# ---------------------------------------------------------------------------------------
include_directories(zenith)

# ---------------------------------------------------------------------------------------
# 配置源码目录 SOURCEALL_DIR
# ---------------------------------------------------------------------------------------
aux_source_directory(${CMAKE_SOURCE_DIR} SOURCE_DIRECTORY)

set(CMAKE_CXX_STANDARD 20)

add_definitions(
        -D__ZENITH_PLATFORM_WINDOWS__                   # 编译平台为Windows
        -D__ZENITH_IN_CHINA__                           # 引擎语言为中文
        -D__ZENITH_RENDERAPI_OPENGL__                   # 引擎渲染API使用OpenGL
        -DZENITH_GLAD_CORE                              # GLAD使用Core版本
)

if(DEBUG MATCHES ON)
    add_definitions(-D__DEBUG__) # 开启DEBUG
endif()

link_libraries(imm32)
link_libraries(${CMAKE_CURRENT_SOURCE_DIR}/bin/glfw3.dll)

add_executable(${PROJECT_NAME}
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
        ${SOURCE_SCENE_3D_CAMERA}
        ${SOURCE_RENDER_2D_CAMERA}
        ${SOURCE_BUF}
        ${SOURCE_SANDBOX}
        ${SOURCE_EXAMPLE}
        ${SOURCE_LOAD}
        ${SOURCE_JAPI}
        ${LOADER_JVM_CALL}

        ${SOURCE_IMPORTER} ${SOURCE_IMPORTER_OBJ}

        # ------------------------------------------------------
        # GLAD
        # ------------------------------------------------------
        ${CMAKE_CURRENT_SOURCE_DIR}/extern/GLAD/glad.c

        # ------------------------------------------------------
        # IMGUI
        # ------------------------------------------------------
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

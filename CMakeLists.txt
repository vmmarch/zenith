# ----------------------------------------------------------------------
#
# Copyright (C) 2020 dahan All rights reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# ----------------------------------------------------------------------

# ===> Creates on 2021/4/6. <===

#
# @author 2B键盘
#
CMAKE_MINIMUM_REQUIRED(VERSION 3.17)
PROJECT(zenith)

SET(CMAKE_CXX_STANDARD 14)

# ---------------------------------------------
# 发布时需要将Release设置为ON
# ---------------------------------------------
SET(DEBUG ON)

# ---------------------------------------------
# 设置编译平台
# WINDOWS/MACOS
# ---------------------------------------------
SET(PLATFORM WINDOWS)

# ---------------------------------------------
# 开启例子测试
# ---------------------------------------------
SET(EXAMPLE ON)

IF(EXAMPLE MATCHES ON)
    ADD_SUBDIRECTORY(example/line)
    ADD_SUBDIRECTORY(example/grid)
    ADD_SUBDIRECTORY(example/std)
ENDIF()

ADD_SUBDIRECTORY(tool)
ADD_SUBDIRECTORY(guiapi)

AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/zenith SOURCE)
AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/zenith/init SOURCE_INIT)
AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/zenith/window SOURCE_WIN)
AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/zenith/event SOURCE_EVENT)
AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/zenith/platform SOURCE_PLATFORM)
AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/zenith/platform/windows SOURCE_PLATFORM_WINDOWS)
AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/zenith/platform/opengl SOURCE_PLATFORM_OPENGL)
AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/zenith/render SOURCE_RENDER)
AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/zenith/tool SOURCE_TOOL)
AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/zenith/layer SOURCE_LAYER)
AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/zenith/render/texture SOURCE_TEXTURE)
AUX_SOURCE_DIRECTORY(zenith/shader SOURCE_SHADER)
AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/zenith/scene/3d/camera SOURCE_SCENE_3D_CAMERA)
AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/zenith/render/2d/texture SOURCE_RENDER_2D_CAMERA)
AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/zenith/buf SOURCE_BUF)
AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/zenith/sandbox SOURCE_SANDBOX)
AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/zenith/example SOURCE_EXAMPLE)
AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/zenith/load SOURCE_LOAD)
AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/zenith/japi SOURCE_JAPI)

AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/zenith/importer SOURCE_IMPORTER)
AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/zenith/importer/obj SOURCE_IMPORTER_OBJ)

AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/zenith/model SOURCE_MODEL)

INCLUDE_DIRECTORIES(SYSTEM tool)

# ---------------------------------------------------------------------------------------
# for modules dir.
# ---------------------------------------------------------------------------------------
INCLUDE_DIRECTORIES(SYSTEM modules)
INCLUDE_DIRECTORIES(SYSTEM modules/imgui)
INCLUDE_DIRECTORIES(SYSTEM modules/imgui/backends)

# ---------------------------------------------------------------------------------------
# for include dir.
# ---------------------------------------------------------------------------------------
INCLUDE_DIRECTORIES(SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}/include)
INCLUDE_DIRECTORIES(SYSTEM include/api)
INCLUDE_DIRECTORIES(SYSTEM zenith/sys_include)

# ---------------------------------------------------------------------------------------
# for jvm dir.
# ---------------------------------------------------------------------------------------
INCLUDE_DIRECTORIES(SYSTEM include/jvm/win64)

# ---------------------------------------------------------------------------------------
# for src dir.
# ---------------------------------------------------------------------------------------
INCLUDE_DIRECTORIES(zenith)

# ---------------------------------------------------------------------------------------
# 配置源码目录 SOURCEALL_DIR
# ---------------------------------------------------------------------------------------
AUX_SOURCE_DIRECTORY(${CMAKE_SOURCE_DIR} SOURCE_DIRECTORY)

SET(CMAKE_CXX_STANDARD 20)

# ---------------------------------------------------------------------------------------
# 配置编译平台
# ---------------------------------------------------------------------------------------
IF(PLATFORM MATCHES WINDOWS)
    ADD_DEFINITIONS(-D__ZENITH_PLATFORM_WINDOWS__)
ELSE(PLATFORM MATCHES MACOS)
    ADD_DEFINITIONS(-D__ZENITH_PLATFORM_MACOS__)
ENDIF()

ADD_DEFINITIONS(
        -D__ZENITH_IN_CHINA__                           # 引擎语言为中文
        -D__ZENITH_RENDERAPI_OPENGL__                   # 引擎渲染API使用OpenGL
        -DZENITH_GLAD_CORE                              # GLAD使用Core版本
)

IF(DEBUG MATCHES ON)
    ADD_DEFINITIONS(-D__DEBUG__) # 开启DEBUG
ENDIF()

IF(PLATFORM MATCHES WINDOWS)
    LINK_LIBRARIES(imm32)
    LINK_LIBRARIES(${CMAKE_CURRENT_SOURCE_DIR}/bin/glfw3.dll)
ELSE(PLATFORM MATCHES MACOS)
    LINK_LIBRARIES(${CMAKE_CURRENT_SOURCE_DIR}/bin/libglfw.3.dylib)
ENDIF()

IF(PLATFORM MATCHES WINDOWS)
    SET(IMAGE_BACKENDS_1 ${CMAKE_CURRENT_SOURCE_DIR}/modules/imgui/backends/imgui_impl_glfw.cpp)
    SET(IMAGE_BACKENDS_2 ${CMAKE_CURRENT_SOURCE_DIR}/modules/imgui/backends/imgui_impl_opengl3.cpp)
ELSE(PLATFORM MATCHES MACOS)
    SET(IMAGE_BACKENDS_1 ${CMAKE_CURRENT_SOURCE_DIR}/modules/imgui/backends/imgui_impl_glfw.cpp)
    SET(IMAGE_BACKENDS_2 ${CMAKE_CURRENT_SOURCE_DIR}/modules/imgui/backends/imgui_impl_opengl3.cpp)
ENDIF()

ADD_EXECUTABLE(${PROJECT_NAME}
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

        ${SOURCE_MODEL}

        # ------------------------------------------------------
        # C
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

        # backends
        ${IMAGE_BACKENDS_1}
        ${IMAGE_BACKENDS_2}
)

INSTALL(
        TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}
)

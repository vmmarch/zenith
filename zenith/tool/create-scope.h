/*! ************************************************************************
 *
 * Copyright (C) 2020 dahan All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *! ************************************************************************/

/*! ===> Creates on 2021/4/8. <=== */

/*!
 * @author 2B键盘
 */
#pragma once

#include "platform/opengl/opengl-texture2D.h"
#include "platform/opengl/opengl-camera.h"
#include "platform/opengl/opengl-shader.h"
#include "platform/windows/window.h"
#include "platform/opengl/opengl-renderer.h"
#include "platform/opengl/opengl-graphics-context.h"
#include "platform/opengl/opengl-vertex-buf.h"
#include "platform/opengl/opengl-index-buf.h"

/**
 * @return 窗口实例
 */
static v_scope<zenith::Window> __create_window(const zenith::v_winprops &props)
{
#ifdef __ZENITH_PLATFORM_WINDOWS__
    return zenith::__create_scope<zenith::win::WinWindow>(props);
#else
    ZENITH_ERROR(__ONLY_SUPPORT_WINDOWS__); return nullptr;
#endif
}

/**
 * @return 图形上下文
 */
static v_scope<zenith::GraphicsContext> __create_graphics_context(v_any window)
{
    switch (zenith::Renderer::__render_api())
    {
        case render::NONE:
            break;
        case render::GL:
            return zenith::__create_scope<zenith::OpenGLGraphicsContext>(static_cast<GLFWwindow *>(window));
        case render::DX:
            break;
    }

    return nullptr;
}

/**
 * @return 渲染器
 */
static v_scope<zenith::Renderer> __create_renderer()
{
    switch (zenith::Renderer::__render_api())
    {
        case render::NONE:
            break;
        case render::GL:
            return zenith::__create_scope<zenith::OpenGLRenderer>();
        case render::DX:
            break;
    }

    return nullptr;
}

/**
 * @return 着色器实例
 */
static v_scope<zenith::Shader> __create_shader(v_cc path, v_cc debugname)
{
    switch (zenith::Renderer::__render_api())
    {
        case render::NONE:
            break;
        case render::GL:
            return zenith::__create_scope<zenith::OpenGLShader>(path, debugname);
        case render::DX:
            break;
    }

    return nullptr;
}

/**
 * @return 相机
 */
static v_scope<zenith::Camera> __create_camera(glm::vec3 pos, glm::vec3 upvec, glm::vec3 target)
{
    switch (zenith::Renderer::__render_api())
    {
        case render::NONE:
            break;
        case render::GL:
            return zenith::__create_scope<zenith::OpenGLCamera>(pos, upvec, target);
        case render::DX:
            break;
    }

    return nullptr;
}

/**
 * @return 纹理
 */
static v_scope<zenith::Texture2D> __create_texture2D()
{
    switch (zenith::Renderer::__render_api())
    {
        case render::NONE:
            break;
        case render::GL:
            return zenith::__create_scope<zenith::OpenGLTexture2D>();
        case render::DX:
            break;
    }

    return nullptr;
}


/**
 * @return vertex buffer
 */
static zenith::VertexBuf* __create_vertex_buf(float *buf, v_ui32 size)
{
    switch (zenith::Renderer::__render_api())
    {
        case render::NONE:
            break;
        case render::GL:
            if(buf != NULL)
                return new zenith::OpenGLVertexBuf(buf, size);
            else
                return new zenith::OpenGLVertexBuf(size);
        case render::DX:
            break;
    }

    return nullptr;
}

/**
 * @return index buffer
 */
static zenith::IndexBuf* __create_index_buf(v_ui32 *buf, v_ui32 size)
{
    switch (zenith::Renderer::__render_api())
    {
        case render::NONE:
            break;
        case render::GL:
                return new zenith::OpenGLIndexBuf(buf, size);
        case render::DX:
            break;
    }

    return nullptr;
}
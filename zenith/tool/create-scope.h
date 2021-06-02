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
#include "platform/opengl/opengl-shader.h"
#include "platform/windows/window.h"
#include "platform/opengl/opengl-renderer.h"
#include "platform/opengl/opengl-graphics-context.h"

/**
 * @return 窗口实例
 */
static zenith_scope<zenith::Window> create_window(const zenith::v_winprops &props)
{
#if (defined __ZENITH_PLATFORM_WINDOWS__) || (defined __ZENITH_PLATFORM_MACOS__)
    return zenith::create_scope<zenith::win::WinWindow>(props);
#else
    ZENITH_ERROR("NOT SUPPORT CURRENT PLATFORM"); return nullptr;
#endif
}

/**
 * @return 图形上下文
 */
static zenith::GraphicsContext* create_graphics_context(zenith_any window)
{
    switch (zenith::AbstractRenderer::GetRenderAPI())
    {
        case zenith::render::api::NONE:
            break;
        case zenith::render::api::GL:
            return new zenith::OpenGLGraphicsContext(static_cast<GLFWwindow *>(window));
        case zenith::render::api::DX:
            break;
    }

    return nullptr;
}

/**
 * @return 渲染器
 */
static zenith_scope<zenith::AbstractRenderer> create_renderer()
{
    switch (zenith::AbstractRenderer::GetRenderAPI())
    {
        case zenith::render::api::NONE:
            break;
        case zenith::render::api::GL:
            return zenith::create_scope<zenith::OpenGLRenderer>();
        case zenith::render::api::DX:
            break;
    }

    return nullptr;
}

/**
 * @return 着色器实例
 */
static zenith::ShaderProgram* create_shader_program(zenith_char path, zenith_char debugname)
{
    switch (zenith::AbstractRenderer::GetRenderAPI())
    {
        case zenith::render::api::NONE:
            break;
        case zenith::render::api::GL:
            return new zenith::OpenGLShaderProgram(path, debugname);
        case zenith::render::api::DX:
            break;
    }

    return nullptr;
}

/**
 * @return 纹理
 */
static zenith_scope<zenith::Texture2D> create_texture2D()
{
    switch (zenith::AbstractRenderer::GetRenderAPI())
    {
        case zenith::render::api::NONE:
            break;
        case zenith::render::api::GL:
            return zenith::create_scope<zenith::OpenGLTexture2D>();
        case zenith::render::api::DX:
            break;
    }

    return nullptr;
}
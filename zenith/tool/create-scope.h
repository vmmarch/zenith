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

#include "platform/opengl/opengl-shader.h"
#include "platform/windows/window.h"
#include "platform/opengl/opengl-renderer.h"
#include "platform/opengl/opengl-graphics-context.h"

/**
 * @return 窗口实例
 */
static zenith_scope<Window> create_window(const v_winprops &props)
{
#if (defined __ZENITH_PLATFORM_WINDOWS__) || (defined __ZENITH_PLATFORM_MACOS__)
    return create_scope<WinWindow>(props);
#else
    ZENITH_ERROR("NOT SUPPORT CURRENT PLATFORM"); return nullptr;
#endif
}

/**
 * @return 图形上下文
 */
static GraphicsContext* create_graphics_context(zenith_any window)
{
    switch (AbstractRenderer::GetRenderAPI())
    {
        case render::api::NONE:
            break;
        case render::api::GL:
            return new OpenGLGraphicsContext(static_cast<GLFWwindow *>(window));
        case render::api::DX:
            break;
    }

    return nullptr;
}

/**
 * @return 渲染器
 */
static zenith_scope<AbstractRenderer> create_renderer()
{
    switch (AbstractRenderer::GetRenderAPI())
    {
        case render::api::NONE:
            break;
        case render::api::GL:
            return create_scope<OpenGLRenderer>();
        case render::api::DX:
            break;
    }

    return nullptr;
}

/**
 * @return 着色器实例
 */
static Shader* create_shader_shader(zenith_char path, zenith_char debugname)
{
    switch (AbstractRenderer::GetRenderAPI())
    {
        case render::api::NONE:
            break;
        case render::api::GL:
            return new OpenGLShader(path, debugname);
        case render::api::DX:
            break;
    }

    return nullptr;
}
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

/**
 * @return 窗口实例
 */
static v_scope<alkaid::Window> __create_window(const alkaid::v_winprops &props)
{
#ifdef __ALKAID_PLATFORM_WINDOWS__
    return __create_scope<alkaid::win::WinWindow>(props);
#else
    __ALKAID_ERROR(__ONLY_SUPPORT_WINDOWS__); return nullptr;
#endif
}

/**
 * @return 图形上下文
 */
static v_scope<alkaid::GraphicsContext> __create_graphics_context(v_any window)
{
    switch (alkaid::Renderer::__get_render_api())
    {
        case render::NONE:
            break;
        case render::GL:
            return __create_scope<alkaid::OpenGLGraphicsContext>(static_cast<GLFWwindow*>(window));
        case render::DX:
            break;
    }

    return nullptr;
}

/**
 * @return 渲染器
 */
static v_scope<alkaid::Renderer> __create_renderer()
{
    switch (alkaid::Renderer::__get_render_api())
    {
        case render::NONE:
            break;
        case render::GL: return __create_scope<alkaid::OpenGLRenderer>();
        case render::DX:
            break;
    }

    return nullptr;
}

/**
 * @return 着色器实例
 */
static v_scope<alkaid::Shader> __create_shader(v_cc vertex_path, v_cc fragment_path)
{
    switch (alkaid::Renderer::__get_render_api())
    {
        case render::NONE:
            break;
        case render::GL: return __create_scope<alkaid::OpenGLShader>(vertex_path, fragment_path);
        case render::DX:
            break;
    }

    return nullptr;
}

/**
 * @return 相机
 */
static v_scope<Camera> __create_camera(glm::vec3 pos, glm::vec3 upvec, glm::vec3 target)
{
	switch(alkaid::Renderer::__get_render_api())
	{
		case render::NONE: break;
		case render::GL: return __create_scope<OpenGLCamera>(pos, upvec, target);
		case render::DX: break;
	}
}

/**
 * @return 纹理
 */
static v_scope<Texture2D> __create_texture2D()
{
	switch(alkaid::Renderer::__get_render_api())
	{
		case render::NONE: break;
		case render::GL: return __create_scope<OpenGLTexture2D>();
		case render::DX: break;
	}
}

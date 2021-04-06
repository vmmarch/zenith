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

/*! ===> Creates on 2021/4/6. <=== */

/*!
 * @author 2B键盘
 */
#include "shader.h"
#include "platform/opengl/opengl-shader.h"
#include "render/render-api.h"
#include <zenith/globalization.h>

namespace zenith
{
    Ref<Shader> Shader::Create(v_cc filepath)
    {
        switch (RenderAPI::GetAPI())
        {
            case RenderAPI::API::None:
            {
                __ZENITH_ERROR__(__PLEASE_CHOOSE_RENDER_API__)
                return nullptr;
            }

            case RenderAPI::API::OpenGL:
            {
                return CreateRef<OpenGLShader>(filepath);
            }

            case RenderAPI::API::DirectX:
            {
                __ZENITH_ERROR__(__NOT_SUPPORT_DIRECTX_API__)
                return nullptr;
            }
        }

        return nullptr;
    }

    Ref<Shader> Shader::Create(v_cc name, v_cc vec_f, v_cc frgm_f)
    {
        switch (RenderAPI::GetAPI())
        {
            case RenderAPI::API::None:
            {
                __ZENITH_ERROR__(__PLEASE_CHOOSE_RENDER_API__)
                return nullptr;
            }

            case RenderAPI::API::OpenGL:
            {
                return CreateRef<OpenGLShader>(name, vec_f, frgm_f);
            }

            case RenderAPI::API::DirectX:
            {
                __ZENITH_ERROR__(__NOT_SUPPORT_DIRECTX_API__)
                return nullptr;
            }
        }

        return nullptr;
    }
}
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

/*! ===> Creates on 2021/4/4. <=== */

/*!
 * @author orvals
 */
#include "render-api.h"

#ifdef __ZENITH_RENDERAPI_OPENGL__

#include "platform/opengl/render-impl-opengl.h"

#endif

namespace zenith
{
    RenderAPI::API RenderAPI::s_API = RenderAPI::API::OpenGL;

    v_scope<RenderAPI> RenderAPI::Create()
    {
        switch (GetAPI())
        {
            case API::None:
            {
                __ZENITH_ERROR__(__PLEASE_CHOOSE_RENDER_API__)
                return nullptr;
            }
            case API::OpenGL:
            {
                return CreateScope<OpenGLRenderAPI>();
            }
            case API::DirectX:
            {
                __ZENITH_ERROR__(__NOT_SUPPORT_DIRECTX_API__)
                return nullptr;
            }
        }

        return nullptr;
    }
}
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

/*! ===> Creates on 2021/4/7. <=== */

/*!
 * @author 2B键盘
 */
#include "renderer.h"
#include "platform/opengl/opengl-renderer.h"

namespace alkaid
{

#ifdef __GLAPI
    render::api Renderer::render_api = render::api::GL;
#elif __DXAPI
    #error ##__NOT_SUPPORT_DIRECTX_API__
#else
    #error ##__PLEASE_CHOOSE_RENDER_API__
#endif

    render::api Renderer::__get_render_api()
    {
        return render_api;
    }

    v_scope<Renderer> Renderer::__create()
    {
        switch (Renderer::render_api)
        {
            case render::NONE:
                break;
            case render::GL: __create_scope<OpenGLRenderer>();
            case render::DX:
                break;
        }

        return nullptr;
    }

}
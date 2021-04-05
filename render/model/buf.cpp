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

/*! ===> Creates on 2021/4/5. <=== */

/*!
 * @author 2B键盘
 */
#include "buf.h"
#include "render/renderer.h"
#include <zenith/globalization.h>
#include "render/model/opengl-buf.h"

namespace zenith::buf
{
    Ref<VertexBuffer> VertexBuffer::Create(v_uint32t size)
    {
        return Create(nullptr, size);
    }

    Ref<VertexBuffer> VertexBuffer::Create(float *vertices, v_uint32t size)
    {
        switch(Renderer::GetAPI())
        {
            case RenderAPI::API::None: __ZENITH_ERROR__(__PLEASE_CHOOSE_RENDER_API__) break;
            case RenderAPI::API::OpenGL:
            {
                if(vertices == nullptr)
                    return CreateScope<OpenGLVecBuf>(size);
                else
                    return CreateScope<OpenGLVecBuf>(vertices, size);
            }
            case RenderAPI::API::DirectX: __ZENITH_ERROR__(__NOT_SUPPORT_DIRECTX_API__) break;
        }

        return nullptr;
    }

}
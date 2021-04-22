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

/*! ===> Creates on 2021/4/20. <=== */

/*!
 * @author 2B键盘
 */
#include "opengl-vertex-buf.h"
#include "api/glfw-api.h"

namespace zenith
{
    OpenGLVertexBuffer::OpenGLVertexBuffer(v_ui32 size)
    {
        GLAPI_CreateDynamicVertexBufferAndBind(render_id, size);
    }

    OpenGLVertexBuffer::OpenGLVertexBuffer(float *buf, v_ui32 size)
    {
        GLAPI_CreateStaticVertexBufferAndBind(render_id, buf, size);
    }

    OpenGLVertexBuffer::~OpenGLVertexBuffer()
    {
        GLAPI_DeleteBuffer(render_id);
    }

    void OpenGLVertexBuffer::bind()
    {
        GLAPI_BindArrayBuffer(render_id);
    }

    void OpenGLVertexBuffer::unbind()
    {
        GLAPI_UnbindArrayBuffer();
    }

    void OpenGLVertexBuffer::__data(float *buf, v_ui32 size)
    {
        GLAPI_BindArrayBuffer(render_id);
        glBufferSubData(GL_ARRAY_BUFFER, 0, size, buf);
    }

}
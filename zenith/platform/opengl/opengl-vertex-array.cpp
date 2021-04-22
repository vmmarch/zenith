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

/*! ===> Creates on 2021/4/21. <=== */

/*!
 * @author 2B键盘
 */
#include "opengl-vertex-array.h"
#include <api/glfw-api.h>

namespace zenith
{

    OpenGLVertexArray::OpenGLVertexArray()
    {
        GLAPI_CreateVertexArray(array_id);
    }

    OpenGLVertexArray::~OpenGLVertexArray()
    {
        GLAPI_DeleteVertexArray(array_id);
    }

    void OpenGLVertexArray::bind() const
    {
        GLAPI_BindVertexArray(array_id);
    }

    void OpenGLVertexArray::unbind() const
    {
        GLAPI_UnbindVertexArray();
    }

    void OpenGLVertexArray::add_vertex_buf(std::shared_ptr<VertexBuffer> &buf)
    {
        GLAPI_BindVertexArray(array_id);
        buf->bind();

        if(buf->__layout().__elements().size() == 0)
            ZENITH_ERROR(VERTEX_BUFFER_HAS_NOT_LAYOUT);

        v_ui32 index = 0;
        const auto& layout = buf->__layout();
        for(const auto& element : layout)
        {
            glEnableVertexAttribArray(index);
            glVertexAttribPointer(index, element.__size(), element.__type(),
                                  element.normalized ? GL_TRUE : GL_FALSE,
                                  buf->__layout().__stride(),
                                  (const void*) element.offset);
            index++;
        }

        vertex_buffers.push_back(buf);
    }

    void OpenGLVertexArray::__index_buffer(v_ui32* buf, v_ui32 size)
    {
        std::shared_ptr<IndexBuffer> index_buf;
        index_buf.reset(IndexBuffer::__create(buf, size));

        __index_buffer(index_buf);
    }

    void OpenGLVertexArray::__index_buffer(std::shared_ptr<IndexBuffer> &buf)
    {
        GLAPI_BindVertexArray(array_id);
        buf->bind();

        this->index_buf = buf;
    }
}
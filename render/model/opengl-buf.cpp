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
#pragma once
#include "opengl-buf.h"
#include "api/opengl/glfw-api.h"

namespace zenith::buf
{

    // =============================================================================
    // OpenGLVecBuf
    OpenGLVecBuf::OpenGLVecBuf(v_uint32t size)
    {
        __glCreateArrayBuffer__(rendererId, size, nullptr, GL_DYNAMIC_DRAW);
    }

    OpenGLVecBuf::OpenGLVecBuf(float *vertices, uint32_t size)
    {
        __glCreateArrayBuffer__(rendererId, size, vertices, GL_STATIC_DRAW);
    }

    OpenGLVecBuf::~OpenGLVecBuf() noexcept
    {
        glDeleteBuffers(1, &rendererId);
    }

    void OpenGLVecBuf::Bind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, rendererId);
    }

    void OpenGLVecBuf::UnBind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void OpenGLVecBuf::SetData(const void *data, uint32_t size)
    {
        glBindBuffer(GL_ARRAY_BUFFER, rendererId);
        glBufferSubData(GL_ARRAY_BUFFER, 0, size, data);
    }

    const BufferLayout &OpenGLVecBuf::GetLayout() const
    { return layout; }

    void OpenGLVecBuf::SetLayout(const BufferLayout &__count)
    { layout = __count; }

    // =============================================================================
    // OpenGLIndexBuf
    OpenGLIndexBuf::OpenGLIndexBuf(v_uint32t *indices, v_uint32t __count) : count(__count)
    {
        __glCreateArrayBuffer__(rendererId, count * sizeof(v_uint32t), indices, GL_STATIC_DRAW);
    }

    OpenGLIndexBuf::~OpenGLIndexBuf()
    {
        __glDeleteBuffer__(rendererId);
    }

    void OpenGLIndexBuf::Bind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, rendererId);
    }

}
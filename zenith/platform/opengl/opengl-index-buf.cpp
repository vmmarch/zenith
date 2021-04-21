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
#include "opengl-index-buf.h"
#include <api/glfw-api.h>

namespace zenith
{
    OpenGLIndexBuf::OpenGLIndexBuf(v_ui32* indices, v_ui32 size)
        : v_size(size)
    {
        GLAPI_CreateAndBindIndexArrayBuffer(index_id);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, size * sizeof(v_ui32), indices, GL_STATIC_DRAW);
    }

    OpenGLIndexBuf::~OpenGLIndexBuf()
    {
        GLAPI_DeleteBuffer(index_id);
    }

    void OpenGLIndexBuf::bind()
    {
        GLAPI_BindIndexArrayBuffer(index_id);
    }

    void OpenGLIndexBuf::unbind()
    {
        GLAPI_UnbindIndexArrayBuffer();
    }

    v_ui32 OpenGLIndexBuf::size() const
    {
        return v_size;
    }

}
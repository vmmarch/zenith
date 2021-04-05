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
#include "buf.h"

namespace zenith::buf
{
    class OpenGLVecBuf : public VertexBuffer
    {
    public:
        explicit OpenGLVecBuf(v_uint32t size);
        OpenGLVecBuf(float* vertices, uint32_t size);
        ~OpenGLVecBuf() override;

        virtual void Bind() const override;
        virtual void UnBind() const override;

        virtual void SetData(const void* data, uint32_t size) override;

        virtual const BufferLayout& GetLayout() const override;
        virtual void SetLayout(const BufferLayout& __count) override;
    private:
        v_uint32t rendererId;
        BufferLayout layout;
    };

    class OpenGLIndexBuf : public IndexBuffer
    {
    public:
        OpenGLIndexBuf(v_uint32t* indices, v_uint32t count);
        virtual ~OpenGLIndexBuf();

        virtual void Bind() const;
        virtual void Unbind() const;

        virtual uint32_t GetCount() const { return count; }
    private:
        uint32_t rendererId;
        uint32_t count;
    };
};
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
#pragma once

#include "buf.h"

namespace zenith
{

    enum DrawMode
    {
        ARRAY, INDEX
    };

    enum DrawType
    {
        DEFAULT, LINE
    };

    class VertexArray
    {
    public:
        virtual ~VertexArray() = default;
        virtual void bind() const = 0;
        virtual void unbind() const = 0;

        virtual void AddVertexBuffer(float *buf, zenith_uint32 size) = 0;
        virtual void AddVertexBuffer(VertexBuffer* vbuf) = 0;
        virtual void SetIndexBuffer(zenith_uint32* buf, zenith_uint32 size) = 0;
        virtual void SetIndexBuffer(IndexBuffer* ibuf) = 0;
        virtual IndexBuffer* GetIndexBuffer() const = 0;
        virtual DrawMode GetMod() const = 0;
        virtual void SetType(DrawType) = 0;
        virtual DrawType GetType() const = 0;
        virtual std::vector<VertexBuffer*> GetVertexBuffers() const = 0;

        static VertexArray* Create();
    };
}
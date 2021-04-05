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
#include <memory>

namespace zenith::vec
{
    class VertexArray
    {
    public:
        virtual ~VertexArray() = default;

        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;

        virtual void AddVertexBuffer(const Ref<buf::VertexBuffer>& vertexBuffers) = 0;
        virtual void SetIndexBuffer(const Ref<buf::IndexBuffer>& indexBuffer) = 0;

        virtual const std::vector<Ref<buf::VertexBuffer>>& GetVertexBuffers() const = 0;
        virtual const Ref<buf::IndexBuffer>& GetIndexBuffer() const = 0;

        static Ref<VertexArray> Create();
    };
}
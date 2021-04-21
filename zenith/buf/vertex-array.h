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
    class VertexArray
    {
    public:
        virtual ~VertexArray();
        virtual void bind() const = 0;
        virtual void unbind() const = 0;

        virtual void add_vertex_buf(std::shared_ptr<VertexBuffer>& vbuf) = 0;
        virtual void __index_buffer(std::shared_ptr<IndexBuffer>& ibuf) = 0;
        virtual std::shared_ptr<IndexBuffer> __index_buffer() const = 0;

        virtual std::vector<std::shared_ptr<VertexBuffer>> __vertex_buffers() const = 0;

        static VertexArray* __create();
    };
}
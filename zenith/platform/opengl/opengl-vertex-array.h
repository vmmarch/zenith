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

#include "buf/vertex-array.h"
#include <memory>

namespace zenith
{
    class OpenGLVertexArray : public VertexArray
    {
    public:
        OpenGLVertexArray();
        ~OpenGLVertexArray();

        /**
         * 绑定Array
         */
        void bind() const override;

        /**
         * 解绑Array
         */
        void unbind() const override;

        /**
         * 添加顶点缓冲对象
         */
        void AddVertexBuffer(float *buf, zenith_ui32 size) override;
        void AddVertexBuffer(VertexBuffer*) override;
        void SetIndexBuffer(zenith_ui32* buf, zenith_ui32 size) override;
        void SetIndexBuffer(IndexBuffer*) override;
        DrawMode GetMod() const override { return mod; }
        IndexBuffer* GetIndexBuffer() const override { return index_buf; }
        std::vector<VertexBuffer*> GetVertexBuffers() const override { return vertex_buffers; };

    private:
        zenith_ui32 array_id;
        DrawMode mod = DrawMode::ARRAY;
        std::vector<VertexBuffer*> vertex_buffers;
        IndexBuffer* index_buf;
    };
}
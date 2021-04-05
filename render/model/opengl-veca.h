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
#include "vec.h"

namespace zenith
{
    class OpenGLVeca : public vec::VertexArray
    {
    public:
        OpenGLVeca();
        virtual ~OpenGLVeca();

        void Bind() const override;
        void Unbind() const override;

        void AddVertexBuffer(const Ref<buf::VertexBuffer>& vertexBuffers) override;
        virtual void SetIndexBuffer(const Ref<buf::IndexBuffer>& indexBuffer) override;

        virtual const std::vector<Ref<buf::VertexBuffer>>& GetVertexBuffers() const;
        virtual const Ref<buf::IndexBuffer>& GetIndexBuffer() const { return m_IndexBuffer; }

    private:
        v_uint32t rendererId;
        v_uint32t m_VertexBufferIndex = 0;
        std::vector<Ref<buf::VertexBuffer>> m_VertexBuffers;
        Ref<buf::IndexBuffer> m_IndexBuffer;
    };
}
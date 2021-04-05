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
#include <zenith.h>
#include <vector>

namespace zenith
{

    enum class ShaderType
    {
        None = 0,
        FLOAT,
        FLOAT2,
        FLOAT3,
        FLOAT4,

        MAT3,
        MAT4,

        INT,
        INT2,
        INT3,
        INT4,

        BOOL
    };

    static v_uint32t ShaderTypeSize(ShaderType type)
    {
        switch (type)
        {
            case ShaderType::FLOAT:         return 4;
            case ShaderType::FLOAT2         return 4 * 2;
            case ShaderType::FLOAT3         return 4 * 3;
            case ShaderType::FLOAT4         return 4 * 4;

            case ShaderType::MAT3           return 4 * 3 * 3;
            case ShaderType::MAT4           return 4 * 4 * 4;

            case ShaderType::INT             return 4;
            case ShaderType::INT2            return 4 * 2;
            case ShaderType::INT3            return 4 * 3;
            case ShaderType::INT4            return 4 * 4;

            case ShaderType::BOOL           return 1;
        }

        return 0;
    }

    namespace buf
    {
        class BufferLayout
        {

        };

        // Currently Hazel only supports 32-bit index buffers
        class IndexBuffer
        {
        public:
            virtual ~IndexBuffer() = default;

            virtual void Bind() const = 0;
            virtual void Unbind() const = 0;

            virtual uint32_t GetCount() const = 0;

            static Ref<IndexBuffer> Create(uint32_t* indices, uint32_t count);
        };

        class VertexBuffer
        {
        public:
            virtual ~VertexBuffer() = default;

            virtual void Bind() const = 0;
            virtual void UnBind() const = 0;

            virtual void SetData(const void* data, v_uint32t size) = 0;
            virtual const BufferLayout& GetLayout() const = 0;
            virtual void SetLayout(const BufferLayout& layout) = 0;

            static Ref<VertexBuffer> Create(v_uint32t size);
            static Ref<VertexBuffer> Create(float* vertices, v_uint32t size);
        };
    }
}
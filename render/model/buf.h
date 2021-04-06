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
            case ShaderType::FLOAT2:        return 4 * 2;
            case ShaderType::FLOAT3:        return 4 * 3;
            case ShaderType::FLOAT4:        return 4 * 4;

            case ShaderType::MAT3:          return 4 * 3 * 3;
            case ShaderType::MAT4:          return 4 * 4 * 4;

            case ShaderType::INT:           return 4;
            case ShaderType::INT2:          return 4 * 2;
            case ShaderType::INT3:          return 4 * 3;
            case ShaderType::INT4:          return 4 * 4;

            case ShaderType::BOOL:          return 1;

            case ShaderType::None:          break;
        }

        return 0;
    }

    namespace buf
    {

        struct BufferElement
        {
            v_cc name;
            ShaderType type;
            v_uint32t size;
            size_t offset;
            bool normalized;

            BufferElement() = default;

            BufferElement(ShaderType __type, v_cc __name, bool __normalized = false)
                    : name(__name), type(__type), size(ShaderTypeSize(__type)), offset(0), normalized(__normalized)
            {
            }

            uint32_t GetComponentCount() const
            {
                switch (type)
                {
                    case ShaderType::FLOAT:   return 1;
                    case ShaderType::FLOAT2:  return 2;
                    case ShaderType::FLOAT3:  return 3;
                    case ShaderType::FLOAT4:  return 4;
                    case ShaderType::MAT3:    return 3; // 3* float3
                    case ShaderType::MAT4:    return 4; // 4* float4
                    case ShaderType::INT:     return 1;
                    case ShaderType::INT2:    return 2;
                    case ShaderType::INT3:    return 3;
                    case ShaderType::INT4:    return 4;
                    case ShaderType::BOOL:    return 1;
                    case ShaderType::None:    break;
                }

                return 0;
            }
        };

        class BufferLayout
        {
        public:
            BufferLayout() {}
            BufferLayout(std::initializer_list<BufferElement> __elements) : elements(__elements)
            {
                CalculateOffsetAndStride();
            }

            const v_uint32t GetStride() const { return stride; }
            const std::vector<BufferElement>& GetElements() const { return elements; }

            std::vector<BufferElement>::iterator begin() { return elements.begin(); }
            std::vector<BufferElement>::iterator end()   { return elements.end();   }

            std::vector<BufferElement>::const_iterator begin() const { return elements.begin(); }
            std::vector<BufferElement>::const_iterator end() const   { return elements.end();   }

        private:
            v_uint32t stride;
            std::vector<BufferElement> elements;
            void CalculateOffsetAndStride()
            {
                size_t offset = 0;
                stride = 0;
                for(auto& elem : elements)
                {
                    elem.offset = offset;
                    offset += elem.size;
                    stride += elem.size;
                }
            }
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
            virtual void Unbind() const = 0;

            virtual void SetData(const void* data, v_uint32t size) = 0;
            virtual const BufferLayout& GetLayout() const = 0;
            virtual void SetLayout(const BufferLayout& layout) = 0;

            static Ref<VertexBuffer> Create(v_uint32t size);
            static Ref<VertexBuffer> Create(float* vertices, v_uint32t size);
        };

        enum class FramebufTextureFormat
        {
            None = 0,

            // Color
            RGBA8,

            // Depth/stencil
            DEPTH24STENCIL8,

            // Defaults
            Depth = DEPTH24STENCIL8
        };

        struct FramebufTextureSpecification
        {
            FramebufTextureSpecification() = default;
            FramebufTextureSpecification(FramebufTextureFormat format)
            : TextureFormat(format) {}

            FramebufTextureFormat TextureFormat = FramebufTextureFormat::None;
            // TODO: filtering/wrap
        };

        struct FramebufAttachmentSpecification
        {
            FramebufAttachmentSpecification() = default;
            FramebufAttachmentSpecification(std::initializer_list<FramebufTextureSpecification> attachments) : __Attachments(attachments)
            {
            }

            std::vector<FramebufTextureSpecification> __Attachments;
        };

        struct FramebufSpecification
        {
            v_uint32t __Width = 0, __Height = 0;
            FramebufAttachmentSpecification __Attachments;
            v_uint32t __Samples = 1;

            bool __SwapChainTarget = false;
        };

        class Framebuf
        {
        public:
            virtual ~Framebuf() = default;
            virtual void Bind() = 0;
            virtual void Unbind() = 0;

            virtual void Resize(v_uint32t width, v_uint32t height) = 0;
            virtual v_uint32t GetColorAttachmentRendererId(v_uint32t index = 0) const = 0;
            virtual const FramebufSpecification& GetSpecification() const = 0;

            static Ref<Framebuf> Create(const FramebufSpecification& spec);
        };

    }
}
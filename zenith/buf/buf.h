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

#include <zenith/type.h>
#include <api/glfw-api.h>
#include <memory>

#define SIZE_I4   4
#define SIZE_I8   8
#define SIZE_I12 12
#define SIZE_I16 16
#define SIZE_I36 36
#define SIZE_I64 64

namespace zenith
{

    enum shader_t
    {
        FLOAT, FLOAT2, FLOAT3, FLOAT4,
        MAT3, MAT4,
        INT, INT2, INT3, INT4
    };

    static v_ui32 __shader_t_size(shader_t type)
    {
        switch(type)
        {
            case shader_t::FLOAT:    return SIZE_I4;
            case shader_t::FLOAT2:   return SIZE_I8;
            case shader_t::FLOAT3:   return SIZE_I12;
            case shader_t::FLOAT4:   return SIZE_I16;

            case shader_t::MAT3:     return SIZE_I36;
            case shader_t::MAT4:     return SIZE_I64;

            case shader_t::INT:      return SIZE_I4;
            case shader_t::INT2:     return SIZE_I8;
            case shader_t::INT3:     return SIZE_I12;
            case shader_t::INT4:     return SIZE_I16;
        }

        return 0;
    }

    struct element_t
    {
        v_cc name;
        size_t offset;
        v_ui32 size;
        shader_t type;
        bool normalized;

        element_t(v_cc name_, shader_t type_, bool normalized_ = false)
            : name(name_), type(type_), size(__shader_t_size(type_)), offset(0), normalized(normalized_) {}

        GLenum __type() const
        {
            switch (type)
            {
                case FLOAT:
                case FLOAT2:
                case FLOAT3:
                case FLOAT4:
                case MAT3:
                case MAT4:       return  GL_FLOAT;
                case INT:
                case INT2:
                case INT3:
                case INT4:       return  GL_INT;
            }

            return 0;
        }

        v_ui32 __size() const
        {
            switch (type)
            {
                case FLOAT:      return  1;
                case FLOAT2:     return  2;
                case FLOAT3:     return  3;
                case FLOAT4:     return  4;
                case MAT3:       return  9;
                case MAT4:       return 16;
                case INT:        return  1;
                case INT2:       return  2;
                case INT3:       return  3;
                case INT4:       return  4;
            }

            return 0;
        }
    };

    /**
     * Buffer layout like this:
     *
     * <code>
     *      glEnableVertexAttribArray(0);
     *      glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), NULL);
     * </code>
     */
    class layout_t
    {
    public:
        layout_t() {}
        layout_t(const std::initializer_list<element_t>& e) : elements(e)
        {
            v_ui32 offset = 0;
            stride = 0;
            for(auto& element : elements)
            {
                element.offset = offset;
                offset += element.size;
                stride += element.size;
            }
        }

        inline const v_ui32 __stride() const { return stride; }
        inline const std::vector<element_t>& __elements() const { return elements; }

        std::vector<element_t>::iterator begin() { return elements.begin(); }
        std::vector<element_t>::iterator end() { return elements.end(); }
        std::vector<element_t>::const_iterator begin() const { return elements.begin(); }
        std::vector<element_t>::const_iterator end() const { return elements.end(); }
    private:
        v_ui32 stride;
        std::vector<element_t> elements;
    };

    class VertexBuffer
    {
    public:
        virtual ~VertexBuffer() {};
        virtual void bind() = 0;
        virtual void unbind() = 0;
        virtual void __data(float* vertex, v_ui32 size) = 0;
        virtual void __layout(const layout_t&) = 0;
        virtual const layout_t& __layout() const = 0;

        static VertexBuffer* __create(v_ui32);
        static VertexBuffer* __create(float*, v_ui32);
    };

    class IndexBuffer
    {
    public:
        virtual ~IndexBuffer() {};
        virtual void bind() = 0;
        virtual void unbind() = 0;
        virtual v_ui32 size() const = 0;

        static IndexBuffer* __create(v_ui32* indices, v_ui32 size);
    };

}
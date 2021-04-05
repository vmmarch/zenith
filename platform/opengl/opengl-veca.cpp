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
#include "opengl-veca.h"
#include "api/opengl/glfw-api.h"
#include <zenith/assert.h>
#include <zenith/globalization.h>

namespace zenith
{
    static GLenum ShaderTypeToGLType(ShaderType type)
    {
        switch (type)
        {
            case ShaderType::FLOAT:
            case ShaderType::FLOAT2:
            case ShaderType::FLOAT3:
            case ShaderType::FLOAT4:
            {
                return GL_FLOAT;
            }

            case ShaderType::MAT3:
            case ShaderType::MAT4:
            {
                return GL_INT;
            }

            case ShaderType::INT:
            case ShaderType::INT2:
            case ShaderType::INT3:
            case ShaderType::INT4:
            {
                return GL_INT;
            }

            case ShaderType::BOOL:
            {
                return GL_BOOL;
            }
        }

        return 0;
    }

    OpenGLVeca::OpenGLVeca()
    {
        glGenVertexArrays(1, &rendererId);
    }

    OpenGLVeca::~OpenGLVeca()
    {
        glDeleteVertexArrays(1, &rendererId);
    }

    void OpenGLVeca::Bind() const
    {
        glBindVertexArray(rendererId);
    }

    void OpenGLVeca::Unbind() const
    {
        glBindVertexArray(0);
    }

    void OpenGLVeca::AddVertexBuffer(const Ref<buf::VertexBuffer> &__vertexBuffers)
    {
        Bind();
        __vertexBuffers->Bind();

        const auto &layout = __vertexBuffers->GetLayout();
        for (const auto &elem : layout)
        {
            switch (elem.type)
            {
                case ShaderType::FLOAT:
                case ShaderType::FLOAT2:
                case ShaderType::FLOAT3:
                case ShaderType::FLOAT4:
                {
                    glEnableVertexAttribArray(this->vertexBufferIndex);
                    glVertexAttribPointer(this->vertexBufferIndex,
                                          elem.GetComponentCount(),
                                          ShaderTypeToGLType(elem.type),
                                          elem.normalized ? GL_TRUE : GL_FALSE,
                                          layout.GetStride(),
                                          (const void *) elem.offset);
                    this->vertexBufferIndex++;
                    break;
                }

                case ShaderType::INT:
                case ShaderType::INT2:
                case ShaderType::INT3:
                case ShaderType::INT4:
                case ShaderType::BOOL:
                {
                    glEnableVertexAttribArray(this->vertexBufferIndex);
                    glVertexAttribIPointer(this->vertexBufferIndex,
                                           elem.GetComponentCount(),
                                           ShaderTypeToGLType(elem.type),
                                           layout.GetStride(),
                                           (const void *) elem.offset);
                    this->vertexBufferIndex++;
                    break;
                }

                case ShaderType::MAT3:
                case ShaderType::MAT4:
                {
                    v_uint8t count = elem.GetComponentCount();
                    for (v_uint8t i = 0; i < count; i++)
                    {
                        glEnableVertexAttribArray(this->vertexBufferIndex);
                        glVertexAttribPointer(this->vertexBufferIndex,
                                              count,
                                              ShaderTypeToGLType(elem.type),
                                              elem.normalized ? GL_TRUE : GL_FALSE,
                                              layout.GetStride(),
                                              (const void*)(elem.offset + sizeof(float) * count * i));
                    }
                    break;
                }

                default:
                __ZENITH_ASSERT__(false, __UNKNOWN_SHADER_TYPE__);
            }

            this->vertexBuffers.push_back(__vertexBuffers);
        }

    }

    void OpenGLVeca::SetIndexBuffer(const Ref<buf::IndexBuffer> &__indexBuffer)
    {
        glBindVertexArray(rendererId);
        __indexBuffer->Bind();

        this->indexBuffer = __indexBuffer;
    }

}
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
#include <glad/glad.h>
#include <GLFW/glfw3.h>
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
        glCreateVertexArrays(1, &rendererId);
    }

    OpenGLVeca::~OpenGLVeca()
    {

    }

    void OpenGLVeca::Bind() const
    {
        glBindVertexArray(rendererId);
    }

    void OpenGLVeca::Unbind() const
    {
        glBindVertexArray(0);
    }

    void OpenGLVeca::AddVertexBuffer(const Ref<buf::VertexBuffer> &vertexBuffers)
    {
        Bind();
        vertexBuffers->Bind();

        const auto &layout = vertexBuffers->GetLayout();
        for (const auto &elem : layout)
        {
            switch (elem.Type)
            {
                case ShaderType::FLOAT:
                case ShaderType::FLOAT2:
                case ShaderType::FLOAT3:
                case ShaderType::FLOAT4:
                {
                    glEnableVertexAttribArray(m_VertexBufferIndex);
                    glVertexAttribPointer(m_VertexBufferIndex,
                                          elem.getComponentCount(),
                                          ShaderTypeToGLType(elem.type),
                                          elem.Normalized ? GL_TRUE : GL_FALSE,
                                          layout.GetStride(),
                                          (const void *) elem.offset);
                    m_VertexBufferIndex++;
                    break;
                }

                case ShaderType::INT:
                case ShaderType::INT2:
                case ShaderType::INT3:
                case ShaderType::INT4:
                case ShaderType::BOOL:
                {
                    glEnableVertexAttribArray(m_VertexBufferIndex);
                    glVertexAttribIPointer(m_VertexBufferIndex,
                                           elem.getComponentCount(),
                                           ShaderTypeToGLType(elem.type),
                                           elem.Normalized ? GL_TRUE : GL_FALSE,
                                           layout.GetStride(),
                                           (const void *) elem.offset);
                    break;
                }

                case ShaderType::MAT3:
                case ShaderType::MAT4:
                {
                    v_uint8t count = elem.getComponentCount();
                    for (v_uint8t i = 0; i < count; i++)
                    {
                        glEnableVertexArrayAttrib(m_VertexBufferIndex);
                        glVertexAttribPointer(m_VertexBufferIndex,
                                              count, elem.Normalized ? GL_TRUE : GL_FALSE,
                                              layout.GetStride(),
                                              (const void *) elem.offset);
                    }
                    break;
                }

                default: __ZENITH_ASSERT__(false, __UNKNOWN_SHADER_TYPE__);
            }

            m_VertexBuffers.push_back(vertexBuffers);
        }

    }

}
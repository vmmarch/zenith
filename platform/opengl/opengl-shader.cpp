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

/*! ===> Creates on 2021/4/6. <=== */

/*!
 * @author 2B键盘
 */
#include <fstream>
#include <vector>
#include "opengl-shader.h"

namespace zenith
{

    static GLenum ShaderTypeFromString(v_cc type)
    {
        if (type == "vertex")
            return GL_VERTEX_SHADER;
        if (type == "fragment" || type == "pixel")
            return GL_FRAGMENT_SHADER;

        return 0;
    }

    OpenGLShader::OpenGLShader(v_cc filepath)
    {
        v_cc source = ReadFile(filepath);
        auto shaderSource = Preprocess(source);
        Compile(shaderSource);
    }

    OpenGLShader::OpenGLShader(v_cc name, v_cc vec_f, v_cc frgm_f) : __Name(name)
    {
        std::unordered_map<GLenum, v_cc> sources;
        sources[GL_VERTEX_SHADER] = vec_f;
        sources[GL_FRAGMENT_SHADER] = frgm_f;

        Compile(sources);
    }

    OpenGLShader::~OpenGLShader()
    {
        glDeleteShader(__RendererId);
    }

    void OpenGLShader::Bind() const
    {
        __glBindProgram__(__RendererId);
    }

    void OpenGLShader::Unbind() const
    {
        __glUnbindProgram__();
    }

    void OpenGLShader::SetInt(v_cc name, int value)
    {
        __glUniform1i__(__RendererId, name, value);
    }

    void OpenGLShader::SetIntArray(v_cc name, int *values, v_uint32t count)
    {
        __glUniformai__(__RendererId, name, count, values);
    }

    void OpenGLShader::SetFloat(v_cc name, float value)
    {
        __glUniform1f__(__RendererId, name, value);
    }

    void OpenGLShader::SetFloat2(v_cc name, const glm::vec2 &value)
    {
        __glUniform2f__(__RendererId, name, value.x, value.y);
    }

    void OpenGLShader::SetFloat3(v_cc name, const glm::vec3 &value)
    {
        __glUniform3f__(__RendererId, name, value.x, value.y, value.z);
    }

    void OpenGLShader::SetFloat4(v_cc name, const glm::vec4 &value)
    {
        __glUniform4f__(__RendererId, name, value.x, value.y, value.z, value.w);
    }

    void OpenGLShader::SetMat3(v_cc name, const glm::mat3 &value)
    {
        __glUniformMatrix3fv__(__RendererId, name, value);
    }

    void OpenGLShader::SetMat4(v_cc name, const glm::mat4 &value)
    {
        __glUniformMatrix4fv__(__RendererId, name, value);
    }

    v_cc OpenGLShader::ReadFile(v_cc path)
    {
        std::string result;
        std::ifstream in(path, std::ios::in | std::ios::binary); // ifstream closes itself due to RAII
        if (in)
        {
            in.seekg(0, std::ios::end);
            size_t size = in.tellg();
            if (size != -1)
            {
                result.resize(size);
                in.seekg(0, std::ios::beg);
                in.read(&result[0], size);
            } else
            {
                __ZENITH_ERROR__("Could not read from file '{0}'", path);
            }
        } else
        {
            __ZENITH_ERROR__("Could not open file '{0}'", path);
        }

        return result.c_str();
    }

    std::unordered_map<GLenum, v_cc> OpenGLShader::Preprocess(v_cc __source)
    {
        std::string source = __source;
        std::unordered_map<GLenum, v_cc> shaderSources;

        v_cc typeToken = "#type";
        size_t typeTokenLength = strlen(typeToken);
        size_t pos = source.find(typeToken, 0); // start of shader type declaration line.
        while (pos != std::string::npos)
        {
            size_t eol = source.find_first_of("\r\n", pos);
            size_t begin = pos + typeTokenLength + 1;
            std::string type = source.substr(begin, eol - begin);

            size_t nextLinePos = source.find_first_not_of("\r\n", eol);
            pos = source.find(typeToken, nextLinePos);

            shaderSources[ShaderTypeFromString(type.c_str())] =
                    (pos == std::string::npos) ? source.substr(nextLinePos).c_str()
                                               : source.substr(nextLinePos, pos - nextLinePos).c_str();

            return shaderSources;
        }
    }

    void OpenGLShader::Compile(std::unordered_map<GLenum, v_cc> &shaderSources)
    {
        GLuint program = glCreateProgram();
        std::array<GLenum, 2> glShaderIDs;
        int glShaderIDIndex = 0;
        for (auto &kv : shaderSources)
        {
            GLenum type = kv.first;
            const std::string &source = kv.second;

            GLuint shader = glCreateShader(type);

            const GLchar *source_cc = source.c_str();
            glShaderSource(shader, 1, &source_cc, 0);
            glCompileShader(shader);

            GLint isCompiled = 0;
            glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);
            if (isCompiled == GL_FALSE)
            {
                GLint maxLength = 0;
                glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);

                std::vector<GLchar> infoLog(maxLength);
                glGetShaderInfoLog(shader, maxLength, &maxLength, &infoLog[0]);

                glDeleteShader(shader);

                __ZENITH_ERROR__("{0}", infoLog.data());
                break;
            }

            glAttachShader(program, shader);
            glShaderIDs[glShaderIDIndex++] = shader;
        }

        __RendererId = program;

        // link program
        glLinkProgram(program);

        GLint isLinked = 0;
        glGetProgramiv(program, GL_LINK_STATUS, (int *) &isLinked);
        if(isLinked == GL_FALSE)
        {
            GLint maxLength = 0;
            glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);

            std::vector<GLchar> infoLog(maxLength);
            glGetProgramInfoLog(program, maxLength, &maxLength, &infoLog[0]);

            glDeleteProgram(program);

            for(auto id : glShaderIDs)
                glDeleteShader(id)

            __ZENITH_ERROR__("{0}", infoLog.data());
        }
    }

}
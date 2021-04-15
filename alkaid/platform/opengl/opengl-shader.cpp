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

/*! ===> Creates on 2021/4/14. <=== */

/*!
 * @author 2B键盘
 */
#include <alkaid/globalization.h>
#include "opengl-shader.h"
#include <api/glfw-api.h>
#include <fstream>
#include <sstream>

namespace alkaid
{
    OpenGLShader::OpenGLShader(v_cc vertex_path, v_cc fragment_path)
    {
        v_cc vcode;
        v_cc fcode;
        std::ifstream vshader;
        std::ifstream fshader;

        // 确保ifstream对象能够抛出异常信息
        vshader.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        fshader.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        try
        {
            vshader.open(vertex_path);
            fshader.open(fragment_path);
            std::stringstream __vstream, __fstream;

            __vstream << vshader.rdbuf();
            __fstream << fshader.rdbuf();

            // 关闭流
            vshader.close();
            fshader.close();

            // 流转成string字符串
            vcode = __vstream.str().c_str();
            fcode = __fstream.str().c_str();
        } catch (std::ifstream::failure &e)
        {
            __ALKAID_ERROR(SHADER_FILE_READ_NOT_SUCCESS)
        }

        v_ui1 vertex, fragment;
        // 创建vertex shader
        vertex = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertex, 1, &vcode, NULL);
        glCompileShader(vertex);
        checkCompileErrors(vertex, "VERTEX");

        // 创建fragment shader
        fragment = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragment, 1, &fcode, NULL);
        glCompileShader(fragment);
        checkCompileErrors(fragment, "FRAGMENT");

        // 绑定着色器程序
        shader_id = glCreateProgram();
        glAttachShader(shader_id, vertex);
        glAttachShader(shader_id, fragment);
        glLinkProgram(shader_id);
        checkCompileErrors(shader_id, "PROGRAM");

        // 删除着色器，因为当前着色器已经链接到我们的程序中了。
        glDeleteShader(vertex);
        glDeleteShader(fragment);
    }

    void OpenGLShader::bind()
    {
        glUseProgram(shader_id);
    }

    void OpenGLShader::setBool(v_cc name, bool value) const
    {
        __glUniform1i(shader_id, name, value);
    }

    void OpenGLShader::setInt(v_cc name, int value) const
    {
        __glUniform1i(shader_id, name, value);
    }

    void OpenGLShader::setFloat(v_cc name, float value) const
    {
        __glUniform1f(shader_id, name, value);
    }

    void OpenGLShader::setFloat2(v_cc name, glm::vec2 value) const
    {
        __glUniform2f(shader_id, name, value.x, value.y);
    }

    void OpenGLShader::setFloat3(v_cc name, glm::vec3 value) const
    {
        __glUniform3f(shader_id, name, value.x, value.y, value.z);
    }

    void OpenGLShader::setFloat4(v_cc name, glm::vec4 value) const
    {
        __glUniform4f(shader_id, name, value.x, value.y, value.w, value.a);
    }

    void OpenGLShader::setMat3(v_cc name, glm::mat3 value) const
    {
        __glUniformMatrix3fv(shader_id, name, value);
    }

    void OpenGLShader::setMat4(v_cc name, glm::mat4 value) const
    {
        __glUniformMatrix4fv(shader_id, name, value);
    }

    void OpenGLShader::checkCompileErrors(unsigned int shader, std::string type)
    {
        int success;
        char infoLog[1024];
        if (type != "PROGRAM")
        {
            glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
            if (!success)
            {
                glGetShaderInfoLog(shader, 1024, NULL, infoLog);
                std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog
                          << "\n -- --------------------------------------------------- -- " << std::endl;
            }
        } else
        {
            glGetProgramiv(shader, GL_LINK_STATUS, &success);
            if (!success)
            {
                glGetProgramInfoLog(shader, 1024, NULL, infoLog);
                std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog
                          << "\n -- --------------------------------------------------- -- " << std::endl;
            }
        }
    }
}

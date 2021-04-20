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
#include <zenith/globalization.h>
#include "opengl-shader.h"
#include <fstream>
#include <sstream>

#define RD_NONE 0
#define RD_VERTEX 1
#define RD_FRAGMENT 2

#define GLSL_VERSION "#version 330 core\n"

namespace zenith
{
    static void load_shader(v_cc path, std::string &vtext, std::string &ftext);

    OpenGLShader::OpenGLShader(v_cc path, v_cc debugname)
    {
#ifdef __DEBUG__
        ZENITH_DEBUG(IFSPLIT);
#endif
        ZENITH_INFO(CREATE_SHADER, path, debugname);
        std::string v_str_code, f_str_code;
        load_shader(path, v_str_code, f_str_code);

        v_cc vcode = v_str_code.c_str(), fcode = f_str_code.c_str();

#ifdef __DEBUG__
        ZENITH_DEBUG(VERTEX_SHADER_DEBUG, vcode);
        ZENITH_DEBUG(FRAGMENT_SHADER_DEBUG, fcode);
#endif

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

        if(error)
            ZENITH_ERROR(CREATE_SHADER_FAILED, debugname);

// #ifdef __DEBUG__
//         ZENITH_DEBUG(ENDIFSPLIT);
// #endif
    }

    OpenGLShader::~OpenGLShader()
    {
        glDeleteShader(shader_id);
    }

    void OpenGLShader::bind()
    {
        glUseProgram(shader_id);
    }

    void OpenGLShader::setBool(v_cc name, bool value) const
    {
        GLAPI_Uniform1i(shader_id, name, value);
    }

    void OpenGLShader::setInt(v_cc name, int value) const
    {
        GLAPI_Uniform1i(shader_id, name, value);
    }

    void OpenGLShader::setFloat(v_cc name, float value) const
    {
        GLAPI_Uniform1f(shader_id, name, value);
    }

    void OpenGLShader::setFloat2(v_cc name, glm::vec2 value) const
    {
        GLAPI_Uniform2f(shader_id, name, value.x, value.y);
    }

    void OpenGLShader::setFloat3(v_cc name, glm::vec3 value) const
    {
        GLAPI_Uniform3f(shader_id, name, value.x, value.y, value.z);
    }

    void OpenGLShader::setFloat4(v_cc name, glm::vec4 value) const
    {
        GLAPI_Uniform4f(shader_id, name, value.x, value.y, value.w, value.a);
    }

    void OpenGLShader::setMat3(v_cc name, glm::mat3 value) const
    {
        GLAPI_UniformMatrix3fv(shader_id, name, value);
    }

    void OpenGLShader::setMat4(v_cc name, glm::mat4 value) const
    {
        GLAPI_UniformMatrix4fv(shader_id, name, value);
    }

    void OpenGLShader::checkCompileErrors(unsigned int shader, std::string type)
    {
        int success;
        char infoLog[1024];
        if(!error)
            error = success;
        if (type != "PROGRAM")
        {
            glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
            if (!success)
            {
                glGetShaderInfoLog(shader, 1024, NULL, infoLog);
                ZENITH_ERROR(SHADER_COMPILATION_ERROR, type.c_str(), infoLog);
            }
        } else
        {
            glGetProgramiv(shader, GL_LINK_STATUS, &success);
            if (!success)
            {
                glGetProgramInfoLog(shader, 1024, NULL, infoLog);
                ZENITH_ERROR(PROGRAM_LINKING_ERROR, type.c_str(), infoLog);
            }
        }
    }

    static void load_shader(v_cc path, std::string &vtext, std::string &ftext)
    {
        std::ifstream in(path);
        if(!in.is_open())
        {
            ZENITH_ERROR(SHADER_FILE_NOT_EXIST, path);
            return;
        }

        int status = RD_NONE;
        std::string line, vstr, fstr;

        vstr.append(GLSL_VERSION);
        fstr.append(GLSL_VERSION);

        while (getline(in, line))
        {
            if (line == "// @vertex")
            {
                status = RD_VERTEX;
                continue;
            }

            if (line == "// @fragment")
            {
                status = RD_FRAGMENT;
                continue;
            }

            if (line == "// @end")
            {
                status = RD_NONE;
                continue;
            }

            if (status == RD_VERTEX)
            {
                vstr.append(line).append("\n");
                continue;
            }

            if (status == RD_FRAGMENT)
            {
                fstr.append(line).append("\n");
                continue;
            }
        }

        std::cout << vstr << "\n";
        vtext = vstr;
        ftext = fstr;

        in.close();
    }

}

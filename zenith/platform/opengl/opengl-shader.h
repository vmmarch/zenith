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
#pragma once

#include "shader.h"


class OpenGLShaderProgram : public ShaderProgram
{
public:
    OpenGLShaderProgram(zenith_char path, zenith_char debugname);
    ~OpenGLShaderProgram() override;
    void bind() override;
    void unbind() override;
    zenith_uint get_id() const override { return shader_id; }
    void set_bool(zenith_char, bool) override;
    void set_int(zenith_char, int) override;
    void set_float(zenith_char, float) override;
    void set_float2(zenith_char, glm::vec2) override;
    void set_float3(zenith_char, glm::vec3) override;
    void set_float4(zenith_char, glm::vec4) override;
    void set_mat3(zenith_char, glm::mat3) override;
    void set_mat4(zenith_char, glm::mat4) override;

    zenith_uint32 get_mark_id() const override;

    bool is_load_success() const override
    {
        return error;
    }

    void reload() override;

private:
    zenith_uint shader_id;

private:

    // utility function for checking shader compilation/linking errors.
    // ------------------------------------------------------------------------
    bool error = false;
    zenith_uint32 mark_id;
    void checkCompileErrors(unsigned int shader, const std::string& type);
};


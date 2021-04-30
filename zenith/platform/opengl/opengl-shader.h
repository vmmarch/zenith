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

#include "render/shader/shader.h"

namespace zenith
{
    class OpenGLShaderProgram : public ShaderProgram
    {
    public:
        OpenGLShaderProgram(zenith_char path, zenith_char debugname);
        ~OpenGLShaderProgram() override;
        void bind() override;
        void unbind() override;
        void SetBool(zenith_char, bool) override;
        void SetInt(zenith_char, int) override;
        void SetFloat(zenith_char, float) override;
        void SetFloat2(zenith_char, glm::vec2) override;
        void SetFloat3(zenith_char, glm::vec3) override;
        void SetFloat4(zenith_char, glm::vec4) override;
        void SetMat3(zenith_char, glm::mat3) override;
        void SetMat4(zenith_char, glm::mat4) override;

        zenith_uint32 GetMarkID() const override;

    private:
        zenith_uint shader_id;

    private:

        // utility function for checking shader compilation/linking errors.
        // ------------------------------------------------------------------------
        bool error = false;
        zenith_uint32 markid;
        void checkCompileErrors(unsigned int shader, std::string type);
    };
}

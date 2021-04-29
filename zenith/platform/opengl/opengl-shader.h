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
        void setBool(zenith_char, bool) override;
        void setInt(zenith_char, int) override;
        void setFloat(zenith_char, float) override;
        void setFloat2(zenith_char, glm::vec2) override;
        void setFloat3(zenith_char, glm::vec3) override;
        void setFloat4(zenith_char, glm::vec4) override;
        void setMat3(zenith_char, glm::mat3) override;
        void setMat4(zenith_char, glm::mat4) override;

    private:
        zenith_uint shader_id;

    private:
        // utility function for checking shader compilation/linking errors.
        // ------------------------------------------------------------------------
        bool error = false;
        void checkCompileErrors(unsigned int shader, std::string type);
    };
}

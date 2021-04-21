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
    class OpenGLShader : public Shader
    {
    public:
        OpenGLShader(v_cc path, v_cc debugname);
        ~OpenGLShader() override;
        void bind() override;
        void unbind() override;
        void setBool(v_cc, bool) const override;
        void setInt(v_cc, int) const override;
        void setFloat(v_cc, float) const override;
        void setFloat2(v_cc, glm::vec2) const override;
        void setFloat3(v_cc, glm::vec3) const override;
        void setFloat4(v_cc, glm::vec4) const override;
        void setMat3(v_cc, glm::mat3) const override;
        void setMat4(v_cc, glm::mat4) const override;

    private:
        v_ui1 shader_id;

    private:
        // utility function for checking shader compilation/linking errors.
        // ------------------------------------------------------------------------
        bool error = false;
        void checkCompileErrors(unsigned int shader, std::string type);
    };
}

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
#pragma once

#include <unordered_map>
#include "render/shader/shader.h"

namespace zenith
{
    class OpenGLShader : public Shader
    {
    public:
        OpenGLShader(v_cc filepaht);
        OpenGLShader(v_cc name, v_cc vec_f, v_cc frgm_f);
        virtual ~OpenGLShader() override;
        void Bind() const override;
        void Unbind() const override;

        void SetInt(v_cc name, int value) override;
        void SetIntArray(v_cc name, int* values, v_uint32t count) override;

        void SetFloat(v_cc name, float value) override;
        void SetFloat2(v_cc name, const glm::vec2& value) override;
        void SetFloat3(v_cc name, const glm::vec3& value) override;
        void SetFloat4(v_cc name, const glm::vec4& value) override;

        void SetMat3(v_cc name, const glm::mat3& value);
        void SetMat4(v_cc name, const glm::mat4& value) override;

    private:
        v_cc __Name;
        v_uint32t __RendererId;
        v_cc ReadFile(v_cc path);
        std::unordered_map<GLenum, v_cc> Preprocess(v_cc source);
        void Compile(std::unordered_map<GLenum, v_cc>&);
    };
}
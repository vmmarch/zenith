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
#include <zenith.h>
#include "api/opengl/glfw-api.h"
#include <glm/glm.hpp>

namespace zenith
{
    class Shader
    {
        virtual ~Shader();
        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;

        virtual void SetInt(v_cc name, int value) = 0;
        virtual void SetIntArray(v_cc name, int* values, v_uint32t count) = 0;

        virtual void SetFloat(v_cc name, float value) = 0;
        virtual void SetFloat2(v_cc name, const glm::vec2& value) = 0;
        virtual void SetFloat3(v_cc name, const glm::vec3& value) = 0;
        virtual void SetFloat4(v_cc name, const glm::vec4& value) = 0;

        virtual void SetMat4(v_cc name, const glm::mat4& value) = 0;

        static Ref<Shader> Create(v_cc filepath);
        static Ref<Shader> Create(v_cc name, v_cc vec_f,v_cc frgm_f);
    };
}
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
 * 着色器
 * @author 2B键盘
 */
#pragma once

#include <api/glfw-api.h>
#include "zenith/type.h"

namespace zenith
{

    class Shader
    {
    public:
        virtual ~Shader() = default;
        virtual void bind() = 0;
        virtual void setBool(v_cc name, bool value) const = 0;
        virtual void setInt(v_cc name, int value) const = 0;
        virtual void setFloat(v_cc name, float value) const = 0;
        virtual void setFloat2(v_cc name, glm::vec2 value) const = 0;
        virtual void setFloat3(v_cc name, glm::vec3 value) const = 0;
        virtual void setFloat4(v_cc name, glm::vec4 value) const = 0;
        virtual void setMat3(v_cc name, glm::mat3 value) const = 0;
        virtual void setMat4(v_cc name, glm::mat4 value) const = 0;

        /*!
         * 创建着色器
         */
        static v_scope<Shader> __create(v_cc path, v_cc debugname = "shader");
    };

}

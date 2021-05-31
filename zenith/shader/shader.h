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

#include "virtual/loader.h"
#include <api/glfw-api.h>
#include "zenith/type.h"

namespace zenith
{

    class ShaderProgram : Loader
    {
    public:
        virtual ~ShaderProgram() = default;
        virtual void bind() = 0;
        virtual void unbind() = 0;
        virtual zenith_uint get_id() const = 0;
        virtual void set_bool(zenith_char name, bool value) = 0;
        virtual void set_int(zenith_char name, int value) = 0;
        virtual void set_float(zenith_char name, float value) = 0;
        virtual void set_float2(zenith_char name, glm::vec2 value) = 0;
        virtual void set_float3(zenith_char name, glm::vec3 value) = 0;
        virtual void set_float4(zenith_char name, glm::vec4 value) = 0;
        virtual void set_mat3(zenith_char name, glm::mat3 value) = 0;
        virtual void set_mat4(zenith_char name, glm::mat4 value) = 0;

        /**
         * 每个 Shader 程序都会有一个独特的标识。这个标识就是 MarkId。
         */
        virtual zenith_uint32 get_mark_id() const = 0;

        /*!
         * 创建着色器
         */
        static ShaderProgram* Create(zenith_char path, zenith_char debugname = "shader");
    };

}

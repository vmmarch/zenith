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

/*! ===> Creates on 2021/6/3. <=== */

/*!
 * @author 2B键盘
 */
#pragma once

#include "shader/shader.h"
#include<glm-api.h>

namespace zenith
{
    class Material
    {
    private:
        glm::vec3 ambient;
        glm::vec3 diffuse;
        glm::vec3 specular;
        int       diffuse_tex;
        int       specular_tex;

    public:
        Material(glm::vec3 ambient,
                 glm::vec3 diffuse,
                 glm::vec3 specular,
                 int       diffuse_tex,
                 int       specular_tex)
        {
            this->ambient           = ambient;
            this->diffuse           = diffuse;
            this->specular          = specular;
            this->diffuse_tex       = diffuse_tex;
            this->specular_tex      = specular_tex;
        }

        void update(ShaderProgram* shader)
        {
            shader->set_float3("material.ambient", ambient);
            shader->set_float3("material.diffuse", diffuse);
            shader->set_float3("material.specular", specular);
            shader->set_int("material.diffuse_tex", diffuse_tex);
            shader->set_int("material.specular_tex", specular_tex);
        }

    };
}
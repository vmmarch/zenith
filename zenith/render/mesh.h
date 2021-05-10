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

/*! ===> Creates on 2021/4/22. <=== */

/*!
 * @author 2B键盘
 */
#pragma once

#include "shader.h"
#include "color.h"

#include <zenith/zms.h>
#include <zenith/type.h>
#include <zenith_string.h>

#include <utility>

namespace zenith
{
    class Mesh;

    struct vertex_t
    {
        float*      position;
        float*      normal;
        float*      tex_coords;
    };

    struct texture_t
    {
        zenith_uint id;
        zenith_char type;
        zenith_char path;
    };

    /**
     * 渲染封装模型
     */
    class Mesh
    {
    public:
        Mesh(std::vector<vertex_t> vertices, std::vector<zenith_uint> indices, std::vector<texture_t> textures)
        {
            this->vertices = vertices;
            this->indices = indices;
            this->textures = textures;
        }

        void bind();

        /**
         * 渲染网格
         * @param shader 着色器
         */
        void draw();

    public:
        std::vector<vertex_t>       vertices;
        std::vector<unsigned int>   indices;
        std::vector<texture_t>      textures;

    private:
        zenith_uint vaoid, vboid, eboid;
    };

}
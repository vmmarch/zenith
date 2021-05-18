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

/*! ===> Creates on 2021/5/9. <=== */

/*!
 * @author 2B键盘
 */
#pragma once

#include "mesh.h"

namespace zenith
{
    class Model
    {
    public:

        /**
         * 创建模型对象
         *
         * @param path   模型路径
         * @param mt     模型类型
         */
        Model(zenith_char path, ShaderProgram* program, zenith_enum mt = ZENITH_MODEL_OBJ, bool gamma = false)
            : gamma_correction(gamma)
        {
            load_model(path, mt);
            this->program = program;
        }

        ShaderProgram *get_program() { return program; }

        void draw();
s
    private:
        void load_model(zenith_char path, zenith_enum mt);

        /**
         * 解析Obj模型
         * @param path 模型路径
         */
        void parse_obj(zenith_char path);

    private:
        ShaderProgram *program;
        std::vector<texture_t> textures;
        std::vector<Mesh> meshes;

        bool gamma_correction;
    };
}
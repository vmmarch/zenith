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

/*! ===> Creates on 2021/4/26. <=== */

/*!
 * @author 2B键盘
 */
#pragma once

#include <zenith/type.h>
#include <zenith/glob.h>
#include <api/glm-api.h>
#include <vector>

namespace zenith
{

    class Importer
    {
    public:
        /**
         * 模型读取
         * @param modpath 模型路径
         */
        virtual void ReadFile(v_cc modpath) = 0;

        /**
         * 设置纹理，从文件读取
         * @param texpath 纹理路径
         */
        virtual void SetTextureFormFile(v_cc texpath) = 0;

        virtual std::vector<glm::vec3> GetVertexArray() = 0;
    };
}
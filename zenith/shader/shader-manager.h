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

#include <map>
#include <zenith-std.h>
#include "shader.h"
#include <zenith/type.h>
#include <zenith/glob.h>

class ShaderManager
{
public:
    ShaderManager() = default;

    Shader *get_shader(const std::string &name)
    {
        auto shader = shaders[(name + ".vfs")];
        if (shader == nullptr)
            ZENITH_ERROR(CANNOT_READ_SHADER, name.c_str());

        return shader;
    }

    void load_shaders(const std::string &folder);

private:
    std::map<std::string, Shader *> shaders;
};
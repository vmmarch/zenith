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

/*! ===> Creates on 2021/4/30. <=== */

/*!
 * @author 2B键盘
 */
#pragma once

#include "shader/shader.h"

class Light {
protected:
    glm::vec3 color;
    glm::vec3 position;

public:
    explicit Light(glm::vec3 _color) : color(_color) {
    }

    /**
     * 设置光源位置
     * @param position 坐标
     */
    void set_position(glm::vec3 position)
    {
        this->position = position;
    }

    /**
     * 将光源数据更新到shader
     * @param shader shader程序
     */
    virtual void update(Shader *shader) = 0;

};

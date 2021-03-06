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
 * 渲染队列
 *
 * @author 2B键盘
 */
#pragma once

#include "model/model.h"
#include "shader.h"
#include "light/light.h"

#include <map>
#include <vector>

typedef Shader*                      sp;
typedef std::vector<Model*>          vecq;

class RenderQueue
{
public:
    void push(Model* model, Shader* shader);
    void draw_queue(const glm::mat4& view_matrix, const glm::mat4& projection, glm::vec3 camera_position,
                    Light* light);

    void reload_all_bad_model();
private:
    std::map<sp, vecq> queue;
    std::map<std::string, Model*> bad_models;
};

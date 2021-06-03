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
#include "render/render-queue.h"

namespace zenith
{
    void RenderQueue::push(Model &model, ShaderProgram* shader)
    {
        if (queue.count(shader) > 0)
        {
            vecq vq = queue[shader];
            vq.push_back(model);
        } else
        {
            vecq vq;
            vq.push_back(model);

            queue.insert(std::pair<ShaderProgram *, vecq>(shader, vq));
        }
    }

    void RenderQueue::reload_all_bad_model()
    {

    }

    void RenderQueue::draw_queue(glm::mat4 view_matrix, glm::mat4 projection)
    {
        std::map<sp, vecq>::reverse_iterator    iter;
        for(iter = queue.rbegin(); iter != queue.rend(); iter++)
        {
            ShaderProgram* shader = iter->first;
            shader->bind(); // 绑定Shader

            shader->set_mat4("ViewMatrix", view_matrix);
            shader->set_mat4("ProjectionMatrix", projection);

            for(auto model : iter->second)
                model.draw(shader);
        }
    }

}
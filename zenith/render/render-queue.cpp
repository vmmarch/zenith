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
    void RenderQueue::push(Model& model)
    {
        if(model.get_load_success() == SUCCESSFUL)
        {
            sp program = model.get_program();
            if(queue.count(program) > 0)
            {
                vecq vq = queue[program];
                vq.push_back(model);
            } else
            {
                vecq vq;
                vq.push_back(model);

                queue.insert(std::pair<ShaderProgram*, vecq>(program, vq));
            }
        }
    }

    void RenderQueue::draw_queue()
    {
        std::map<sp, vecq>::reverse_iterator    iter;
        for(iter = queue.rbegin(); iter != queue.rend(); iter++)
        {
            iter->first->bind();
            for(auto model : iter->second)
                model.draw();
        }
    }

}
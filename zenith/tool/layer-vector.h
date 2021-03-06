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

/*! ===> Creates on 2021/4/10. <=== */

/*!
 * @author 2B键盘
 */
#pragma once

#include "layer/layer.h"
#include <vector>

class LayerStack
{
public:

    LayerStack() = default;

    ~LayerStack() = default;

    void push(Layer *layer)
    {
        layers_vector.push_back(layer);
        // layers_vector.emplace(layers_vector.begin() + insert_index, layer);
        insert_index++;
    }

    void update(DeltaTime deltaTime)
    {
        for (auto layer : layers_vector)
            layer->update(deltaTime);
    }

    void render()
    {
        for (auto layer : layers_vector)
            layer->render();
    }

private:
    zenith_uint insert_index = 0;
    std::vector<Layer *> layers_vector;
};

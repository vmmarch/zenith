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

/*! ===> Creates on 2021/4/24. <=== */

/*!
 * @author 2B键盘
 */
#pragma once

#include "layer/layer.h"
#include "render/render-command.h"

namespace zenith
{

    // world space positions of our cubes
    static glm::vec3 cube_pos[] = {
            glm::vec3(-3.8f, -2.0f, -12.3f),
            glm::vec3( 2.4f, -0.4f, -3.5f),
    };

    static int cube_len = 0;

    class ExampleLayer : public Layer
    {
    public:
        explicit ExampleLayer() : Layer("example layer")
        {
            ShaderProgram* shader = ShaderProgram::Create("../sh/shader-vfs");
        }

        void render() override
        {

        }

        void update(DeltaTime) override
        {

        }

        void event(Event&) override
        {

        }

        void close() override {}
    };
}
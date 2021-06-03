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

/*! ===> Creates on 2021/4/7. <=== */

/*!
 * @author 2B键盘
 */
#pragma once

#include "render/renderer.h"
#include "render/render-queue.h"

namespace zenith
{
    class OpenGLRenderer : public AbstractRenderer
    {
    public:
        ~OpenGLRenderer() override = default;
        void clear_color(const glm::vec4&) override;
        void clear() override;
        void begin(Camera&) override;
        void disable_depth_test() override;
        void enable_depth_test() override;
        void submit(Model& model, ShaderProgram* shader) override { render_queue.push(model, shader); }
        void draw_model(Model&) override;
        void draw_models() override;

    private:
        glm::mat4 projection;
        glm::mat4 view_matrix;
        glm::vec3 camera_position;

        RenderQueue render_queue;
    };
}
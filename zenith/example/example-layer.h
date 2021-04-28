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

namespace zenith
{

    // world space positions of our cubes
    static glm::vec3 cube_pos[] = {
            glm::vec3( 0.0f,  0.0f,  0.0f),
            glm::vec3( 2.0f,  5.0f, -15.0f),
            glm::vec3(-1.5f, -2.2f, -2.5f),
            glm::vec3(-3.8f, -2.0f, -12.3f),
            glm::vec3( 2.4f, -0.4f, -3.5f),
            glm::vec3(-1.7f,  3.0f, -7.5f),
            glm::vec3( 1.3f, -2.0f, -2.5f),
            glm::vec3( 1.5f,  2.0f, -2.5f),
            glm::vec3( 1.5f,  0.2f, -1.5f),
            glm::vec3(-1.3f,  1.0f, -1.5f)
    };

    class ExampleLayer : public Layer
    {
    public:
        explicit ExampleLayer(Renderer* renderer) : Layer("example layer"), renderer(renderer)
        {
            zenith_scope<Shader> shader = Shader::__create("../sh/shader-vfs");

            // ----------------------------------------
            // 画三角形
            std::shared_ptr<VertexArray> vertexArray;
            vertexArray.reset(VertexArray::__create());

            float vertices[] = {
                    -0.5f, -0.5f, 0.0f,
                    0.5f, -0.5f, 0.0f,
                    0.0f,  0.5f, 0.0f
            };
            std::shared_ptr<VertexBuffer> vbuf;
            vbuf.reset(VertexBuffer::__create(vertices, sizeof(vertices)));
            vbuf->SetVertexSize(3);

            layout_t layout = {
                    {"position", shader_t::FLOAT3},
            };
            vbuf->SetLayout(layout);
            vertexArray->AddVertexBuffer(vbuf);

            RenderModel model(vertexArray, std::move(shader));

            // 提交渲染模型
            for(int i = 0; i < 10; i++)
                renderer->submit(model);

            GraphicsContext::instance()->SetCurrModel(model);
        }

        void render() override
        {
            // ----------------------------------------------------
            // GL render from there.
            for(int i = 0; i < 10; i++)
            {
                RenderModel& model = renderer->__render_model0();
                model.SetLocation(cube_pos[i]);
                renderer->draw_render_model(model);
            }
        }

        void update(DeltaTime) override
        {

        }

        void event(Event&) override
        {

        }

        void close() override {}

    private:
        Renderer* renderer;
    };
}
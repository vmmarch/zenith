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

    static int cube_len = 2;

    class ExampleLayer : public Layer
    {
    public:
        explicit ExampleLayer() : Layer("example layer")
        {
            ShaderProgram* shader = ShaderProgram::Create("../sh/shader-vfs");

            // ----------------------------------------
            // 画三角形
            VertexArray* vertexArray = VertexArray::Create();

            float vertices[] = {
                    -0.5f, -0.5f, 0.0f,
                    0.5f, -0.5f, 0.0f,
                    0.0f,  0.5f, 0.0f
            };
            VertexBuffer* vbuf = VertexBuffer::Create(vertices, sizeof(vertices));

            layout_t layout = {
                    {"position", shader_t::FLOAT3},
            };
            vbuf->SetLayout(layout);
            vertexArray->AddVertexBuffer(vbuf);

            RenderObject object(vertexArray, shader);

            // 更新坐标等参数
            object.SetUpdate([](RenderObject& object, glm::mat4 projection, glm::mat4 view_matrix){
                ShaderProgram* shader = object.GetShader();

                shader->SetMat4("u_object_location", object.GetMat4Location());
                shader->SetMat4("u_projection", projection);
                shader->SetMat4("u_view", view_matrix);
            });

            // ----------------------------------------------------
            // GL render from there.
            for(int i = 0; i < cube_len; i++)
            {
                object.SetLocation(cube_pos[i]);
                // 提交渲染模型
                Renderer::submit(object);
            }

            GraphicsContext::instance()->SetCurrObject(object);
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
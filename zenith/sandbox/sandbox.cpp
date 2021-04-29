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

/*! ===> Creates on 2021/4/23. <=== */

/*!
 * @author 2B键盘
 */
#include "sandbox.h"
#include "settings.h"
#include "layer/editor-layer.h"
#include "example/example-layer.h"
#include "event/mouse-event.h"
#include "state.h"

namespace zenith
{
    static bool first = true;

    SandBox::SandBox(Window *window)
            : Layer("sandbox layer"), camera(Camera()), window(window)
    {
        this->renderer = Renderer::Create();
        main_layer = new ExampleLayer(renderer.get());

        this->imlayer = new ImGuiLayer();
        layer_stack.push(new HomeLayer());
        layer_stack.push(new EditorLayer());
    }

    void SandBox::initialize()
    {
        // 绘制网格
        float line_vertices[] = {
                0.5f, 0.0f, 0.0f,
        };

        VertexBuffer* line_buffer = VertexBuffer::Create(line_vertices, sizeof(line_vertices));

        line_buffer->SetLayout({
            {"position", shader_t::FLOAT3}
        });

        VertexArray* line_array = VertexArray::Create();
        line_array->AddVertexBuffer(line_buffer);
        line_array->bind();

        this->grid_object = new RenderObject(line_array, Shader::Create("../sh/grid-vfs"));
        this->grid_object->SetUpdate([](RenderObject& object, glm::mat4 projection, glm::mat4 view) {
            Shader* shader = object.GetShader();
            shader->bind();

            shader->setMat4("u_object_location", object.GetMat4Location());
            shader->setMat4("u_projection", projection);
            shader->setMat4("u_view", view);
        });
    }

    void SandBox::update(DeltaTime deltaTime)
    {
        // ----------------------------------------
        // reload settings
        RELOAD_SETTING();

        camera.update(State::GetWidth(), State::GetHeight(), deltaTime);

        // 禁止鼠标移动相机
        if (Input::multikey(ZENITH_KEY_LEFTCONTROL, ZENITH_KEY_LEFTSHIFT, ZENITH_KEY_C))
        {
            SetValue(KEY_CURSOR_MOVE_CAMER, !GetValue(KEY_CURSOR_MOVE_CAMER));
        }

        // 隐藏鼠标
        else if(Input::multikey(ZENITH_KEY_LEFTCONTROL, ZENITH_KEY_C))
        {
            if (!cursor_hide) glfwSetInputMode(window->GetGLFWwindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
            else glfwSetInputMode(window->GetGLFWwindow(), GLFW_CURSOR, GLFW_CURSOR_NORMAL);
            cursor_hide = !cursor_hide;
        }

        main_layer->update(deltaTime);
        layer_stack.update(deltaTime);
    }

    void SandBox::render()
    {
        renderer->begin(camera);
        renderer->clear();

        imlayer->begin();
        {
            layer_stack.render();
        }
        imlayer->end();

        glLineWidth(3.0f);
        renderer->draw_lines(*grid_object);
        main_layer->render();
    }

    void SandBox::event(Event &e)
    {
        if (e.GetEventType() == event::type::EVENT_MOUSE_MOVED)
        {
            if(!GetValue(KEY_CURSOR_MOVE_CAMER)) return;
            MouseMovedEvent &event = dynamic_cast<MouseMovedEvent &>(e);

            float xpos = event.GetX();
            float ypos = event.GetY();

            if (first)
            {
                last_x = xpos;
                last_y = ypos;

                first = false;
            }

            float xoffset = xpos - last_x;
            float yoffset = last_y - ypos;

            last_x = xpos;
            last_y = ypos;

            camera.perspective(xoffset, yoffset);
        }

        if (e.GetEventType() == event::type::EVENT_MOUSE_SCROLLED)
        {
            MouseButtonScrolledEvent &event = dynamic_cast<MouseButtonScrolledEvent &>(e);
            camera.SetZoom(event.GetY());
        }
    }

}
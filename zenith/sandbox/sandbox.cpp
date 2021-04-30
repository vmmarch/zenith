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
#include "color.h"

namespace zenith
{
    static bool first = true;

    glm::vec3 grid_x_pos[] = {
            { 0.0f, 0.5f, 0.5f },
            { 0.0f, 1.0f, 0.5f },
            { 0.0f, 1.5f, 0.5f },
            { 0.0f, 2.0f, 0.5f },
    };

    static int grid_count = 4;

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
        float grid[] = {
                 1.0f, 0.0f, 0.0f,
                -1.0f, 0.0f, 0.0f,
        };
        VertexArray* array = VertexArray::Create();
        array->AddVertexBuffer(grid, sizeof(grid));

        this->grid_object = new RenderObject(array, ShaderProgram::Create("../sh/grid-vfs"));

        grid_object->SetUpdate([](RenderObject& object, glm::mat4 projection, glm::mat4 view){
            ShaderProgram* shader = object.GetShader();

            shader->SetFloat4("u_color", RGBA::RED);
            shader->SetMat4("u_view", view);
            shader->SetMat4("u_projection", projection);
            shader->SetMat4("u_location", object.GetMat4Location());
        });
    }

    void SandBox::update(DeltaTime deltaTime)
    {
        // ----------------------------------
        // ------
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

        for(int i = 0; i < grid_count; i++)
        {
            for(int j = 0; j < grid_count; j++)
            {
                glm::vec3 loc = grid_x_pos[i];
                this->grid_object->SetLocation(loc);
                renderer->DrawLines(*grid_object);
            }
        }
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
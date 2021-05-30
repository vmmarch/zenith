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

    static int grid_count = 8;

    SandBox::SandBox(Window *window)
            : Layer("sandbox layer"), camera(Camera()), window(window)
    {
        main_layer = new ExampleLayer();

        this->imlayer = new ImGuiLayer();
        layer_stack.push(new HomeLayer());
        layer_stack.push(new EditorLayer());

        shader_manager = new ShaderManager();
        shader_manager->load_shaders("../sh");
    }

    void SandBox::initialize()
    {
        ShaderProgram *program = shader_manager->get_program("shader");
        Renderer::submit(*new Model("D:/model/cube.obj", program));
    }

    void SandBox::update(DeltaTime delta_time)
    {
        // ----------------------------------
        // ------
        // reload settings
        RELOAD_SETTING();

        camera.update((float) State::get_width(), (float) State::get_height(), delta_time);

        // 禁止鼠标移动相机
        if (Input::multikey(ZENITH_KEY_LEFTCONTROL, ZENITH_KEY_LEFTSHIFT, ZENITH_KEY_C))
        {
            SetValue(KEY_CURSOR_MOVE_CAMER, !GetValue(KEY_CURSOR_MOVE_CAMER));
        }

        // 隐藏鼠标
        else if(Input::multikey(ZENITH_KEY_LEFTCONTROL, ZENITH_KEY_C))
        {
            if (!cursor_hide) glfwSetInputMode(window->get_glfw_window(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
            else glfwSetInputMode(window->get_glfw_window(), GLFW_CURSOR, GLFW_CURSOR_NORMAL);
            cursor_hide = !cursor_hide;
        }

        main_layer->update(delta_time);
        layer_stack.update(delta_time);
    }

    void SandBox::render()
    {
        Renderer::begin(camera);
        Renderer::clear();

#ifndef __ZENITH_PLATFORM_MACOS__
        imlayer->begin();
        {
            layer_stack.render();
        }
        imlayer->end();
#endif

        Renderer::draw_models();
    }

    void SandBox::event(Event &e)
    {
        if (e.GetEventType() == event::type::EVENT_MOUSE_MOVED)
        {
            if(!GetValue(KEY_CURSOR_MOVE_CAMER)) return;
            auto &event = dynamic_cast<MouseMovedEvent&>(e);

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
            auto &event = dynamic_cast<MouseButtonScrolledEvent &>(e);
            camera.SetZoom(event.GetY());
        }
    }

}
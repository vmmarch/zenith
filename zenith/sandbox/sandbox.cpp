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
#include "event/input.h"

namespace zenith
{

    SandBox::SandBox(Window* window)
        : Layer("sandbox layer"), camera(Camera()), window(window)
    {
        this->renderer = Renderer::__create();
        main_layer = new ExampleLayer(renderer.get());

        this->imlayer = new ImGuiLayer();
        layer_stack.push(new HomeLayer());
        layer_stack.push(new EditorLayer());
    }

    void SandBox::update(Timestep timestep)
    {
        // ----------------------------------------
        // reload settings
        reload_settings();
        camera.update(window->__width(), window->__height(), timestep);

        if(Input::pressed(ZN_KEY_W))
            camera.direction(camera_movement::FORWARD);
        if(Input::pressed(ZN_KEY_S))
            camera.direction(camera_movement::BACKWARD);
        if(Input::pressed(ZN_KEY_A))
            camera.direction(camera_movement::LEFT);
        if(Input::pressed(ZN_KEY_D))
            camera.direction(camera_movement::RIGHT);

        main_layer->update(timestep);
        layer_stack.update(timestep);
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

        main_layer->render();
    }

    void SandBox::event(Event& e)
    {
    }

 }
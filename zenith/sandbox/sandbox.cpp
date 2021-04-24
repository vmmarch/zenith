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
#include "event/key-event.h"
#include "event/input.h"
#include "layer/editor-layer.h"

namespace zenith
{

    SandBox::SandBox() : Layer("sandbox layer")
    {
        this->renderer = Renderer::__create();

        this->imlayer = new ImGuiLayer();
        layer_stack.push(new HomeLayer());
        layer_stack.push(new EditorLayer());
        camera = new OrthographicCamera(-1.0f, 1.0f, -1.0f, 1.0f);
    }

    void SandBox::update(Timestep timestep)
    {
        // ----------------------------------------
        // reload settings
        reload_settings();

        layer_stack.update(timestep);

        if(Input::pressed(ZN_KEY_LEFT))
            position.x -= move_speed * timestep;
        if(Input::pressed(ZN_KEY_RIGHT))
            position.x += move_speed * timestep;
        if(Input::pressed(ZN_KEY_UP))
            position.y -= move_speed * timestep;
        if(Input::pressed(ZN_KEY_DOWN))
            position.y += move_speed * timestep;

        if(Input::pressed(ZN_KEY_A))
            camera->__rotation((rotation += rotation_speed));
        if(Input::pressed(ZN_KEY_D))
            camera->__rotation((rotation -= rotation_speed));

    }

    void SandBox::render()
    {
        renderer->clear();

//        camera->__position(position);
        renderer->begin(camera);

        imlayer->begin();
        {
            layer_stack.render();
        }
        imlayer->end();

        // ----------------------------------------------------
        // GL render from there.
        for(auto model : models)
            renderer->draw_render_model(model);
    }

    void SandBox::event(Event& ev)
    {
    }

    void SandBox::close()
    {
    }
}
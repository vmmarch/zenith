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

/*! ===> Creates on 2021/4/6. <=== */

/*!
 * @author 2B键盘
 */
#include "starter.h"

namespace zenith
{
    Starter *Starter::__instance = nullptr;

    Starter::Starter(v_cc title, int width, int height)
    {
        __instance = this;
        init_window(title, width, height);

        sandbox = new SandBox(window.get());
    }

    Starter::~Starter()
    {
        delete &window;
    }

    void Starter::init_window(v_cc title, int width, int height)
    {
        v_winprops winprops(title, width, height);
        this->window = Window::__create(winprops);
        this->window->SetEventCallback(ZENITH_BIND_EVENT_FN(Starter::event));
    }

    void Starter::close()
    {
        this->running = false;
        this->window->close_window();
    }

    void Starter::event(Event &event)
    {
        event::type type = event.GetEventType();
        switch (type)
        {
            case event::type::EVENT_WINDOW_CLOSE:
                close();
                return;

            default: sandbox->event(event);
        }
    }

    void Starter::update(Timestep timestep)
    {
        sandbox->update(timestep);
    }

    void Starter::start_engine()
    {
        sandbox->clear_color(color::BLACK);

        // ------------------------------------------
        // game loop.
        while (running)
        {
            auto time = (float) glfwGetTime(); // FIXME: get time from different platform. And now use GLFW.
            Timestep timestep = time - last_frame_time;
            last_frame_time = time;

            update(timestep);
            sandbox->render();
            this->window->update();
        }
    }

}
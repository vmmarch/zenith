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

#define __enums(x) #x

namespace alkaid
{

    Starter::Starter()
    {

    }

    Starter::~Starter()
    {
        delete &window;
    }

    void Starter::init_window(v_cc title, int width, int height)
    {
        v_winprops winprops(title, width, height);
        this->window = Window::__create(winprops);
        this->window->set_event_callback(__ALKAID_BIND_EVENT_FN(Starter::on_event));
    }

    void Starter::on_event(Event& event)
    {

        std::cout << __enums(event.getEventType()) << std::endl;
    }

    void Starter::start_engine()
    {
        while(running)
        {
            this->window->on_update();
        }
    }

}
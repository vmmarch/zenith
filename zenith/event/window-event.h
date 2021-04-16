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

/*! ===> Creates on 2021/4/9. <=== */

/*!
 * @author 2B键盘
 */
#pragma once

#include "event/event.h"

namespace zenith
{
    class WindowCloseEvent : public Event
    {
    public:
        WindowCloseEvent() = default;

        TYPE(event::type::EVENT_WINDOW_CLOSE);
        CLASSIF(event::classif::MAIN);
    };

    class WindowResizeEvent : public Event
    {
    public:
        WindowResizeEvent(v_ui1 _width, v_ui1 _height) : width(_width), height(_height) {}

        v_ui1 get_width() const { return width; }
        v_ui1 get_height() const { return height; }

        TYPE(event::type::EVENT_WINDOW_RESIZE);
        CLASSIF(event::classif::MAIN);
    private:
        v_ui1 width, height;
    };

}
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
#pragma once

#include "event.h"

namespace alkaid
{
    using v_moucode = v_ui16;

    namespace mouse
    {
        enum : v_moucode
        {
            // From glfw3.h
            Button0 = 0,
            Button1 = 1,
            Button2 = 2,
            Button3 = 3,
            Button4 = 4,
            Button5 = 5,
            Button6 = 6,
            Button7 = 7,

            ButtonLast = Button7,
            ButtonLeft = Button0,
            ButtonRight = Button1,
            ButtonMiddle = Button2
        };
    }

    class MouseEvent : public Event
    {
    public:
        MouseEvent(v_vec2 vec2) : __vec2(vec2) {}
        MouseEvent(v_ui16 x, v_ui16 y) : __vec2(__create_vec2(x, y)) {};
        MouseEvent(v_moucode vcode) : __mousecode(vcode), __vec2(empty_vec2) {}
        MouseEvent(v_moucode vcode, v_vec2 vec2) : __mousecode(vcode), __vec2(vec2) {}
        MouseEvent(v_moucode vcode, v_ui16 x, v_ui16 y) : __mousecode(vcode), __vec2(__create_vec2(x, y)) {};

        v_ui16 getX()
        { return __vec2.x; }

        v_ui16 getY()
        { return __vec2.y; }

        v_vec2 getMouseCoordinate()
        { return __vec2; };

        v_moucode getMouseCode()
        { return __mousecode; }

        CLASSIF(event::MOUSE);
    private:
        v_vec2 __vec2;
        v_moucode __mousecode;
    };

    /**
     * 鼠标移动
     */
    class MouseMovedEvent : public MouseEvent
    {
    public:

        MouseMovedEvent(v_vec2 vec2) : MouseEvent(vec2)
        {}

        MouseMovedEvent(v_ui16 x, v_ui16 y) : MouseEvent(x, y)
        {}

        TYPE(event::type::EVENT_MOUSE_MOVED);
    };

    /**
     * 鼠标按钮按下
     */
    class MouseButtonPressedEvent : public MouseEvent
    {
    public:
        MouseButtonPressedEvent(v_moucode vcode) : MouseEvent(vcode)
        {}

        MouseButtonPressedEvent(v_moucode vcode, v_vec2 vec2) : MouseEvent(vcode, vec2)
        {}

        MouseButtonPressedEvent(v_moucode vcode, v_ui16 x, v_ui16 y) : MouseEvent(vcode, x, y)
        {}

        TYPE(event::type::EVENT_MOUSE_PRESSED);
    };

    /**
     * 鼠标按钮释放
     */
    class MouseButtonReleasedEvent : public MouseEvent
    {
    public:
        MouseButtonReleasedEvent(v_moucode vcode) : MouseEvent(vcode)
        {}

        MouseButtonReleasedEvent(v_moucode vcode, v_vec2 vec2) : MouseEvent(vcode, vec2)
        {}

        MouseButtonReleasedEvent(v_moucode vcode, v_ui16 x, v_ui16 y) : MouseEvent(vcode, x, y)
        {}

        TYPE(event::type::EVENT_MOUSE_RELEASED);
    };

    /**
     * 鼠标按钮释放
     */
    class MouseButtonScrolledEvent : public MouseEvent
    {
    public:
        MouseButtonScrolledEvent(v_vec2 vec2) : MouseEvent(vec2)
        {}

        MouseButtonScrolledEvent(v_ui16 x, v_ui16 y) : MouseEvent(x, y)
        {}

        TYPE(event::type::EVENT_MOUSE_SCROLLED);
    };

}
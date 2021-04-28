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

#define DIRECTION_UP 1

namespace zenith
{
    using v_moucode = zenith_ui16;

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
        MouseEvent(const float x, const float y) : x(x), y(y) {};
        MouseEvent(const float x, const float y, const v_moucode code): x(x), y(y), __mousecode(code) {};

        float GetX()
        { return x; }

        float GetY()
        { return y; }

        v_moucode __code()
        { return __mousecode; }

        CLASSIF(event::MOUSE);
    private:
        float x, y;
        v_moucode __mousecode;
    };

    /**
     * 鼠标移动
     */
    class MouseMovedEvent : public MouseEvent
    {
    public:
        MouseMovedEvent(const float x, const float y) : MouseEvent(x, y)
        {}

        TYPE(event::type::EVENT_MOUSE_MOVED);
    };

    /**
     * 鼠标按钮按下
     */
    class MouseButtonPressedEvent : public MouseEvent
    {
    public:
        MouseButtonPressedEvent(v_moucode vcode) : MouseEvent(0.0f, 0.0f, vcode) {}
        MouseButtonPressedEvent(v_moucode vcode, const float x, const float y) : MouseEvent(x, y, vcode)
        {}

        TYPE(event::type::EVENT_MOUSE_PRESSED);
    };

    /**
     * 鼠标按钮释放
     */
    class MouseButtonReleasedEvent : public MouseEvent
    {
    public:
        MouseButtonReleasedEvent(v_moucode vcode) : MouseEvent(0.0f, 0.0f, vcode) {}
        MouseButtonReleasedEvent(v_moucode vcode, const float x, const float y) : MouseEvent(vcode, x, y)
        {}

        TYPE(event::type::EVENT_MOUSE_RELEASED);
    };

    /**
     * 鼠标滚动
     */
    class MouseButtonScrolledEvent : public MouseEvent
    {
    public:
        MouseButtonScrolledEvent(const float x, const float y) : MouseEvent(x, y)
        {}

        TYPE(event::type::EVENT_MOUSE_SCROLLED);
    };

}
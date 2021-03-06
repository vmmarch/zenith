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
#include "keycode.h"


class KeyEvent : public Event
{
public:
    KeyEvent(keycode keycode) : __keycode(keycode)
    {}

    keycode getKeycode()
    { return __keycode; }

    CLASSIF(event::KEYBOARD);
private:
    keycode __keycode;
};

/**
 * 键盘按下事件处理
 */
class KeyPressedEvent : public KeyEvent
{
public:
    KeyPressedEvent(keycode keycode, int repeat)
            : KeyEvent(keycode), __repeat(repeat)
    {}

    TYPE(event::type::EVENT_KEY_PRESSED);
private:
    int __repeat;
};

/**
 * 键盘释放事件处理
 */
class KeyReleasedEvent : public KeyEvent
{
public:
    KeyReleasedEvent(keycode keycode) : KeyEvent(keycode)
    {}

    TYPE(event::type::EVENT_KEY_RELEASED);
};

class KeyTypeEvent : public KeyEvent
{
public:
    KeyTypeEvent(const keycode keycode) : KeyEvent(keycode)
    {}

    TYPE(event::type::KEY_TYPE);
};

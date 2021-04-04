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

/*! ===> Creates on 2021/4/3. <=== */

/*!
 * @author orvals
 */
#pragma once

#include "event.h"
#include "key-codes.h"

#define __PRESS__  0
#define __REPEAT__ 1

namespace zenith
{

    class KeyEvent : public Event
    {
    public:
        [[nodiscard]] v_keycode GetKeyCode() const { return m_KeyCode; }
        __EVENT_CLASS_CATEGORY__(EventCategoryInput);
    protected:
        explicit KeyEvent(const v_keycode vkeycode) : m_KeyCode(vkeycode) {}
        v_keycode m_KeyCode;
    };

    class KeyPressedEvent : public KeyEvent
    {
    public:
        KeyPressedEvent(const v_keycode keycode, v_uint16t repeat) : KeyEvent(keycode), m_Repeat(repeat) {}
        [[nodiscard]] v_uint16t GetRepeat() const { return m_Repeat; }
        [[nodiscard]] std::string toString() const override
        {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << m_KeyCode << "(" << m_Repeat << ") repeats.";
            return ss.str();
        }

        __EVENT_CLASS_TYPE__(KeyPressed);
    private:
        v_uint16t m_Repeat;
    };

    class KeyReleaseEvent : public KeyEvent
    {
    public:
        explicit KeyReleaseEvent(const v_keycode keycode) : KeyEvent(keycode) {}
        [[nodiscard]] std::string toString() const override
        {
            std::stringstream ss;
            ss << "KeyReleaseEvent: " << m_KeyCode;
            return ss.str();
        }

        __EVENT_CLASS_TYPE__(KeyReleased);
    };

    class KeyTypeEvent : public KeyEvent
    {
    public:
        explicit KeyTypeEvent(const v_keycode keycode) : KeyEvent(keycode) {}

        [[nodiscard]] std::string toString() const override
        {
            std::stringstream ss;
            ss << "KeyTypedEvent: " << m_KeyCode;
            return ss.str();
        }

        __EVENT_CLASS_TYPE__(KeyTyped);
    };
}
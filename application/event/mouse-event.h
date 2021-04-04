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
#include "mouse-codes.h"

namespace zenith
{
    class MouseButtonEvent : public Event
    {
    public:
        explicit MouseButtonEvent(v_mousecode mousecode) : m_MouseCode(mousecode) {}
        [[nodiscard]] v_mousecode GetMouseCode() const { return m_MouseCode; }
        __EVENT_CLASS_CATEGORY__(EventCategoryInput);
    protected:
        v_mousecode m_MouseCode;
    };

    class MouseButtonPressedEvent : public MouseButtonEvent
    {
    public:
        explicit MouseButtonPressedEvent(v_mousecode button) : MouseButtonEvent(button) {}
        [[nodiscard]] std::string toString() const override
        {
            std::stringstream ss;
            ss << "ButtonPressedEvent: " << m_MouseCode;
            return ss.str();
        }

        __EVENT_CLASS_TYPE__(MouseButtonPressed);
    };

    class MouseButtonReleaseEvent : public MouseButtonEvent
    {
    public:
        explicit MouseButtonReleaseEvent(v_mousecode button) : MouseButtonEvent(button) {}
        [[nodiscard]] std::string toString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonReleaseEvent: " << m_MouseCode;
            return ss.str();
        }

        __EVENT_CLASS_TYPE__(MouseButtonReleased);
    };

    class MouseScrollEvent : public Event
    {
    public:
        MouseScrollEvent(float x_offset, float y_offset) : m_XOffset(x_offset), m_YOffset(y_offset) {}
        [[nodiscard]] float GetXOffset() const { return m_XOffset; }
        [[nodiscard]] float GetYOffset() const { return m_YOffset; }

        [[nodiscard]] std::string toString() const override
        {
            std::stringstream ss;
            ss << "MouseScrollEvent: x,y offset(" << m_XOffset << ", " << m_YOffset <<")";
            return ss.str();
        }

        __EVENT_CLASS_TYPE__(MouseScrolled);
        __EVENT_CLASS_CATEGORY__(EventCategoryInput);
    private:
        float m_XOffset, m_YOffset;
    };

    class MouseMoveEvent : public Event
    {
    public:
        MouseMoveEvent(float x, float y) : m_XPos(x), m_YPos(y) {}
        [[nodiscard]] float GetXPosition() const { return m_XPos;}
        [[nodiscard]] float GetYPosition() const { return m_YPos;}
        void GetPosition(float &x, float &y) const
        {
            x = m_XPos;
            y = m_YPos;
        }

        [[nodiscard]] std::string toString() const override
        {
            std::stringstream ss;
            ss << "MouseMoveEvent: x,y position(" << m_XPos << ", " << m_YPos <<")";
            return ss.str();
        }

        __EVENT_CLASS_TYPE__(MouseScrolled);
        __EVENT_CLASS_CATEGORY__(EventCategoryInput);
    private:
        float m_XPos, m_YPos;
    };
}
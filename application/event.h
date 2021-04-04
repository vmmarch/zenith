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
#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-nodiscard"

#include <sstream>
#include <zenith.h>

namespace zenith
{
    enum class EventType
    {
        None = 0,
        WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
        AppTick, AppUpdate, AppRender,
        KeyPressed, KeyReleased, KeyTyped,
        MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
    };

    enum EventCategory
    {
        None = 0,
        EventCategoryApplication    = __BIT__(0),
        EventCategoryInput          = __BIT__(1),
        EventCategoryKeyboard       = __BIT__(2),
        EventCategoryMouse          = __BIT__(3),
        EventCategoryMouseButton    = __BIT__(4)
    };

#define __EVENT_CLASS_TYPE__(type) static EventType GetStaticEventType() { return EventType::type; } \
                               virtual EventType GetEventType() const override { return GetStaticEventType(); } \
                               virtual v_cc GetName() const override { return #type; }

#define __EVENT_CLASS_CATEGORY__(category) virtual int GetCategoryFlags() const override { return category; }

    class Event
    {
    public:
        bool Handled = false;
        virtual ~Event() = default;
        virtual v_cc GetName() const = 0;
        virtual EventType GetEventType() const = 0;
        virtual int GetCategoryFlags() const = 0;
        virtual std::string toString() const { return GetName();  };

        bool IsInCategory(EventCategory category) const
        {
            return GetCategoryFlags() & category;
        }
    };

    class EventDispatcher
    {
    public:
        explicit EventDispatcher(Event &event) : m_Event(event)
        {}

        template<typename T, typename F>
        bool Dispatcher(const F& func)
        {
            if (m_Event.GetEventType() == T::GetStaticEventType)
            {
                m_Event.Handled |= func(static_cast<T&>(m_Event));
                return true;
            }
            return false;
        }

    private:
        Event& m_Event;
    };

    inline std::ostream& operator << (std::ostream& os, const Event& event)
    {
        return os << event.toString();
    }

}

#pragma clang diagnostic pop
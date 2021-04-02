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

/*! ===> Creates on 2021/4/2. <=== */

/*!
 * @author orvals
 */
#ifndef ZENITH_EVENT_H
#define ZENITH_EVENT_H

#include "assist.h"
#include <string>
#include <functional>

namespace zenith
{
    enum class EventType
    {
        None = 0,
        WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
        Tick, Update, Render,
        KeyPressed, KeyReleased,
        MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
    };

    enum EventCategory
    {
        None = 0,
        Event_C_Application      = BIT(0),
        Event_C_Input            = BIT(1),
        Event_C_Keyboard         = BIT(2),
        Event_C_Mouse            = BIT(3),
        Event_C_MouseButton      = BIT(4)

    };

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; } \
                                 virtual EventType GetEventType() const override { return GetStaticFlags(); } \
                                 virtual const char* GetName() const override { return ##type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

    class Event
    {
        friend class EventDispatcher;
    public:
        ~Event(void) = default;
        bool Handle = false;
        virtual EventType GetEventType() const = 0;
        virtual const char* GetName() const = 0;
        virtual int GetCategoryFlags() const = 0;
        virtual std::string ToString() const { return GetName(); }

        inline bool IsInCategory(EventCategory category)
        {
            return GetCategoryFlags() & category;
        }
    };

    class EventDispatcher
    {
    public:
        EventDispatcher(Event& event)
            : m_Event(event) {}

        template<typename T, typename F>
        bool Dispatch(const F& func)
        {
            if(m_Event.GetEventType() == T::GetStaticType())
            {
                m_Event.Handle |= func(static_cast<T&>(m_Event));
                return true;
            }

            return false;
        }
    private:
        Event& m_Event;
    };

    inline std::ostream& operator<<(std::ostream& os, const Event& e)
    {
        return os << e.ToString();
    }

}

#endif // ===> ZENITH_EVENT_H <===

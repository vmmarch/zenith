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

namespace zenith
{

    // =======================================================================================
    // Window resize event class.
    class WindowResizeEvent : public Event
    {
    public:
        WindowResizeEvent(v_uint width, v_uint height)
                : m_Width(width), m_Height(height)
        {}

        int GetWidth()
        { return this->m_Width; }

        int GetHeight()
        { return this->m_Height; }

        void GetSize(v_uint* w, v_uint* h)
        {
            w = &m_Width;
            h = &m_Height;
        }

        [[nodiscard]] std::string toString() const override
        {
            std::stringstream ss;
            ss << "WindowResizeEvent: w,h(" << m_Width << ", " << m_Height << ")";
            return ss.str();
        }

        __EVENT_CLASS_TYPE__(WindowResize);

        __EVENT_CLASS_CATEGORY__(EventCategoryApplication);
    private:
        v_uint m_Width, m_Height;
    };

    // =======================================================================================
    // Window close event class.
    class WindowCloseEvent : public Event
    {
    public:

        [[nodiscard]] std::string toString() const override
        {
            std::stringstream ss;
            ss << "WindowCloseEvent";
            return ss.str();
        }

        __EVENT_CLASS_TYPE__(WindowClose);

        __EVENT_CLASS_CATEGORY__(EventCategoryApplication);
    };
}
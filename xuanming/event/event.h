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

#include <xuanming/type.h>

namespace xm
{

    namespace event
    {
        /**
         * 事件类型
         */
        enum class type
        {
            NONE = 0,

            WINDOW_RESIZE,
            WINDOW_CLOSE,
            WINDOW_FOCUS,
            WINDOW_LOST_FOCUS,
            WINDOW_MOVED,

            KEY_PRESSED,
            KEY_RELEASED,

            MOUSE_PRESSED,
            MOUSE_RELEASED,
            MOUSE_SCROLLED,
            MOUSE_MOVED
        };

        enum classif
        {
            NONE            = 0,
            MAIN            = __BIT__(1),
            INPUT           = __BIT__(2),
            MOUSE           = __BIT__(3),
            KEYBOARD        = __BIT__(4)
        };

    }

#define TYPE(__type) static event::type getStaticEventType() { return __type; } \
                         virtual event::type getEventType() { return getStaticEventType(); }

#define CLASSIF(__classif) static event::classif getStaticEventClassif() { return __classif; } \
                         virtual event::classif getEventClassif() { return getStaticEventClassif(); }

    class Event
    {
    public:
        virtual ~Event();

        virtual bool isHandle() const = 0; // return false表示事件未处理，需要处理该事件。
        virtual bool handled() const = 0;  // 调用该方法表示事件已被处理
        virtual event::type getEventType() const = 0;

    private:
        bool handle = false;
        event::type __type;
    };
}
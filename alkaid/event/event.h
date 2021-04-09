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

#include <alkaid/type.h>

namespace alkaid
{

    namespace event
    {
        /**
         * 事件类型
         */
        enum class type
        {
            EVENT_NONE = 0,

            EVENT_WINDOW_RESIZE,
            EVENT_WINDOW_CLOSE,
            EVENT_WINDOW_FOCUS,
            EVENT_WINDOW_LOST_FOCUS,
            EVENT_WINDOW_MOVED,

            KEY_TYPE,
            EVENT_KEY_PRESSED,
            EVENT_KEY_RELEASED,

            EVENT_MOUSE_PRESSED,
            EVENT_MOUSE_RELEASED,
            EVENT_MOUSE_SCROLLED,
            EVENT_MOUSE_MOVED
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

#define TYPE(__e_type) static event::type getStaticEventType() { return __e_type; } \
                   virtual event::type getEventType() { return getStaticEventType(); }

#define CLASSIF(__classif) static event::classif getStaticEventClassif() { return __classif; } \
                           virtual event::classif getEventClassif() { return getStaticEventClassif(); }

    class Event
    {
    public:
        virtual ~Event();

        bool isHandle() const { return this->handle; } // return false表示事件未处理，需要处理该事件。
        void handled() { this->handle = true; }  // 调用该方法表示事件已被处理
        virtual event::type getEventType() const { return this->type; }

    private:
        bool handle = false;
        event::type type;
    };
}
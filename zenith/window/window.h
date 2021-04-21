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

#include <functional>
#include <zenith/type.h>
#include "event/event.h"

namespace zenith
{

    /**
     * 窗口基础信息。
     */
    struct v_winprops
    {
        v_cc title;
        v_ui32 width, height;

        v_winprops(v_cc title, v_ui32 width, v_ui32 height)
            : title(title), width(width), height(height) {}
    };

    /**
     * 窗户基类，根据不同的API实现不同的窗口创建
     */
    class Window
    {
    public:

        using f_callback = std::function<void(Event&)>;

        virtual ~Window() = default;
        virtual void setTitle(v_cc) = 0;
        virtual v_cc getTitle() const = 0;
        virtual v_ui32 __width() const = 0;
        virtual v_ui32 __height() const = 0;

        virtual void __event_callback(const f_callback& callback) = 0;
        virtual bool is_close() = 0;
        virtual void update() = 0;
        virtual void close_window() = 0;

        virtual void* __handle() const = 0;

        // 创建Window
        static v_scope<Window> __create(const v_winprops&);
    };
}
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
#include "event/event.h"

namespace alkaid
{

    /**
     * 窗口基础信息。
     */
    struct v_winprops
    {
        v_uc* title;
        v_ui16 width, height;
    };

    /**
     * 窗户基类，根据不同的API实现不同的窗口创建
     */
    class Window
    {
    public:
        virtual ~Window() = default;
        virtual void setTitle(v_uc*) = 0;
        virtual v_uc* getTitle() const = 0;
        virtual v_ui16 getWidth() const = 0;
        virtual v_ui16 getHeight() const = 0;

        virtual bool is_close();
        virtual void on_update() = 0;
        virtual void close_window() = 0;

        // 创建Window
        static v_scope<Window> create(v_winprops);
    };
}
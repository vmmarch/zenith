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

    /**
     * 窗口基础信息。
     */
    struct Winprops
    {
        v_cc __Title;
        v_ui32 __Width, __Height;
    };

    /**
     * 窗户基类，根据不同的API实现不同的窗口创建
     */
    class Window
    {
    public:
        virtual ~Window() = default;
        virtual void setTitle(v_cc) = 0;
        virtual v_cc getTitle() const = 0;
        virtual v_ui32 getWidth() const = 0;
        virtual v_ui32 getHeight() const = 0;

        virtual void on_event() = 0;
        virtual void on_update() = 0;

        // 创建Window
        static v_scope<Window> create(Winprops);
    };
}
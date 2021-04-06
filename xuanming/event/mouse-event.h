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
#include "event.h"

namespace xm
{
    using mousecode = uint16_t;

    namespace v_mousecode
    {
        enum : mousecode
        {
            // From glfw3.h
            Button0                = 0,
            Button1                = 1,
            Button2                = 2,
            Button3                = 3,
            Button4                = 4,
            Button5                = 5,
            Button6                = 6,
            Button7                = 7,

            ButtonLast             = Button7,
            ButtonLeft             = Button0,
            ButtonRight            = Button1,
            ButtonMiddle           = Button2
        };
    }

    class MosueEvent : Event
    {

    };

}
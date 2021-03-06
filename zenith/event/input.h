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

/*! ===> Creates on 2021/4/24. <=== */

/*!
 * @author 2B键盘
 */
#pragma once

#include "event/key-event.h"
#include <zenith/type.h>
#include <api/glfw-api.h>
#include <map>

#define NOT_SCROLLED        0
#define SCROLLED_UP         1
#define SCROLLED_DOWN       2

class Input
{
public:
    /**
     * @return 键盘是否按下
     */
    static bool pressed(keycode);

    /**
     * 两个键是否按下
     */
    static bool pressed(keycode key1, keycode key2);

    /**
     * 三个键是否按下
     */
    static bool pressed(keycode key1, keycode key2, keycode key3);
};

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

/*! ===> Creates on 2021/4/28. <=== */

/*!
 * @author 2B键盘
 */
#pragma once

#include <api/glfw-api.h>


struct State
{
    static GLFWwindow *get_glfw_window();

    /**
     * 获取窗口宽度
     */
    static int get_width();

    /**
     * 获取窗口高度
     */
    static int get_height();

    static void count_plus()
    { LOOP_NUMBER++; }

private:
    static long LOOP_NUMBER;
    static GLFWwindow *window;
};

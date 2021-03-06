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
#include "state.h"
#include "init/starter.h"

long State::LOOP_NUMBER = 0;
GLFWwindow *State::window = nullptr;

GLFWwindow *State::get_glfw_window()
{
    if (window == nullptr)
        window = Starter::instance().GetWindow().get_glfw_window();

    return window;
}

int State::get_width()
{
    return (int) Starter::instance().GetWindow().get_width();
}

int State::get_height()
{
    return (int) Starter::instance().GetWindow().get_height();
}

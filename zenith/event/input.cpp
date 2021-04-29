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
#include "input.h"
#include "state.h"

namespace zenith
{
    bool Input::multikey(zenith_keycode key1, zenith_keycode key2)
    {
        return pressed(key1) && pressed(key2);
    }

    bool Input::multikey(zenith_keycode key1, zenith_keycode key2, zenith_keycode key3)
    {
        return pressed(key1) && pressed(key2) && pressed(key3);
    }

    bool Input::pressed(zenith_keycode key)
    {
        auto state = glfwGetKey(State::GetGLFWwindow(), static_cast<int32_t>(key));
#ifdef __DEBUG__
        bool press = state == GLFW_PRESS || state == GLFW_REPEAT;

        if(press)
            ZENITH_DEBUG("Pressed keycode: %d", key);

        return press;
#else
        return state == GLFW_PRESS || state == GLFW_REPEAT;
#endif
    }
}

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
#include "window.h"
#include "platform/windows/window.h"

namespace alkaid
{
    v_scope<Window> Window::__create(const v_winprops &winprops)
    {
#ifdef __ALKAID_PLATFORM_WINDOWS__
        return __create_scope<win::WinWindow>(winprops);
#else
        __ALKAID_ERROR(__ONLY_SUPPORT_WINDOWS__); return nullptr;
#endif
    }

}
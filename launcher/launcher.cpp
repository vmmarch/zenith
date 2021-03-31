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

/*! ===> Creates on 2021/3/25. <=== */

/*!
 * @author orvals
 */
#include "launcher.h"

namespace zenith
{
    Application::Application(int w, int h)
    {
        if (w == -1 && h == -1)
            this->viewport = new __viewport__(600, 600);
        else
            this->viewport = new __viewport__(w, h);
    }

    Application::~Application()
    {
        delete this->viewport;
    }

    void Application::TurnOffEngine(CALLBACK_BEFORE_ENGINE_SHUTDOWN func)
    {
        func();
        is_stop = true;
    }

    int Application::StartEngine()
    {
        // 展示viewport
        this->viewport->Display(custom_iface, render_iface);

        return EXIT_SUCCESS;
    }
}
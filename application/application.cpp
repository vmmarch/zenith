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

/*! ===> Creates on 2021/4/3. <=== */

/*!
 * @author orvals
 */
#include "application.h"
#include "native-window.h"

namespace zenith
{

    void Application::Close()
    {
        this->m_Running = false;
    }

    void Application::StartEngine()
    {
        v_winprops props;
        props.Title = __ENGINE_NAME__;
        props.Width = 1200;
        props.Height = 900;
        auto window = NativeWindow::Create(props);

        while(m_Running)
        {
            window->OnUpdate();
        }

    }
}
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
 * @author 2B键盘
 */
#include "application.h"
#include "native-window.h"

namespace zenith
{

    void Application::OnEvent(Event &event)
    {
        EventDispatcher dispatcher(event);
        dispatcher.Dispatch<WindowCloseEvent>(__ZENITH_BIND_EVENT_FN__(Application::WindowClose));
        dispatcher.Dispatch<WindowResizeEvent>(__ZENITH_BIND_EVENT_FN__(Application::WindowResize));
    }

    bool Application::WindowClose(WindowCloseEvent& event)
    {
        this->___Running = false;
        return true;
    }

    bool Application::WindowResize(WindowResizeEvent& event)
    {
        v_uint width, height;
        event.GetSize(&width, &height);
        if(width == 0 || height == 0)
        {
            __Minimized = true;
            return false;
        }

        __Minimized = false;
        return false;
    }

    void Application::StartEngine()
    {
        v_winprops props;
        props.Title = __ENGINE_NAME__;
        props.Width = 1200;
        props.Height = 900;
        __window = NativeWindow::Create(props);
        __window->SetEventCallbackFn(__ZENITH_BIND_EVENT_FN__(Application::OnEvent));

        while(___Running)
        {
            __window->OnUpdate();
        }

        __window->CloseWindow();

    }
}
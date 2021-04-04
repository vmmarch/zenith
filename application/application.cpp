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
#include "render/renderer.h"

namespace zenith
{

    void Application::OnEvent(Event &event)
    {
        EventDispatcher dispatcher(event);
        dispatcher.Dispatch<WindowCloseEvent>(__ZENITH_BIND_EVENT_FN__(Application::OnClose));
        dispatcher.Dispatch<WindowResizeEvent>(__ZENITH_BIND_EVENT_FN__(Application::OnResize));
    }

    bool Application::OnClose(WindowCloseEvent& event)
    {
        this->m_Running = false;
        return true;
    }

    bool Application::OnResize(WindowResizeEvent& event)
    {
        v_uint width, height;
        event.GetSize(&width, &height);
        if(width == 0 || height == 0)
        {
            m_Minimized = true;
            return false;
        }

        m_Minimized = false;
        Renderer::OnWindowResize(width, height);

        return false;
    }

    void Application::StartEngine()
    {
        v_winprops props;
        props.Title = __ENGINE_NAME__;
        props.Width = 1200;
        props.Height = 900;
        auto window = NativeWindow::Create(props);

        window->SetEventCallbackFn(__ZENITH_BIND_EVENT_FN__(Application::OnEvent));

        while(!m_Running)
        {
            window->OnUpdate();
        }

    }
}
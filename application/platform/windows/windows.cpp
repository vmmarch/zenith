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
#include "windows.h"
#include "event/event-window-resize.h"

namespace zenith::platform::windows
{

    static uint8_t s_GLFWwindowCount = 0;

    static void GLFWErrorCallback(int error, defv_cc description)
    {
        __ZENITH_ERROR__("GLFW Error ({}): {}", error, description);
    }

    Window::Window(defv_winprops &props)
    {
        Initialize(props);
    }

    Window::~Window()
    {
    }

    void Window::Initialize(defv_winprops &props)
    {
        m_Info.Title = props.Title;
        m_Info.Width = props.Width;
        m_Info.Height = props.Height;

        __ZENITH_INFO__("Create window {0} ({1}, {2})", m_Info.Title, m_Info.Width, m_Info.Height);

        if (s_GLFWwindowCount == 0)
        {
            int success = glfwInit();
            if (!success)
                __ZENITH_ERROR__("Could not initialize GLFW~");

            glfwSetErrorCallback(GLFWErrorCallback);
        }

        m_Window = glfwCreateWindow((int) props.Width, (int) props.Height, props.Title, NULL, NULL);
        s_GLFWwindowCount++;

        // set user pointer
        glfwSetWindowUserPointer(m_Window, &m_Info);
        SetVSync(true);

        // set glfw callback
        glfwSetWindowSizeCallback(m_Window, [](GLFWwindow *window, int width, int height)
        {
            defv_info& info = *(defv_info*) glfwGetWindowUserPointer(window);
            info.Width = width;
            info.Height = height;

            EventOf_WindowResize event(width, height);
            info.EventCallback(event);
        });

    }

    void Window::SetVSync(bool v_sync)
    {
        m_Info.VSync = v_sync;
    }

    bool Window::GetVSync()
    { return m_Info.VSync; }

}
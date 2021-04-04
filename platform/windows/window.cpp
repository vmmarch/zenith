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
#pragma clang diagnostic push
#pragma ide diagnostic ignored "hicpp-multiway-paths-covered"
#pragma ide diagnostic ignored "cppcoreguidelines-pro-type-member-init"

#include "window.h"
#include "event/window-event.h"
#include "event/key-event.h"
#include "event/mouse-event.h"

namespace zenith::platform::windows
{
    static uint8_t s_GLFWwindowCount = 0;

    static void GLFWErrorCallback(int error, v_cc description)
    {
        // __ZENITH_ERROR__("GLFW Error ({}): {}", error, description);
    }

    Window::Window(const zenith::v_winprops &props)
    {
        Initialize(props);
    }

    Window::~Window()
    = default;

    void Window::Initialize(const v_winprops &props)
    {
        m_Info.Title = props.Title;
        m_Info.Width = props.Width;
        m_Info.Height = props.Height;

        // TODO ADD LOGGER.;
        // __ZENITH_INFO__("Create window {0} ({1}, {2})", m_Info.Title, m_Info.Width, m_Info.Height);

        if (s_GLFWwindowCount == 0)
        {
            int success = glfwInit();
// TODO ADD LOGGER.;
//            if (!success)
//                __ZENITH_ERROR__("Could not initialize GLFW~");

            glfwSetErrorCallback(GLFWErrorCallback);
        }

        m_Window = glfwCreateWindow((int) props.Width, (int) props.Height, props.Title, NULL, NULL);
        s_GLFWwindowCount++;

        // Create context.
        m_Context = GraphicsContext::Create(m_Window);
        m_Context->Initialize();

        // set user pointer
        glfwSetWindowUserPointer(m_Window, &m_Info);
        SetVSync(true);

        // set glfw callback
        glfwSetWindowSizeCallback(m_Window, [](GLFWwindow *window, int width, int height)
        {
            v_info &info = *(v_info *) glfwGetWindowUserPointer(window);
            info.Width = width;
            info.Height = height;

            WindowResizeEvent event(width, height);
            info.EventCallback(event);
        });

        glfwSetWindowCloseCallback(m_Window, [](GLFWwindow *window)
        {
            v_info &info = *(v_info *) glfwGetWindowUserPointer(window);

            WindowCloseEvent event;
            info.EventCallback(event);
        });

        glfwSetKeyCallback(m_Window, [](GLFWwindow *window, int key, int scancode, int action, int mods)
        {
            v_info &info = *(v_info *) glfwGetWindowUserPointer(window);

            switch (action)
            {
                case GLFW_PRESS:
                {
                    KeyPressedEvent event(key, __PRESS__);
                    info.EventCallback(event);
                    break;
                }

                case GLFW_RELEASE:
                {
                    KeyReleaseEvent event(key);
                    info.EventCallback(event);
                    break;
                }

                case GLFW_REPEAT:
                {
                    KeyPressedEvent event(key, __REPEAT__);
                    info.EventCallback(event);
                    break;
                }
            }
        });

        glfwSetCharCallback(m_Window, [](GLFWwindow *window, v_uint keycode)
        {
            v_info &info = *(v_info *) glfwGetWindowUserPointer(window);

            KeyTypeEvent event(keycode);
            info.EventCallback(event);
        });

        glfwSetMouseButtonCallback(m_Window, [](GLFWwindow *window, int button, int action, int mods)
        {
            v_info &info = *(v_info *) glfwGetWindowUserPointer(window);
            switch (action)
            {
                case GLFW_PRESS:
                {
                    MouseButtonPressedEvent event(button);
                    info.EventCallback(event);
                    break;
                }

                case GLFW_RELEASE:
                {
                    MouseButtonReleasedEvent event(button);
                    info.EventCallback(event);
                    break;
                }
            }
        });

        glfwSetScrollCallback(m_Window, [](GLFWwindow *window, double x_offset, double y_offset)
        {
            v_info &info = *(v_info *) glfwGetWindowUserPointer(window);

            MouseScrolledEvent event((float) x_offset, (float) y_offset);
            info.EventCallback(event);
        });

        glfwSetCursorPosCallback(m_Window, [](GLFWwindow *window, double x_pos, double y_pos)
        {
            v_info &info = *(v_info *) glfwGetWindowUserPointer(window);

            MouseMovedEvent event((float) x_pos, (float) y_pos);
            info.EventCallback(event);
        });

    }

    void Window::OnUpdate()
    {
        glfwPollEvents();
        m_Context->SwapBuffers();
    }

    void Window::GetSize(int &w, int &h) const
    {

    }

    void Window::SetEventCallbackFn(const f_EventCallbackFn &f)
    {
        m_Info.EventCallback = f;
    }

    void Window::SetVSync(bool v_sync)
    {
        m_Info.VSync = v_sync;
    }

    bool Window::GetVSync()
    { return m_Info.VSync; }

    void Window::CloseWindow()
    {
        glfwDestroyWindow(m_Window);
        s_GLFWwindowCount--;

        if (s_GLFWwindowCount == 0)
            glfwTerminate();
    }

    bool Window::IsClose() const
    { return glfwWindowShouldClose(m_Window); }
}

#pragma clang diagnostic pop
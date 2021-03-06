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

/*! ===> Creates on 2021/4/7. <=== */

/*!
 * @author 2B键盘
 */
#include "window.h"
#include "event/mouse-event.h"
#include "event/key-event.h"
#include "event/window-event.h"

static zenith_uint window_count_of_create = 0;

WinWindow::WinWindow(const v_winprops &winprops)
{
    initialize(winprops);
    callback();
}

WinWindow::~WinWindow()
{
    glfwTerminate();
}

/**
 * 创建窗口并初始化GLFW
 * @param winprops 窗口基本信息（标题、宽度、高度）
 */
void WinWindow::initialize(const v_winprops &winprops)
{

    info.title = winprops.title;
    info.width = winprops.width;
    info.height = winprops.height;

    ZENITH_INFO(CREATE_WINDOW_INFO, info.title, info.width, info.height);

    int success = glfwInit();
    if (!success)
            ZENITH_ERROR(GLFW_INIT_FAILED);

    glfwWindowHint(GL_SAMPLES, 4); // 开启多样本缓冲
    this->window = glfwCreateWindow(info.width, info.height, reinterpret_cast<const char *>(info.title),
                                    nullptr, nullptr);
    window_count_of_create++; // 窗口计数+1

    if (window == nullptr)
    {
        ZENITH_ERROR(CREATE_WINDOW_FAILED);
        glfwTerminate();
    }

    graphics_context = GraphicsContext::Create(this->window);
    glfwSetWindowUserPointer(this->window, &this->info);
}

void WinWindow::callback()
{
    // set framebuffer callback
    glfwSetFramebufferSizeCallback(this->window, [](GLFWwindow *window, int width, int height)
    {
        glViewport(0, 0, width, height);
    });

    // window resize callback
    glfwSetWindowSizeCallback(this->window, [](GLFWwindow *window, int width, int height)
    {
        v_info info = *(v_info*) glfwGetWindowUserPointer(window);
        info.width = width;
        info.height = height;

        WindowResizeEvent event(width, height);
        info.fn(event);
    });

    // window close callback.
    glfwSetWindowCloseCallback(this->window, [](GLFWwindow *window)
    {
        v_info info = *(v_info*) glfwGetWindowUserPointer(window);

        WindowCloseEvent event;
        info.fn(event);
    });

    // key callback
    glfwSetKeyCallback(this->window, [](GLFWwindow *window, int key, int scancode, int action, int mods)
    {
        v_info info = *(v_info*) glfwGetWindowUserPointer(window);

        switch(action)
        {
            case GLFW_PRESS:
            {
                KeyPressedEvent event(key, 0);
                info.fn(event);
                break;
            }

            case GLFW_RELEASE:
            {
                KeyReleasedEvent event(key);
                info.fn(event);
                break;
            }

            case GLFW_REPEAT:
            {
                KeyPressedEvent event(key, 1);
                info.fn(event);
                break;
            }
        }

    });

    // window char callback
    glfwSetCharCallback(this->window, [](GLFWwindow *window, zenith_uint keycode)
    {
        v_info info = *(v_info*) glfwGetWindowUserPointer(window);

        KeyTypeEvent event(keycode);
        info.fn(event);
    });

    // mouse button callback
    glfwSetMouseButtonCallback(this->window, [](GLFWwindow *window, int button, int action, int mods)
    {
        v_info info = *(v_info*) glfwGetWindowUserPointer(window);
        switch(action)
        {
            case GLFW_PRESS:
            {
                MouseButtonPressedEvent event(button);
                info.fn(event);
            }

            case GLFW_RELEASE:
            {
                MouseButtonReleasedEvent event(button);
                info.fn(event);
            }
        }
    });

    // mouse scrolled callback
    glfwSetScrollCallback(this->window, [](GLFWwindow *window, double x_offset, double y_offset)
    {
        v_info info = *(v_info*) glfwGetWindowUserPointer(window);

        MouseButtonScrolledEvent event((float) x_offset, (float) y_offset);
        info.fn(event);
    });

    glfwSetCursorPosCallback(this->window, [](GLFWwindow *window, double x_pos, double y_pos)
    {
        v_info info = *(v_info*) glfwGetWindowUserPointer(window);

        MouseMovedEvent event((float) x_pos, (float) y_pos);
        info.fn(event);
    });

}

void WinWindow::SetEventCallback(const f_callback &fn)
{
    info.fn = fn;
}

bool WinWindow::is_close()
{
    return glfwWindowShouldClose(this->window);
}

void WinWindow::close_window()
{
    destroy(this->window);
    // 如果窗口数量为0就释放窗口占用的内存
    if(window_count_of_create == 0)
        glfwTerminate();
}

void WinWindow::update()
{
    glfwPollEvents();
    graphics_context->swap_buffers();
}

void WinWindow::destroy(GLFWwindow *window)
{
    glfwDestroyWindow(window);
    window_count_of_create--;
}

void* WinWindow::GetWindowHANDLE() const
{
    return this->window;
}

GLFWwindow* WinWindow::get_glfw_window() const
{
    return this->window;
}

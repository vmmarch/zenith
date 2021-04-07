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

namespace alkaid::win
{
    WinWindow::WinWindow(v_winprops &winprops)
    {
        initialize(winprops);
    }

    WinWindow::~WinWindow()
    {
    }

    /**
     * 创建窗口并初始化GLFW
     * @param winprops 窗口基本信息（标题、宽度、高度）
     */
    void WinWindow::initialize(v_winprops &winprops)
    {

        info.title = winprops.title;
        info.width = winprops.width;
        info.height = winprops.height;

        __ALKAID_INFO(__CREATE_WINDOW_INFO__, info.title, info.width, info.height);

        v_suc success = glfwInit();
        if (!success)
                __ALKAID_ERROR(__GLFW_INIT_FAILED__);

        this->window = glfwCreateWindow(info.width, info.height, reinterpret_cast<const char *>(info.title), nullptr, nullptr);
        if(window == nullptr)
        {
            __ALKAID_ERROR(__CREATE_WINDOW_FAILED__);
            glfwTerminate();
        }

        glfwMakeContextCurrent(this->window);

    }

}
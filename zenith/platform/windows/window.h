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
#pragma once
#include "window/window.h"
#include <api/glfw-api.h>
#include "render/graphics-context.h"

namespace zenith::win
{

    class WinWindow : public Window
    {
    public:
        WinWindow(const v_winprops&);
        virtual ~WinWindow();

        void setTitle(zenith_char title) override { info.title = title; }
        zenith_char getTitle() const override { return info.title; }
        zenith_ui32 __width() const override { return info.width; }
        zenith_ui32 __height() const override { return info.height; }

        void SetEventCallback(const f_callback&) override;

        bool is_close() override;
        void close_window() override;
        void update() override;

        void* __handle() const override;

    private:
        struct v_info
        {
            zenith_char title;
            zenith_ui32 width, height;

            f_callback fn;
        };

        v_info info;
        GLFWwindow* window;
        GraphicsContext* graphics_context;

        void initialize(const v_winprops&);
        void callback();
        void destroy(GLFWwindow* window);
    };

}
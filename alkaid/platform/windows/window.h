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

namespace alkaid::win
{

    class WinWindow : public Window
    {
    public:
        WinWindow(const v_winprops&);
        virtual ~WinWindow();

        void setTitle(v_cc title) override { info.title = title; }
        v_cc getTitle() const override { return info.title; }
        v_ui32 getWidth() const override { return info.width; }
        v_ui32 getHeight() const override { return info.height; }
        bool is_close() override;
        void close_window() override;
        void on_update() override;

    private:
        struct v_info
        {
            v_cc title;
            v_ui32 width, height;
        };

        v_info info;
        GLFWwindow* window;
        v_scope<GraphicsContext> graphics_context;

        void initialize(const v_winprops&);
        void callback();
    };

}
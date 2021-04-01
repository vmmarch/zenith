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

/*! ===> Creates on 2021/3/27. <=== */

/*!
 * @author orvals
 */
#pragma once

#include "imgui-env.h"
#include <zenith/zenith.h>
#include <zenith/globalization.h>

class framework;

typedef void (*other_render)();

class framework
{
public:
    framework(int, int);
    ~framework();
    void render(other_render);

private:
    /*! //////////////////////////////////////////////////////////////// */
    /*! variable */
    int width, height;
    // config
    GLFWwindow* window{};
    bool p_open{};
    float c_font_size = 18.0f; // font size
    zenith_cc glslVersion;

    bool show_demo_window;
    bool show_another_window;

    /*! //////////////////////////////////////////////////////////////// */
    /*! method */
    ImGuiIO& setupImGui();
    void setupGLFW();

};
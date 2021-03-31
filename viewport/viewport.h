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

#include "component-container.h"

class __viewport__;

typedef void (*func_custom_iface)(zenith::comps_cntr*);
typedef void (*func_custom_glfw)(GLFWwindow*);
typedef void (*func_render_iface)(__viewport__*, zenith::comps_cntr*);

/*!
 * 模型以及场景展示区
 */
class __viewport__ : public ImGUILayout
{
public:
    __viewport__(int, int);
    ~__viewport__();
    void Display(func_custom_glfw, func_custom_iface, func_render_iface);
    void render(const char *__comps_name);

    /*! //////////////////////////////////////////////////////////////// */
    // get/set
    GLFWwindow *get_GLFWwindow();
    zenith::comps_cntr *get_component_container();

private:
    zenith::comps_cntr* comps = new zenith::comps_cntr(); // 组件容器列表

    /*! //////////////////////////////////////////////////////////////// */
    // config
    bool p_open;
    float c_font_size = 18.0f; // font size

};
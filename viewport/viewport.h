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

class state_manager;

typedef void (*func_custom_iface)(zenith::comps_cntr*);
typedef void (*func_render_iface)(state_manager*, zenith::comps_cntr*);

/*!
 * 模型以及场景展示区
 */
class __viewport__ : public ImGUILayout
{
public:
    __viewport__(int, int);
    ~__viewport__();
    void Display(func_custom_iface, func_render_iface);
    /*! //////////////////////////////////////////////////////////////// */
    // get/set

    GLFWwindow *get_window();
    state_manager *get_state_manager();
    zenith::comps_cntr *get_component_container();

private:
    state_manager *state_m;
    zenith::comps_cntr* comps = new zenith::comps_cntr(); // 组件容器列表

    /*! //////////////////////////////////////////////////////////////// */
    // config
    float c_font_size = 18.0f; // font size

};

/**
 * 组件生成管理类
 */
class state_manager
{
public:
    void render(component*); // 添加导航栏菜单
private:
    __viewport__ *viewport;
    int is_display_menu_bar /*! 显示导航栏菜单 */
    ;
};
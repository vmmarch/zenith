//
// Created by aorus on 2021/3/27.
//
// nama

#pragma once

#include "component-container.h"

class state_manager;

typedef void (*func_custom_iface)(comps_container*);
typedef void (*func_render_iface)(state_manager*, comps_container*);

/*!
 * 模型以及场景展示区
 */
class child_window : public ImGUILayout
{
public:
    child_window(int, int);
    ~child_window();
    void Display(func_custom_iface, func_render_iface);
    ////////////////////////////////////////////////////////////////
    // get/set

    GLFWwindow *get_window();
    state_manager *get_state_manager();
    comps_container *get_component_container();

    ////////////////////////////////////////////////////////////////

private:
    state_manager *vsm;
    comps_container* _comps = new comps_container(); // 组件容器列表
};

/**
 * 组件生成管理类
 */
class state_manager
{
public:
    void render(component*); // 添加导航栏菜单
private:
    child_window *viewport;
    int is_display_menu_bar /*! 显示导航栏菜单 */
    ;
};
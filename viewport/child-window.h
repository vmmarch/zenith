//
// Created by aorus on 2021/3/27.
//
// nama

#pragma once

#include "component/zenith-component.h"

class state_manager;

/*!
 * 模型以及场景展示区
 */
class child_window : public ImGUILayout
{
public:
    child_window(int, int);
    void Display();
    ////////////////////////////////////////////////////////////////
    // get/set

    GLFWwindow *get_window();
    state_manager *get_state_manager();

    ////////////////////////////////////////////////////////////////

private:
    state_manager *vsm;
};

/**
 * 组件生成管理类
 */
class state_manager
{
public:
    void render_menu(zenith::menu *_menu); // 添加导航栏菜单
private:
    zenith::menu menu_bar;
    child_window *viewport;
    int is_display_menu_bar /*! 显示导航栏菜单 */
    ;
};
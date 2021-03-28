//
// Created by aorus on 2021/3/27.
//

#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <zenith/zenith.h>

#include <imgui.h>

/*!
 * 模型以及场景展示区
 */
class Viewport
{
public:
    /*!
     * 创建展示区
     * @param [i] width 视窗宽度
     * @param [i] height 视窗高度
     */
    Viewport(int, int);
    int ViewportInitialize();
    void StartLoop();
private:
    GLFWwindow *kWindowHandle; // 窗口句柄
    int width, height;
};
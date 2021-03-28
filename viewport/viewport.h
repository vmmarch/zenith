//
// Created by aorus on 2021/3/27.
//

#pragma once
#include <zenith/zenith.h>

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
    int StartLoop();
private:
    int width, height;
};
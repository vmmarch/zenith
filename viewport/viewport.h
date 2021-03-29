//
// Created by aorus on 2021/3/27.
//

#pragma once

#include "layout.h"

/*!
 * 模型以及场景展示区
 */
class Viewport : public ImGUILayout
{
public:
    Viewport(int, int);
    int StartLoop();
};
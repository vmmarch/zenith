//
// Created by aorus on 2021/3/30.
//

#ifndef ZENITH_COMPONENT_H
#define ZENITH_COMPONENT_H

#include "layout.h"

class component
{
public:
    bool get_should_be_render();
    void set_should_be_render(bool render); // 是否渲染该组件，默认为true
    virtual void render(); // 渲染
private:
    bool should_be_render = true;
};


#endif //ZENITH_COMPONENT_H

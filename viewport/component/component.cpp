//
// Created by aorus on 2021/3/30.
//

#include "component.h"

bool component::get_should_be_render()
{
    return this->should_be_render;
}

void component::set_should_be_render(bool render)
{
    this->should_be_render = render;
}

void component::render()
{
    // do nothing...
}

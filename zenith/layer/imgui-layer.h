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

/*! ===> Creates on 2021/4/10. <=== */

/*!
 * @author 2B键盘
 */
#pragma once

#include <zenith/type.h>
#include <api/imgui-api.h>
#include <api/glfw-api.h>
#include <map>

struct v_font
{
    zenith_char name;
    float size;
    zenith_char ttf;
};

class ImGuiLayer
{
public:
    ImGuiLayer();
    ~ImGuiLayer() = default;
    void add_font(v_font);
    void apply_font(zenith_char);
    void begin();
    void end();
    void close();

private:
    std::map<zenith_char, ImFont *> font_libs;
    void initialize();
};
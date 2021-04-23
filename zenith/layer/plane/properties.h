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

/*! ===> Creates on 2021/4/11. <=== */

/*!
 * @author 2B键盘
 */
#pragma once

#include "render/graphics-context.h"

static bool check = false;

/**
 * 属性面板配置
 */
static void __properties()
{
    ImGui::Begin(GUI_TEXT_PROPERTIES);
    if (ImGui::TreeNode("camera"))
    {
        ImGui::TreePop();
    }

    if (ImGui::CollapsingHeader("模型选项"))
    {
        if (ImGui::BeginTable("split", 3))
        {
            ImGui::TableNextColumn();

            ImGui::Checkbox("启用线性渲染模式", &check);
            if (check)
            {
                zenith::GraphicsContext::instance()->__curr_model()->__render_type(zenith::render::type_t::LINE);
            } else
            {
                zenith::GraphicsContext::instance()->__curr_model()->__render_type(zenith::render::type_t::FILL);
            }

            ImGui::EndTable();
        }
    }

    ImGui::End();
}
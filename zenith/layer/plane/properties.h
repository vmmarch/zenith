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
#include "settings.h"

static bool line_check = false;
static bool __multisample = false;
static bool __depthtest = false;
static bool reload_settings_check = false;

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

    if (ImGui::CollapsingHeader("配置"))
    {
        if (__multisample)
        {
            if (ImGui::Button("关闭多重采样抗锯齿"))
            {
                zenith::__value(KEY_MULTISAMPLE, V_FALSE);
                __multisample = false;
            }
        } else
        {
            if (ImGui::Button("开启多重采样抗锯齿"))
            {
                zenith::__value(KEY_MULTISAMPLE, V_TRUE);
                __multisample = true;
            }
        }

        if (__depthtest)
        {
            if (ImGui::Button("关闭深度缓冲"))
            {
                zenith::__value(KEY_DEPTHTEST, V_FALSE);
                __depthtest = false;
            }
        } else
        {
            if (ImGui::Button("开启深度缓冲"))
            {
                zenith::__value(KEY_DEPTHTEST, V_TRUE);
                __depthtest = true;
            }
        }
    }

    if (ImGui::CollapsingHeader("模型选项"))
    {
        ImGui::TableNextColumn();

        ImGui::Checkbox("启用线性渲染模式", &line_check);
        if (line_check)
        {
            zenith::GraphicsContext::instance()->__curr_model()->__render_type(zenith::render::type_t::LINE);
        } else
        {
            zenith::GraphicsContext::instance()->__curr_model()->__render_type(zenith::render::type_t::FILL);
        }
    }

    ImGui::End();
}
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

/**
 * 属性面板配置
 */
static void __properties()
{
    ImGui::Begin(GUI_TEXT_PROPERTIES);
    if (ImGui::TreeNode("投影相机"))
    {
        if (get_value(KEY_CURSOR_MOVE_CAMER))
        {
            if (ImGui::Button("关闭鼠标移动相机"))
            {
                set_value(KEY_CURSOR_MOVE_CAMER, ZENITH_FALSE);
            }
        } else
        {
            if (ImGui::Button("启用鼠标移动相机"))
            {
                set_value(KEY_CURSOR_MOVE_CAMER, ZENITH_TRUE);
            }
        }
        ImGui::TreePop();
    }

    if (ImGui::TreeNode("配置"))
    {
        if (get_value(KEY_MULTISAMPLE))
        {
            if (ImGui::Button("关闭多重采样抗锯齿"))
            {
                set_value(KEY_MULTISAMPLE, ZENITH_FALSE);
            }
        } else
        {
            if (ImGui::Button("开启多重采样抗锯齿"))
            {
                set_value(KEY_MULTISAMPLE, ZENITH_TRUE);
            }
        }

        if (get_value(KEY_DEPTHTEST))
        {
            if (ImGui::Button("关闭深度缓冲"))
            {
                set_value(KEY_DEPTHTEST, ZENITH_FALSE);
            }
        } else
        {
            if (ImGui::Button("开启深度缓冲"))
            {
                set_value(KEY_DEPTHTEST, ZENITH_TRUE);
            }
        }

        ImGui::TreePop();
    }

    if (ImGui::TreeNode("模型选项"))
    {
        ImGui::TableNextColumn();

        ImGui::Checkbox("启用线性渲染模式", &line_check);
        if (line_check)
        {
            glEnable(GL_LINE);
        } else
        {
            glEnable(GL_FILL);
        }

        ImGui::TreePop();
    }

    ImGui::End();
}
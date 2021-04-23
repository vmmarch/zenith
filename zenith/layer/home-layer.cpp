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
#include "home-layer.h"
#include "init/starter.h"
#include <zenith/glob.h>
#include "layer/plane/properties.h"
#include "layer/plane/resource-manager.h"

namespace zenith
{

    void HomeLayer::render()
    {
        if (ImGui::BeginMenuBar())
        {
            if (ImGui::BeginMenu(GUI_TEXT_FILE))
            {

                // 新建
                if (ImGui::BeginMenu(GUI_TEXT_CREATE))
                {
                    if (ImGui::MenuItem(GUI_TEXT_CREATE_PROJECT)); // TODO 新建项目
                    ImGui::EndMenu();
                }

                // 打开
                if (ImGui::BeginMenu(GUI_TEXT_OPEN))
                {
                    if (ImGui::MenuItem(GUI_TEXT_OPEN_PROJECT)); // TODO 打开项目
                    if (ImGui::MenuItem(GUI_TEXT_OPEN_FOLDER)); // TODO 打开文件夹
                    ImGui::EndMenu();
                }

                // 退出引擎
                if (ImGui::MenuItem(GUI_TEXT_EXIT))
                    Starter::__instance().close();

                ImGui::EndMenu();
            }
            ImGui::EndMenuBar();
        }

        ImGui::ShowDemoWindow();

        __properties();
        __resource_manager();
    }

    void HomeLayer::close()
    {}

    void HomeLayer::update()
    {
        static bool no_titlebar = false;
        static bool no_scrollbar = false;
        static bool no_menu = false;
        static bool no_move = false;
        static bool no_resize = false;
        static bool no_collapse = false;
        static bool no_close = false;
        static bool no_nav = false;
        static bool no_background = false;
        static bool no_bring_to_front = false;
        static bool no_docking = false;

        ImGuiWindowFlags window_flags = 0;
        if (no_titlebar) window_flags |= ImGuiWindowFlags_NoTitleBar;
        if (no_scrollbar) window_flags |= ImGuiWindowFlags_NoScrollbar;
        if (!no_menu) window_flags |= ImGuiWindowFlags_MenuBar;
        if (no_move) window_flags |= ImGuiWindowFlags_NoMove;
        if (no_resize) window_flags |= ImGuiWindowFlags_NoResize;
        if (no_collapse) window_flags |= ImGuiWindowFlags_NoCollapse;
        if (no_nav) window_flags |= ImGuiWindowFlags_NoNav;
        if (no_background) window_flags |= ImGuiWindowFlags_NoBackground;
        if (no_bring_to_front) window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus;
        if (no_docking) window_flags |= ImGuiWindowFlags_NoDocking;
    }

    void HomeLayer::event(Event &)
    {}

}
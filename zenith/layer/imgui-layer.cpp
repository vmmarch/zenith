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
#include "imgui-layer.h"
#include "init/starter.h"

namespace zenith
{

    ImGuiLayer::ImGuiLayer()
    {
        initialize();
    }

    void ImGuiLayer::initialize()
    {
        // Setup Dear ImGui context
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO &io = ImGui::GetIO();
        (void) io;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls
        //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking
        io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;         // Enable Multi-Viewport / Platform Windows
        //io.ConfigViewportsNoAutoMerge = true;
        //io.ConfigViewportsNoTaskBarIcon = true;

        v_font font;
        font.name = "宋体";
        font.size = 16.0f;
        font.ttf = "../assets/font/simsun.ttc";
        add_font(font);
        apply_font(font.name);

        // Setup Dear ImGui style
        ImGui::StyleColorsDark();

        // When viewports are enabled we tweak WindowRounding/WindowBg so platform windows can look identical to regular ones.
        ImGuiStyle &style = ImGui::GetStyle();
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            style.WindowRounding = 0.0f;
            style.Colors[ImGuiCol_WindowBg].w = 1.0f;
        }

        Starter &starter = Starter::get_instance();
        GLFWwindow *window = static_cast<GLFWwindow *>(starter.get_window().get_handle());

        // Setup Platform/Renderer bindings
        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init("#version 410");
    }

    void ImGuiLayer::add_font(v_font font)
    {
        ImGuiIO &io = ImGui::GetIO();
        (void) io;
        font_libs[font.name] = io.Fonts->AddFontFromFileTTF(font.ttf, font.size, NULL, io.Fonts->GetGlyphRangesChineseFull());
    }

    void ImGuiLayer::apply_font(v_cc name)
    {
        if (font_libs.count(name) == 0)
        {
            ZENITH_ERROR(__CANNOT_READ_FONT__);
        } else
        {
            ImFont *font = font_libs.at(name);
            ImGuiIO &io = ImGui::GetIO(); (void) io;
            io.FontDefault = font;
        }
    }

    void ImGuiLayer::begin()
    {
        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
    }

    void ImGuiLayer::end()
    {
        ImGuiIO &io = ImGui::GetIO();
        Starter &starter = Starter::get_instance();
        io.DisplaySize = ImVec2((float) starter.get_window().get_width(), (float) starter.get_window().get_height());

        // Rendering
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            GLFWwindow *backup_current_context = glfwGetCurrentContext();
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
            glfwMakeContextCurrent(backup_current_context);
        }
    }

    void ImGuiLayer::close()
    {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
    }

}
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

/*! ===> Creates on 2021/3/27. <=== */

/*!
 * @author orvals
 */
#include "viewport.h"

/*! /////////////////////////////////////////////////////////////////////// */
/*! class: viewport_state_manager */
void state_manager::render(component *_comp)
{
    _comp->vrender();
}

/*! /////////////////////////////////////////////////////////////////////// */
/*! class: viewport */
__viewport__::__viewport__(int width, int height) : ImGUILayout(width, height)
{
    SETUP_GLFW();
}

__viewport__::~__viewport__()
{
    delete this->comps;
}

state_manager *__viewport__::get_state_manager()
{
    if (state_m == NULL)
        this->state_m = new state_manager();

    return this->state_m;
}

zenith::comps_cntr *__viewport__::get_component_container()
{
    return this->comps;
}

GLFWwindow *__viewport__::get_window()
{
    if (this->kWindowHandle == nullptr)
        ZENITH_LOGGER_ERROR("this->kWindowHandle = %s", this->kWindowHandle);

    return this->kWindowHandle;
}

void __viewport__::Display(func_custom_glfw  __CUSTOM_GLFW__,
                           func_custom_iface __CUSTOM_IFACE__,
                           func_render_iface __RENDER_IFACE__)
{

    __CUSTOM_GLFW__(this->kWindowHandle);

    ImGuiIO &io = SETUP_IMGUI();
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    comps->imGuiIO = &io;
    __CUSTOM_IFACE__(this->comps);
    /*! /////////////////////////////////////////////////////////////////////////////// */
    /*! main loop */

    while (!glfwWindowShouldClose(this->kWindowHandle))
    {
        // Poll and handle events (inputs, window resize, etc.)
        // You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
        // - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application.
        // - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application.
        // Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
        glfwPollEvents();

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        __RENDER_IFACE__(this->state_m, comps);

        // Rendering
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(this->kWindowHandle, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w,
                     clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        // Update and Render additional Platform Windows.
        // (Platform functions may change the current OpenGL context, so we save/restore it to make it easier to paste this code elsewhere.
        //  For this specific demo app we could also call glfwMakeContextCurrent(window) directly)
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            GLFWwindow *backup_current_context = glfwGetCurrentContext();
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
            glfwMakeContextCurrent(backup_current_context);
        }

        glfwSwapBuffers(this->kWindowHandle);
    }

    /*! main loop */
    /*! /////////////////////////////////////////////////////////////////////////////// */

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(kWindowHandle);
    glfwTerminate();
}
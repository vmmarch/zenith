#include "child-window.h"

/*! /////////////////////////////////////////////////////////////////////// */
/*! class: viewport_state_manager */
void state_manager::render(component* _comp)
{
     _comp->vrender();
}

/*! /////////////////////////////////////////////////////////////////////// */
/*! class: viewport */
child_window::child_window(int width, int height) : ImGUILayout(width, height)
{
    setup_glfw();
}

child_window::~child_window()
{
    delete this->_comps;
}

state_manager *child_window::get_state_manager()
{
    if(vsm == NULL)
        this->vsm = new state_manager();

    return this->vsm;
}

comps_container *child_window::get_component_container()
{
    return this->_comps;
}

GLFWwindow* child_window::get_window()
{
    if(this->kWindowHandle == nullptr)
        ZENITH_LOGGER_ERROR("this->kWindowHandle = %s", this->kWindowHandle);

    return this->kWindowHandle;
}

void child_window::Display(func_custom_iface __custom_iface__, func_render_iface __render_iface__)
{
    ImGuiIO &io = setup_imgui();
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    __custom_iface__(get_component_container());

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

        __render_iface__(this->get_state_manager(), _comps);

        // Rendering
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(this->kWindowHandle, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
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
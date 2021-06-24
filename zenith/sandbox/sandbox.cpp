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

/*! ===> Creates on 2021/4/23. <=== */

/*!
 * @author 2B键盘
 */
#include "sandbox.h"
#include "settings.h"
#include "layer/editor-layer.h"
#include "example/example-layer.h"
#include "event/mouse-event.h"
#include "state.h"
#include "init/starter.h"

#include "light/point-light.h"

static bool first = true;

SandBox::SandBox(Window *window)
        : Layer("sandbox layer"), camera(Camera()), window(window)
{
    main_layer = new ExampleLayer();

    this->imgui_layer = new ImGuiLayer();
    layer_stack.push(new HomeLayer());
    layer_stack.push(new EditorLayer());

    shader_manager = new ShaderManager();
    shader_manager->load_shaders("../shader");
}

void SandBox::initialize()
{

    // 点光源
    light = new PointLight(glm::vec3(2.0f));

    Shader *shader = shader_manager->get_shader("core");

    choose_model = new Model(
            MODEL_POSITION,
            new Material(MATER_AMBIENT, MATER_DIFFUSE, MATER_SPECULAR, MATER_DIFFUSE_TEX, MATER_SPECULAR_TEX),
            new Texture(R"(C:\Users\Mi\Documents\models\mandalorian\texture.png)"),
            new Texture(R"(C:\Users\Mi\Documents\models\mandalorian\2.png)"),
            R"(C:\Users\Mi\Documents\models\mandalorian\Mandalorian.obj)"
    );
    Renderer::submit(choose_model, shader);

}

void SandBox::update(DeltaTime delta_time)
{
    // ----------------------------------
    // ------
    // reload settings
    reload_setting();

    camera.set_move_speed(get_float(KEY_CAMERA_MOVE_SPEED));
    camera.update((float) State::get_width(), (float) State::get_height(), delta_time);

    // 关闭窗口
    if(Input::pressed(ZENITH_KEY_ESCAPE))
    {
        Starter::instance().close();
        abort();
    }

    // 禁止鼠标移动相机
    if (Input::pressed(ZENITH_KEY_LEFTCONTROL, ZENITH_KEY_LEFTSHIFT, ZENITH_KEY_C))
    {
        set_value(KEY_CAMERA_MOVE_SPEED, get_float(KEY_CAMERA_MOVE_SPEED) + 1.0f);
    }

    // 增加相机速度
    if (Input::pressed(ZENITH_KEY_PAGEUP))
    {
        set_value(KEY_CAMERA_MOVE_SPEED, get_float(KEY_CAMERA_MOVE_SPEED) + 1.0f);
    }

    if (Input::pressed(ZENITH_KEY_PAGEDOWN))
    {
        set_value(KEY_CAMERA_MOVE_SPEED, get_float(KEY_CAMERA_MOVE_SPEED) - 1.0f);
    }

    if(Input::pressed(ZENITH_KEY_HOME))
    {
        choose_model->scale_up(glm::vec3(0.1f));
    }

    if(Input::pressed(ZENITH_KEY_END))
    {
        choose_model->scale_down( glm::vec3(0.1f));
    }

    // 隐藏鼠标
    else if (Input::pressed(ZENITH_KEY_LEFTCONTROL, ZENITH_KEY_C))
    {
        if (!cursor_hide)
            glfwSetInputMode(window->get_glfw_window(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        else
            glfwSetInputMode(window->get_glfw_window(), GLFW_CURSOR, GLFW_CURSOR_NORMAL);
        cursor_hide = !cursor_hide;
    }

    main_layer->update(delta_time);
    layer_stack.update(delta_time);
}

void SandBox::render()
{
    Renderer::begin(camera, light);
    Renderer::clear();

#ifndef __ZENITH_PLATFORM_MACOS__
    imgui_layer->begin();
    {
        layer_stack.render();
    }
    imgui_layer->end();
#endif

    // 渲染模型
    Renderer::draw_models();
}

void SandBox::event(Event &e)
{
    if (e.GetEventType() == event::type::EVENT_MOUSE_MOVED)
    {
        if (!get_bool(KEY_CURSOR_MOVE_CAMER)) return;
        auto &event = dynamic_cast<MouseMovedEvent &>(e);

        float xpos = event.GetX();
        float ypos = event.GetY();

        if (first)
        {
            last_x = xpos;
            last_y = ypos;

            first = false;
        }

        float xoffset = xpos - last_x;
        float yoffset = last_y - ypos;

        last_x = xpos;
        last_y = ypos;

        camera.perspective(xoffset, yoffset);
    }

    if (e.GetEventType() == event::type::EVENT_MOUSE_SCROLLED)
    {
        auto &event = dynamic_cast<MouseButtonScrolledEvent &>(e);
        camera.SetZoom(event.GetY());
    }
}

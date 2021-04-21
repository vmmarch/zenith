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

/*! ===> Creates on 2021/4/6. <=== */

/*!
 * @author 2B键盘
 */
#include "starter.h"
#include "render/renderer.h"
#include "layer/home-layer.h"
#include "layer/editor-layer.h"
#include "render/shader/shader.h"
#include "buf/vertex-buf.h"

namespace zenith
{
    Starter *Starter::instance = nullptr;

    Starter::Starter()
    {
        instance = this;
    }

    Starter::~Starter()
    {
        delete &window;
    }

    void Starter::init_window(v_cc title, int width, int height)
    {
        v_winprops winprops(title, width, height);
        this->window = Window::__create(winprops);
        this->window->set_event_callback(ZENITH_BIND_EVENT_FN(Starter::event));

        this->imlayer = new ImGuiLayer();

        layer_stack.push(new HomeLayer());
    }

    void Starter::close()
    {
        this->window->close_window();
    }

    void Starter::event(Event &event)
    {
        event::type type = event.get_event_type();
        if (type == event::type::EVENT_WINDOW_CLOSE)
            close();
    }

    void Starter::update()
    {
    }

    void Starter::start_engine()
    {

        v_scope<Renderer> renderer = Renderer::__create();
        renderer->clear_color(color::BLACK);

        float last_frame_time = 0.0f;
        int render_count = 0;

        // ----------------------------------------
        // 画三角形
        unsigned int verbuf, verarr, verindex;

        glGenVertexArrays(1, &verarr);
        glBindVertexArray(verarr);

        glGenBuffers(1, &verbuf);
        glBindBuffer(GL_ARRAY_BUFFER, verbuf);

        glGenBuffers(1, &verindex);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, verindex);

        float vertices[] = {
                -0.5f, -0.5f, 0.0f,
                0.5f, -0.5f, 0.0f,
                0.0f, 0.5f, 0.0f,
        };
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        unsigned int indices[] = { 0, 1, 2 };
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), NULL);

        while (running)
        {
            float time = (float) glfwGetTime();
            float timestep = time - last_frame_time;
            last_frame_time = timestep;

            renderer->clear();

            layer_stack.update();
            imlayer->begin();
            {
                layer_stack.render();
            }
            imlayer->end();

            // ----------------------------------------------------
            // GL render from there.
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);

            this->window->update();
        }
    }

}
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
#include "buf/buf.h"

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
        this->window->__event_callback(ZENITH_BIND_EVENT_FN(Starter::event));

        this->imlayer = new ImGuiLayer();

        layer_stack.push(new HomeLayer());
    }

    void Starter::close()
    {
        this->running = false;
        this->window->close_window();
    }

    void Starter::event(Event &event)
    {
        event::type type = event.__event_type();
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

        v_scope<Shader> shader = Shader::__create("../sh/shader-vfs");

        // ----------------------------------------
        // 画三角形
        float vertices[] = {
                -0.5f, -0.5f, 0.0f,    0.0, 1.0, 0.0, 1.0,
                0.5f, -0.5f, 0.0f,     1.0, 1.0, 0.0, 1.0,
                0.0f, 0.5f, 0.0f,      1.0, 0.0, 1.0, 1.0
        };
        std::unique_ptr<VertexBuf> vertex_buf;
        vertex_buf.reset(VertexBuf::__create(vertices, sizeof(vertices)));

        layout_t layout = {
                { "position", shader_t::FLOAT3 },
                { "color", shader_t::FLOAT4 }
        };

        v_ui32 index = 0;
        for(const auto& element : layout)
        {
            glEnableVertexAttribArray(index);
            glVertexAttribPointer(index, element.__size(), element.__type(),
                                  element.normalized ? GL_TRUE : GL_FALSE,
                                  layout.__stride(),
                                  (const void*) element.offset);
            index++;
        }

        unsigned int indices[] = { 0, 1, 2 };
        std::unique_ptr<IndexBuf> index_buf;
        index_buf.reset(IndexBuf::__create(indices, sizeof(indices) / sizeof(v_ui1)));

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
            shader->bind();
            GLAPI_DrawIndexTriangles(index_buf->size(), GL_UNSIGNED_INT);
            this->window->update();
        }
    }

}
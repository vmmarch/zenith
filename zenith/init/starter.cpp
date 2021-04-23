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
#include "render/graphics-context.h"

namespace zenith
{
    Starter *Starter::instance = nullptr;

    Starter::Starter(v_cc title, int width, int height)
    {
        instance = this;
        init_window(title, width, height);

        sandbox = new SandBox();
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
        {
            close();
            return;
        }

        sandbox->event(event);
    }

    void Starter::update()
    {
        sandbox->update();
    }

    void Starter::start_engine()
    {
        sandbox->clear_color(color::BLACK);

        v_scope<Shader> shader = Shader::__create("../sh/shader-vfs");

        // ----------------------------------------
        // 画三角形
        std::shared_ptr<VertexArray> vertexArray;
        vertexArray.reset(VertexArray::__create());

        float vertices[] = {
                -0.5f, -0.5f, 0.0f,
                0.5f, -0.5f, 0.0f,
                0.0f, 0.5f, 0.0f
        };
        std::shared_ptr<VertexBuffer> vbuf;
        vbuf.reset(VertexBuffer::__create(vertices, sizeof(vertices)));

        layout_t layout = {
                {"position", shader_t::FLOAT3},
        };
        vbuf->__layout(layout);
        vertexArray->add_vertex_buf(vbuf);

        // ------------------------------------------
        // set index
        unsigned int indices[] = { 0, 1, 2 };
        vertexArray->__index_buffer(indices, sizeof(indices) / ZENITH_UNSIGNED_INT);

        RenderModel model(vertexArray, std::move(shader));

        // 提交渲染模型
        sandbox->submit(model);
        GraphicsContext::instance()->__curr_model(model);

        // ------------------------------------------
        // game loop.
        while (running)
        {
            update();
            sandbox->render();
            this->window->update();
        }
    }

}
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

/*! ===> Creates on 2021/4/7. <=== */

/*!
 * @author 2B键盘
 */
#include "opengl-renderer.h"

namespace zenith
{

    void OpenGLRenderer::__clear_color(const glm::vec4& color)
    {
        glClearColor(color.r, color.g, color.b, color.a);
    }

    void OpenGLRenderer::clear()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void OpenGLRenderer::disable_depth_test()
    {
        GLAPI_DisableDepthTest();
    }

    void OpenGLRenderer::enable_depth_test()
    {
        GLAPI_EnableDepthTest();
    }

    void OpenGLRenderer::draw_vertex_array(const RenderModel& model)
    {
        model.state_modify();
        model.__shader()->bind();
        draw_vertex_array(*model.__vertex_array());
    }

    void OpenGLRenderer::draw_vertex_array(const VertexArray& vertex)
    {
        vertex.bind();
        GLAPI_DrawIndexTriangles(vertex.__index_buffer()->size(), GL_UNSIGNED_INT);
    }

    void OpenGLRenderer::draw_vertex_array(const std::vector<VertexArray>& vertex_arrays)
    {
        for (auto &vertex : vertex_arrays)
        {
            draw_vertex_array(vertex);
        }
    }

}
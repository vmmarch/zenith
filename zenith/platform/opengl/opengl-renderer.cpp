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

#define U_VIEW_PROJECTION_MATRIX "u_viewProjectionMatrix"

namespace zenith
{

    void OpenGLRenderer::clear_color(const glm::vec4& color)
    {
        glClearColor(color.r, color.g, color.b, color.a);
    }

    void OpenGLRenderer::clear()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void OpenGLRenderer::begin(Camera &camera)
    {
        view_matrix = camera.GetViewMatrix();
        projection = glm::perspective(camera.GetCameraZoom(), camera.GetScreenAspectRadio(), -1.0f, 1.0f);
    }

    void OpenGLRenderer::disable_depth_test()
    {
        GLAPI_DisableDepthTest();
    }

    void OpenGLRenderer::enable_depth_test()
    {
        GLAPI_EnableDepthTest();
    }

    void OpenGLRenderer::draw_render_models()
    {
        for(auto& model : models)
            draw_render_model(model);
    }

    void OpenGLRenderer::draw_render_model(RenderModel& model)
    {
        zenith_shared<Shader> shader = model.GetShader();
        shader->bind();

        glm::mat4 modloc = glm::mat4(1.0f);
        modloc = glm::translate(modloc, model.GetLocation());

        model.GetShader()->setMat4("u_model_location", modloc);
        model.GetShader()->setMat4("u_projection", projection);
        model.GetShader()->setMat4("u_view_matrix", view_matrix);

        if(model.GetMod() == drawmod::INDEX)
        {
            draw_indexed(*model.GetVertexArray());
        } else
        {
            draw_array(*model.GetVertexArray());
        }
    }

    void OpenGLRenderer::draw_array(const VertexArray &vertex)
    {
        vertex.bind();
        for(auto& array : vertex.__vertex_buffers())
        {
            GLAPI_DrawArrays(0, array->GetVertexSize());
        }
    }

    void OpenGLRenderer::draw_array(const std::vector<VertexArray>& vertex_arrays)
    {
        for (auto &vertex : vertex_arrays)
            draw_array(vertex);
    }

    void OpenGLRenderer::draw_indexed(const VertexArray& vertex)
    {
        vertex.bind();
        GLAPI_DrawIndex(vertex.__index_buffer()->size(), GL_UNSIGNED_INT);
    }

    void OpenGLRenderer::draw_indexed(const std::vector<VertexArray>& vertex_arrays)
    {
        for (auto &vertex : vertex_arrays)
            draw_indexed(vertex);
    }

}
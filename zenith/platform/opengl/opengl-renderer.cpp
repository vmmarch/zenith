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

    void OpenGLRenderer::DrawObjects()
    {
        for(auto& object : objects)
            DrawObject(object);
    }

    void OpenGLRenderer::DrawObject(RenderObject& object)
    {
        object.update(projection, view_matrix);

        if(object.GetMod() == DrawMode::INDEX)
        {
            DrawIndex(*object.GetVertexArray());
        } else
        {
            DrawArray(*object.GetVertexArray());
        }
    }

    void OpenGLRenderer::DrawArray(const VertexArray &vertex)
    {
        vertex.bind();
        for(auto& array : vertex.GetVertexBuffers())
            GLAPI_DrawTriangleArrays(0, array->GetVertexSize());
    }

    void OpenGLRenderer::DrawArray(const std::vector<VertexArray>& vertex_arrays)
    {
        for (auto &vertex : vertex_arrays)
            DrawArray(vertex);
    }

    void OpenGLRenderer::DrawIndex(const VertexArray& vertex)
    {
        vertex.bind();
        GLAPI_DrawTriangleIndex(vertex.GetIndexBuffer()->size(), GL_UNSIGNED_INT);
    }

    void OpenGLRenderer::DrawIndex(const std::vector<VertexArray>& vertex_arrays)
    {
        for (auto &vertex : vertex_arrays)
            DrawIndex(vertex);
    }

    void OpenGLRenderer::DrawLines(RenderObject &object)
    {
        object.update(projection, view_matrix);

        VertexArray* vertex = object.GetVertexArray();
        vertex->bind();

        if(object.GetMod() == DrawMode::INDEX)
        {
            GLAPI_DrawLineIndex(vertex->GetIndexBuffer()->size(), GL_UNSIGNED_INT);
        } else
        {
            for (auto &buffer : vertex->GetVertexBuffers())
            {
                buffer->bind();
                GLAPI_DrawLineArrays(0, buffer->GetBufferSize());
            }
        }
    }

}
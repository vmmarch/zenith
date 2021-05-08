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
        projection = camera.GetProjection();
    }

    void OpenGLRenderer::disable_depth_test()
    {
        GLAPI_DisableDepthTest();
    }

    void OpenGLRenderer::enable_depth_test()
    {
        GLAPI_EnableDepthTest();
    }

    void OpenGLRenderer::DrawMeshs()
    {
        for(auto& mesh : meshs)
            DrawMesh(mesh);
    }

    void OpenGLRenderer::DrawMesh(Mesh& mesh)
    {
        mesh.update(projection, view_matrix);

        GLenum mode;
        switch (mesh.GetRenderMode())
        {
            case ZENITH_TRIANGLES: mode = GL_TRIANGLES; break;
            case ZENITH_LINES: mode = GL_LINES; break;
            case ZENITH_TRIANGLE_FAN: mode = GL_TRIANGLE_FAN; break;
        }

        if (mesh.GetVertexArray()->HasIndex() == true)
            DrawIndex(mode, *mesh.GetVertexArray());
        else
            DrawArray(mode, *mesh.GetVertexArray());
    }

    void OpenGLRenderer::DrawArray(GLenum mode, const VertexArray &vertex)
    {
        vertex.bind();
        for(auto& array : vertex.GetVertexBuffers())
        {
            GLAPI_DrawArray(mode, 0, array->GetVertexSize());
        }
    }

    void OpenGLRenderer::DrawIndex(GLenum mode, const VertexArray& vertex)
    {
        vertex.bind();
        GLAPI_DrawIndex(mode, vertex.GetIndexBuffer()->size(), GL_UNSIGNED_INT);
    }

}
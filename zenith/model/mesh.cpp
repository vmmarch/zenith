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

/*! ===> Creates on 2021/6/3. <=== */

/*!
 * @author 2B键盘
 */
#include "mesh.h"

namespace zenith
{
    Mesh::Mesh(vertex_t*   vertices,
               GLuint      vsize,
               GLuint*     indices,
               GLuint      isize,
               glm::vec3   position,
               glm::vec3   origin,
               glm::vec3   rotation,
               glm::vec3   scale)
    {
        this->position = position;
        this->rotation = rotation;
        this->scale    = scale;
        this->origin   = origin;

        this->vertices          = vertices;
        this->vertices_size     = vsize;

        this->indices           = indices;
        this->indices_size      = isize;

        setup_mesh();
        update_matrix();
    }

    Mesh::~Mesh()
    {
        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);

        if(indices_size > 0)
            glDeleteBuffers(1, &EBO);

        // delete[] vertices;
        // delete[] indices;
    }

    void Mesh::setup_mesh()
    {
        GLAPI_CreateAndBindVertexArray(VAO);
        GLAPI_CreateArrayBuffer(VBO, vertices_size * sizeof(vertex_t), vertices, GL_STATIC_DRAW);

        if(indices_size > 0)
            GLAPI_CreateIndexBuffer(EBO, indices_size * sizeof(GLuint), indices);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertex_t), (void*) offsetof(vertex_t, position));
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(vertex_t), (void*) offsetof(vertex_t, color));
        glEnableVertexAttribArray(1);

        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(vertex_t), (void*) offsetof(vertex_t, texcoord));
        glEnableVertexAttribArray(2);

        glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(vertex_t), (void*) offsetof(vertex_t, normal));
        glEnableVertexAttribArray(3);

        glBindVertexArray(0);
    }

    void Mesh::update_matrix()
    {
        this->matrix = glm::mat4(1.f);
        this->matrix = glm::translate(this->matrix, this->origin);
        this->matrix = glm::rotate(this->matrix, glm::radians(this->rotation.x), glm::vec3(1.f, 0.f, 0.f));
        this->matrix = glm::rotate(this->matrix, glm::radians(this->rotation.y), glm::vec3(0.f, 1.f, 0.f));
        this->matrix = glm::rotate(this->matrix, glm::radians(this->rotation.z), glm::vec3(0.f, 0.f, 1.f));
        this->matrix = glm::translate(this->matrix, this->position - this->origin);
        this->matrix = glm::scale(this->matrix, this->scale);
    }

    void Mesh::set_matrix(ShaderProgram* shader)
    {
        shader->set_mat4("matrix", matrix);
    }

    void Mesh::set_position(const glm::vec3 position)
    {
        this->position = position;
    }

    void Mesh::set_rotation(const glm::vec3 rotation)
    {
        this->rotation = rotation;
    }

    void Mesh::set_origin(const glm::vec3 origin)
    {
        this->origin = origin;
    }

    void Mesh::set_scale(const glm::vec3 scale)
    {
        this->scale = scale;
    }

    void Mesh::move(glm::vec3 position)
    {
        this->position += position;
    }

    void Mesh::rotate(glm::vec3 rotation)
    {
        this->rotation += rotation;
    }

    void Mesh::scale_up(glm::vec3 scale)
    {
        this->scale += scale;
    }

    void Mesh::draw(ShaderProgram* shader)
    {
        update_matrix();
        set_matrix(shader);

        glBindVertexArray(VAO);

        if(indices_size > 0)
        {
            GLAPI_DrawTriangleArrays(0, vertices_size);
        }
        else
        {
            GLAPI_DrawIndex(GL_TRIANGLES, indices_size, GL_UNSIGNED_INT);
        }

        glBindVertexArray(0);
        glUseProgram(0);
        glActiveTexture(0);
        glBindTexture(GL_TEXTURE_2D, 0);

    }

}
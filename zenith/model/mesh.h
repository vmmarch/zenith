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
#pragma once

#include "shader.h"
#include "vertex.h"

#include <glfw-api.h>


class Mesh
{

public:
    Mesh(vertex_t *vertices,
         GLuint vsize,
         GLuint *indices,
         GLuint isize,
         glm::vec3 position = glm::vec3(0.f),
         glm::vec3 rotation = glm::vec3(0.f),
         glm::vec3 scale = glm::vec3(0.1f),
         glm::vec3 origin = glm::vec3(0.f)
    );

    ~Mesh();

    void set_scale(glm::vec3 scale);

    void set_origin(glm::vec3 origin);

    void set_position(glm::vec3 position);

    void set_rotation(glm::vec3 rotation);

    void move(glm::vec3 position);

    void rotate(glm::vec3 rotation);

    void draw(Shader *shader);

private:
    void setup_mesh();

    void update_matrix();

    void set_matrix(Shader *shader);

private:
    vertex_t *vertices;
    GLuint vertices_size;

    GLuint *indices;
    GLuint indices_size;

    GLuint VAO;
    GLuint VBO;
    GLuint EBO;

    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;
    glm::vec3 origin;

    glm::mat4 matrix;

};

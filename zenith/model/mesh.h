#pragma once

#include "shader.h"
#include "vertex.h"

#include <glfw-api.h>

namespace zenith
{
    class Mesh
    {

    public:
        Mesh(vertex_t*   vertices,
             GLuint      vsize,
             GLuint*     indices,
             GLuint      isize,
             glm::vec3   position = glm::vec3(0.f),
             glm::vec3   rotation = glm::vec3(0.f),
             glm::vec3   scale    = glm::vec3(1.f),
             glm::vec3   origin   = glm::vec3(0.f)
        );

        ~Mesh();

        void set_scale(glm::vec3 scale);
        void set_origin(glm::vec3 origin);
        void set_position(glm::vec3 position);
        void set_rotation(glm::vec3 rotation);

        void move(glm::vec3 position);
        void rotate(glm::vec3 rotation);
        void scale_up(glm::vec3 scale);

    private:
        void setup_mesh();
        void update_matrix();
        void update_uniform(ShaderProgram* shader);

    private:
        vertex_t* vertices;
        GLuint    vertices_size;

        GLuint*   indices;
        GLuint    indices_size;

        GLuint    VAO;
        GLuint    VBO;
        GLuint    EBO;

        glm::vec3 position;
        glm::vec3 rotation;
        glm::vec3 scale;
        glm::vec3 origin;

        glm::mat4 matrix;

    };
}
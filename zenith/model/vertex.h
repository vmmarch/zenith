#pragma once

#include<glm-api.h>

namespace zenith
{
    struct vertex_t
    {
        glm::vec3 position;
        glm::vec3 color;
        glm::vec2 texcoord;
        glm::vec3 normal;
    };
}
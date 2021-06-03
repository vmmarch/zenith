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

/*! ===> Creates on 2021/6/2. <=== */

/*!
 * @author 2B键盘
 */
#ifndef ZENITH_MODEL_LOADER_H
#define ZENITH_MODEL_LOADER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <glfw-api.h>
#include <zenith/glob.h>
#include <zenith/type.h>

#include "model.h"
#include "vertex.h"

namespace zenith
{

    /**
     * 加载Obj模型
     * @param path 模型路径
     */
    static std::vector<vertex_t> load_obj(const char* path)
    {
        std::ifstream file(path);
        if(!file.is_open())
            ZENITH_ERROR(CANNOT_OPEN_FILE, path);

        std::vector<vertex_t> vertices;

        std::vector<glm::vec3> positions;
        std::vector<glm::vec2> texcoords;
        std::vector<glm::vec3> normals;

        std::vector<GLint> texcoord_indices;
        std::vector<GLint> normals_indices;
        std::vector<zenith_uint> positions_indices;

        std::string line;
        std::string prefix;
        std::stringstream stream;

        glm::vec3 temp_vec3;
        glm::vec2 temp_vec2;
        int       temp_int = 0;

        while(std::getline(file, line))
        {
            stream.clear();
            stream.str(line);
            stream >> prefix;

            if(prefix == "v")
            {
                stream >> temp_vec3.x >> temp_vec3.y >> temp_vec3.z;
                positions.push_back(temp_vec3);
                continue;
            }

            if(prefix == "vn")
            {
                stream >> temp_vec3.x >> temp_vec3.y >> temp_vec3.z;
                normals.push_back(temp_vec3);
                continue;
            }

            if(prefix == "vt")
            {
                stream >> temp_vec2.x >> temp_vec2.y;
                texcoords.push_back(temp_vec2);
                continue;
            }

            if(prefix == "f")
            {
                int count = 0;
                while(stream >> temp_int)
                {
                    if(count == 0)
                        positions_indices.push_back(temp_int);
                    else if(count == 1)
                        texcoord_indices.push_back(temp_int);
                    else if(count == 2)
                        normals_indices.push_back(temp_int);

                    if(stream.peek() == '/')
                    {
                        stream.ignore(1, '/');
                        count++;
                    }
                    else if (stream.peek() == ' ')
                    {
                        stream.ignore(1, ' ');
                        count++;
                    }

                    if(count > 2)
                        count = 0;

                }
                continue;
            }

            if(prefix == "o")
            {
                continue;
            }

            if(prefix == "use_mtl")
            {

            }

            if(prefix == "s")
            {
                continue;
            }
        }

        // Building Mesh.
        vertices.resize(positions_indices.size(), vertex_t());

        for(size_t i = 0; i < positions_indices.size(); i++)
        {
            vertices[i].position     = positions[positions_indices[i] - 1];
            vertices[i].normal       = normals[normals_indices[i] - 1];
            vertices[i].texcoord     = texcoords[texcoord_indices[i] - 1];
            vertices[i].color        = glm::vec3(1.f, 1.f, 1.f);
        }

        return vertices;
    }

}

#endif // ==> ZENITH_OBJ_H <===

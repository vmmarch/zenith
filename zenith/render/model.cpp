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

/*! ===> Creates on 2021/5/9. <=== */

/*!
 * @author 2B键盘
 */
#include "model.h"

#include <fast-obj.h>

namespace zenith
{
    void Model::draw(ShaderProgram &shader)
    {
        for(auto mesh : meshes)
            mesh.draw(shader);
    }

    void Model::load_model(zenith_char path, zenith_enum mt)
    {
        if(mt == ZENITH_MODEL_OBJ)          {
            parse_obj(path); return;        }
    }

    void Model::parse_obj(zenith_char path)
    {
        fastObjMesh *mesh = fast_obj_read(path);
        int t_offset = 0;
        int v_offset = 0;

        std::vector<vertex_t> vertices;
        std::vector<unsigned int> indices;

        for(int i = 0; i < mesh->position_count; i++)
        {
            vertex_t vertex;
            vertex.position = { mesh->positions[v_offset], mesh->positions[(v_offset + 1)], mesh->positions[(v_offset + 2)] };
            vertex.tex_coords = { mesh->texcoords[t_offset], mesh->texcoords[(t_offset + 1)]};
            vertex.normal = { mesh->normals[v_offset], mesh->normals[(v_offset + 1)], mesh->normals[(v_offset + 2)] };

            v_offset += 3;
            t_offset += 3;

            vertices.push_back(vertex);
        }

        fast_obj_destroy(mesh);
    }
}
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
#include "_config.h"

#include <utility>

Model::Model(glm::vec3 position, Material *material, Texture *or_tex_diff, Texture *or_tex_spec,
             std::vector<Mesh *> _meshs) : meshs(std::move(_meshs))
{
    init(position, material, or_tex_diff, or_tex_spec);
}

Model::Model(glm::vec3 position, Material *material, Texture *or_tex_diff, Texture *or_tex_spec,
             const char *file)
{
    std::vector<GLuint> indices;
    std::vector<vertex_t> mesh = load_obj(file, indices);
    this->meshs.push_back(new Mesh(mesh.data(), mesh.size(), indices.data(), indices.size(),
                                   glm::vec3(1.f, 0.f, 0.f),
                                   glm::vec3(0.0f),
                                   glm::vec3(0.0f),
                                   glm::vec3(1.f))
    );

    init(position, material, or_tex_diff, or_tex_spec);
}

void Model::init(glm::vec3 position, Material *material, Texture *or_tex_diff, Texture *or_tex_spec)
{
    this->position = position;
    this->material = material;
    this->override_texture_diffuse = or_tex_diff;
    this->override_texture_specular = or_tex_spec;
    this->scale = glm::vec3(MODEL_SCALE);

    for (auto &item : meshs)
    {
        item->move(this->position);
        item->set_origin(this->position);
    }

}

void Model::rotate(glm::vec3 rotation)
{
    for (auto &item : meshs)
        item->rotate(rotation);
}

void Model::draw(Shader *shader)
{
    this->material->update(shader);

    for (auto &item : meshs)
    {
        override_texture_diffuse->bind(GL_TEXTURE0);
        override_texture_specular->bind(GL_TEXTURE1);

        item->set_scale(scale);
        item->draw(shader);
    }
}

void Model::scale_up(glm::vec3 scale)
{
    this->scale = this->scale + scale;
}

void Model::scale_down(glm::vec3 scale)
{
    this->scale = this->scale - scale;
}

glm::vec3 Model::get_scale()
{
    return this->scale;
}

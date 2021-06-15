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
#pragma once

// if flag eq 5, that means the errors have flag 2 and flag 3;
// or else flag eq 4, that means just have flag 4
#define SUCCESSFUL    0
#define CAUSE_SHADER  2       //  ------|--> 5
#define CAUSE_MODEL   3       //  ------|
#define CAUSE_UNKNOWN 4

#include "loader.h"
#include "material.h"
#include "mesh.h"
#include "texture.h"
#include "virtual/loader.h"
#include "vertex.h"
#include "mesh.h"

#include <vector>

class Model
{
public:
    Model(glm::vec3 position,
          Material *material,
          Texture *or_tex_diff,
          Texture *or_tex_spec,
          std::vector<Mesh *> meshs);

    Model(glm::vec3 position,
          Material *material,
          Texture *or_tex_diff,
          Texture *or_tex_spec,
          const char *file);

    void init(glm::vec3 position,
              Material *material,
              Texture *or_tex_diff,
              Texture *or_tex_spec);

    void rotate(glm::vec3 rotation);

    void scale_up(glm::vec3 scale);
    void scale_down(glm::vec3 scale);

    glm::vec3 get_scale();

    void draw(Shader *shader);

private:
    Material *material;
    Texture *override_texture_diffuse;
    Texture *override_texture_specular;
    std::vector<Mesh *> meshs;
    glm::vec3 position;
    glm::vec3 scale;

};

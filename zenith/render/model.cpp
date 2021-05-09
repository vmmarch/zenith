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
        fastObjMesh *mi = fast_obj_read(path);

        // TODO Loader model.

        fast_obj_destroy(mi);
    }
}
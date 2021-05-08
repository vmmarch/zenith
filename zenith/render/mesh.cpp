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

/*! ===> Creates on 2021/4/22. <=== */

/*!
 * @author 2B键盘
 */
#include "mesh.h"

namespace zenith
{

    void Mesh::SetVertexArray(VertexArray* vertex)
    {
        this->vertex_array = vertex;
    }

    VertexArray* Mesh::GetVertexArray() const
    {
        return this->vertex_array;
    }

    void Mesh::SetShader(ShaderProgram* _shader)
    {
        this->shader = _shader;
    }

    ShaderProgram* Mesh::GetShader()
    {
        return this->shader;
    }

}
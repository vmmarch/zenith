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

    void Mesh::bind()
    {
        GLAPI_CreateVertexArray(vaoid);
        GLAPI_CreateBuffer2(vboid, eboid);

        // 绑定VAO, VBO
        glBindVertexArray(vaoid);
        glBindBuffer(GL_ARRAY_BUFFER, vboid);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(vertex_t), &vertices, GL_STATIC_DRAW);

        // 绑定EBO
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eboid);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(zenith_uint), &indices, GL_STATIC_DRAW);

        // 设置顶点坐标
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*) 0);

        // 设置法向量
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*) 0);

        // 设置贴图
        glEnableVertexAttribArray(2);
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*) 0);

        glBindVertexArray(0);
    }

    void Mesh::draw()
    {
        glBindVertexArray(vaoid);
        GLAPI_DrawIndex(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT);
    }

}
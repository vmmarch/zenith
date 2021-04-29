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
#pragma once

#include "render/shader/shader.h"
#include "buf/vertex-array.h"

#include <zenith/type.h>

#include <utility>

namespace zenith
{

    class RenderObject;

    /**
     * @param [i] RenderObject        渲染对象
     * @param [i] projection_matrix   投影矩阵
     * @param [i] view_matrix         视图矩阵
     */
    typedef void (*zenith_update)(RenderObject&, glm::mat4, glm::mat4);

    /**
     * 渲染封装模型
     */
    class RenderObject
    {
    public:
        RenderObject(VertexArray *vertex, Shader *shader) : vertex_array(vertex), shader(shader)
        {
            render_type = GL_FILL;
            render_type_t = render::type_t::FILL;
        }

        void update(glm::mat4 projection, glm::mat4 view_matrix)
        {
            if(update_p != NULL)
                update_p(*this, projection, view_matrix);
        }

        void SetUpdate(zenith_update update)
        {
            this->update_p = update;
        }

        // vertex array
        void SetVertexArray(VertexArray*);

        [[nodiscard]] VertexArray* GetVertexArray() const;

        // shader
        void SetShader(Shader*);

        [[nodiscard]] Shader* GetShader();

        // 设置渲染类型
        void SetRendertype(render::type_t = render::type_t::FILL);

        [[nodiscard]] render::type_t GetRendertype() const;

        void SetTransform(glm::mat4 transform_ = glm::mat4(1.0f)) { transform = transform_; }

        glm::mat4 GetTransform() { return transform; }

        void SetLocation(glm::vec3 loc) { location = loc; }

        glm::mat4 GetMat4Location()
        {
            glm::mat4 m_location = glm::mat4(1.0f);
            m_location = glm::translate(m_location, GetLocation());
            return m_location;
        }
        glm::vec3 GetLocation() { return location; }

        DrawMode GetMod() const { return vertex_array->GetMod(); }

    private:
        bool modify = false;
        Shader* shader;
        VertexArray* vertex_array;
        render::type_t render_type_t;
        GLenum render_type;

        glm::vec3 location = { 0.0f, 0.0f, 0.0f };
        glm::mat4 transform;

        zenith_update update_p = NULL; // 更新函数
    };
}
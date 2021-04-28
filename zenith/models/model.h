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

    class RenderModel;

    /**
     * 渲染封装模型
     */
    class RenderModel
    {
    public:
        RenderModel() = default;
        RenderModel(zenith_shared<VertexArray> vertex, zenith_shared<Shader> shader)
            : vertex_array(std::move(vertex)), shader(std::move(shader))
            {
                render_type = GL_FILL;
                render_type_t = render::type_t::FILL;
            }

        // vertex array
        void SetVertexArray(zenith_shared<VertexArray>&);

        [[nodiscard]] zenith_shared<VertexArray> GetVertexArray() const;

        // shader
        void SetShader(zenith_shared<Shader>&);

        [[nodiscard]] const zenith_shared<Shader> GetShader() const;

        // 设置渲染类型
        void SetRendertype(render::type_t = render::type_t::FILL);

        [[nodiscard]] render::type_t GetRendertype() const;

        void SetTransform(glm::mat4 transform_ = glm::mat4(1.0f)) { transform = transform_; }

        glm::mat4 GetTransform() { return transform; }

        void SetLocation(glm::vec3 loc) { location = loc; }
        glm::vec3 GetLocation() { return location; }

        drawmod GetMod() const { return vertex_array->GetMod(); }

    private:
        bool modify = false;
        zenith_shared<Shader> shader;
        zenith_shared<VertexArray> vertex_array;
        render::type_t render_type_t;
        GLenum render_type;

        glm::vec3 location = { 0.0f, 0.0f, 0.0f };
        glm::mat4 transform;
    };
}
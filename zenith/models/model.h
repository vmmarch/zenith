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

namespace zenith
{
    /**
     * 渲染封装模型
     */
    class RenderModel
    {
    public:
        RenderModel() {}
        RenderModel(v_shared<VertexArray> vertex, v_shared<Shader> shader)
            : vertex_array(vertex), shader(shader) {}

        // vertex array
         void __vertex_array(v_shared<VertexArray>&);
        v_shared<VertexArray> __vertex_array() const;

        // shader
         void __shader(v_shared<Shader>&);
        const v_shared<Shader> __shader() const;

        // 设置渲染类型
         void __render_type(render::type_t = render::type_t::FILL);
         render::type_t __render_type() const;

        void __transform(glm::mat4 transform_ = glm::mat4(1.0f)) { transform = transform_; }
        glm::mat4 __def_transform() { return transform; }

    private:
        bool modify = false;
        v_shared<Shader> shader;
        v_shared<VertexArray> vertex_array;
        render::type_t render_type_t;
        GLenum render_type = GL_FILL;

        glm::mat4 transform;
    };
}
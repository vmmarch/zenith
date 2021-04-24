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
#include "model.h"

namespace zenith
{

    void RenderModel::__vertex_array(v_shared<VertexArray>& vertex)
    {
        this->vertex_array = vertex;
    }

    v_shared<VertexArray> RenderModel::__vertex_array() const
    {
        return this->vertex_array;
    }

    void RenderModel::__shader(v_shared<Shader>& shader)
    {
        this->shader = shader;
    }

    const v_shared<Shader> RenderModel::__shader() const
    {
        return this->shader;
    }

    void RenderModel::__render_type(render::type_t type)
    {
        if(type == render::type_t::LINE)
        {
            render_type = GL_LINE;
            render_type_t = render::type_t::LINE;
            glPolygonMode(GL_FRONT_AND_BACK, render_type);
        } else
        {
            render_type = GL_FILL;
            render_type_t = render::type_t::FILL;
            glPolygonMode(GL_FRONT_AND_BACK, render_type);
        }
    }

    render::type_t RenderModel::__render_type() const
    {
        return render_type_t;
    }

}
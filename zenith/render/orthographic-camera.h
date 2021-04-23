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

/*! ===> Creates on 2021/4/17. <=== */

/*!
 * 正交投影相机
 * @author 2B键盘
 */
#pragma once

#include <api/glfw-api.h>

namespace zenith
{
    class OrthographicCamera
    {
    public:
        OrthographicCamera(float left, float right, float bottom, float top);

        const glm::vec3& __position() { return this->position; }
        void __position(const glm::vec3& position) { this->position = position; recalculateViewMatrix(); }
        const float __rotation() const { return this->rotation; }
        void __rotation(float rotation) { this->rotation = rotation; recalculateViewMatrix(); }
        const glm::mat4 __projection_matrix() { return this->projection_matrix; }
        const glm::mat4 __view_matrix() { return this->view_matrix; }
        const glm::mat4 __view_projection_matrix() { return this->view_projection_matrix; }
    private:
        glm::mat4 projection_matrix;
        glm::mat4 view_matrix;
        glm::mat4 view_projection_matrix;

        glm::vec3 position = { 0.0f, 0.0f, 0.0f };
        float rotation = 0.0f;

        void recalculateViewMatrix();
    };
}
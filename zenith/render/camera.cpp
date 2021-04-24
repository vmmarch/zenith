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
 * @author 2B键盘
 */
#include "camera.h"

namespace zenith
{
    Camera::Camera(float left, float right, float bottom, float top)
            : projection_matrix(glm::ortho(left, right, bottom, top, -1.0f, 1.0f)), view_matrix(1.0f)
    {
        recalculateViewProjectionMatrix();
    }

    void Camera::__projection(float left, float right, float bottom, float top)
    {
        projection_matrix = glm::ortho(left, right, bottom, top, -1.0f, 1.0f);
        recalculateViewProjectionMatrix();
    }

    void Camera::recalculateViewProjectionMatrix()
    {
        view_projection_matrix = projection_matrix * view_matrix;
    }

    void Camera::recalculateViewMatrix()
    {
        glm::mat4 transform = glm::translate(glm::mat4(1.0f), position) *
                              glm::rotate(glm::mat4(1.0f), glm::radians(rotation), glm::vec3(0, 0, 1));

        view_matrix = glm::inverse(transform);
        recalculateViewProjectionMatrix();
    }
}
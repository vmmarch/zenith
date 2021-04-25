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
    Camera::Camera(glm::vec3 pos, glm::vec3 up, float yaw, float pitch)
        : front(glm::vec3(0.0f, 0.0f, 0.0f)), move_speed(SPEED), camera_zoom(ZOOM)
    {
        this->pos = pos;
        this->worldup = up;
        this->yaw = yaw;
        this->pitch = pitch;

        update_camera_vector();
    }

    void Camera::direction(camera_movement movement)
    {
        float velocity = move_speed * delta_time;
        if(movement == FORWARD)
            pos += front * velocity;
        if(movement == BACKWARD)
            pos -= front * velocity;
        if(movement == LEFT)
            pos -= right * velocity;
        if(movement == RIGHT)
            pos += right * velocity;
    }

    void Camera::perspective(float x, float y, bool constraint_pitch)
    {
        x *= mouse_sens;
        y *= mouse_sens;

        yaw = x;
        pitch = y;

        if(constraint_pitch)
        {
            if(pitch > CONSTRAINT_PITCH) pitch = CONSTRAINT_PITCH;
            if(pitch < -CONSTRAINT_PITCH) pitch = -CONSTRAINT_PITCH;
        }

        update_camera_vector();
    }

    void Camera::zoom(float value)
    {
        if (this->camera_zoom >= 1.0f && this->camera_zoom <= 45.0f)
            this->camera_zoom -= value;
        if (this->camera_zoom <= 1.0f)
            this->camera_zoom = 1.0f;
        if (this->camera_zoom >= 45.0f)
            this->camera_zoom = 45.0f;
    }

    glm::mat4 Camera::__view_matrix()
    {
        return glm::lookAt(pos, (pos + front), up);
    }

    void Camera::update_camera_vector()
    {
        front.x = cos(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));
        front.y = sin(glm::radians(this->pitch));
        front.z = sin(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));

        this->right = glm::normalize(glm::cross(this->front, this->worldup));
        this->up = glm::normalize(glm::cross(this->right, this->front));
    }

    float Camera::__camera_zoom()
    {
        return camera_zoom;;
    }

}
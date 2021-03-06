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

Camera::Camera(glm::vec3 , glm::vec3 up, float yaw, float pitch)
    : front(glm::vec3(0.0f, 0.0f, 0.0f)), move_speed(CAMERA_SPEED), camera_zoom(CAMERA_ZOOM)
{
    this->pos = pos;
    this->worldup = up;
    this->yaw = yaw;
    this->pitch = pitch;
    mouse_sens = CAMERA_MOUSE_SENS;

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

    yaw += x;
    pitch += y;

    if(constraint_pitch)
    {
        if(pitch > CAMERA_CONSTRAINT_PITCH)
            pitch = CAMERA_CONSTRAINT_PITCH;
        if(pitch < -CAMERA_CONSTRAINT_PITCH)
            pitch = -CAMERA_CONSTRAINT_PITCH;
    }

    update_camera_vector();
}

void Camera::SetZoom(float value)
{
    if (this->camera_zoom >= 1.0f && this->camera_zoom <= CAMERA_ZOOM)
        this->camera_zoom -= value;
    if (this->camera_zoom <= 1.0f)
        this->camera_zoom = 1.0f;
    if (this->camera_zoom >= CAMERA_ZOOM)
        this->camera_zoom = CAMERA_ZOOM;
}

glm::mat4 Camera::get_view_matrix()
{
    return glm::lookAt(pos, (pos + front), up);
}

void Camera::update_camera_vector()
{
    glm::vec3 _front_;
    _front_.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    _front_.y = sin(glm::radians(pitch));
    _front_.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    front = glm::normalize(_front_);

    right = glm::normalize(glm::cross(front, worldup));
    up    = glm::normalize(glm::cross(right, front));
}

float Camera::GetCameraZoom() const
{
    return camera_zoom;;
}

glm::mat4 Camera::get_projection()
{
    return glm::perspective(GetCameraZoom(), get_screen_aspect_radio(), -1.0f, 1.0f);
}

glm::vec3 Camera::get_camera_position()
{
    return this->pos;
}

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

/*! ===> Creates on 2021/4/15. <=== */

/*!
 * @author 2B键盘
 */
#pragma once

#include "scene/3d/camera/camera.h"

namespace alkaid
{
    class OpenGLCamera : public Camera
    {
    public:
        OpenGLCamera(glm::vec3 __pos, glm::vec3 __upvec, glm::vec3 __target)
                : pos(__pos), upvec(__upvec), target(__target)
        {
            this->direction = glm::normalize(pos - target);
            this->camera_right = glm::normalize(glm::cross(upvec, direction));
            this->camera_up = glm::cross(direction, camera_right);
        }

        void move(glm::vec3 __pos) override { this->pos = __pos; } // 移动相机

        // 旋转相机
        void rotate(float x, float y) override;

        void look_at();

        // 每帧都需要调用，需要刷新相机的一些参数信息
        void refresh() override;

        // -----------------------------------
        // 获取相机各项参数
        glm::vec3 get_pos() const override { return this->pos; }
        glm::vec3 get_target() const override { return this->target; }
        glm::vec3 get_direction() const override { return this->direction; }
        glm::vec3 get_upvec() const override { return this->upvec; }
        glm::vec3 get_camera_up() const override { return this->camera_up; }
        glm::vec3 get_camera_right() const override { return this->camera_right; }
        glm::vec3 get_camera_front() const override { return this->camera_front; }

        /*! 获取相机的移动速度 */
	void set_speed(float __speed) override { this->speed = __speed; }
        float get_speed() const override { return this->speed * this->delta_time; }

    private:
        glm::vec3 pos;
        glm::vec3 target;
        glm::vec3 direction;
        glm::vec3 upvec;

        glm::vec3 camera_front;
        glm::vec3 camera_up;
        glm::vec3 camera_right;

        float speed = 2.0f; // 相机移动速度
        float delta_time = 0.0f; // 和上一帧的时间差
        float last_frame = 0.0f; // 上一帧的时间

        //
        // 由于鼠标输入是来自上一帧的，所以需要保存上一帧的鼠标信息
        //
        float last_xoffset = 0.0f;
        float last_yoffset = 0.0f;

        float sensitivity = 0.5f; // 相机旋转敏感度

        float yaw = 0.0f, pitch = 0.0f;

        v_scope<Shader> shader; // 着色器
    };

}

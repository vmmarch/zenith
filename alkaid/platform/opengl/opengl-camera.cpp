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
#include "opengl-camera.h"

namespace alkaid
{

    // 旋转相机
    void OpenGLCamera::on_rotate(float x, float y)
    {
        float xoffset = x - last_xoffset;
        float yoffset = y - last_yoffset;
        this->last_xoffset = x;
        this->last_yoffset = y;

        xoffset *= sensitivity;
        yoffset *= sensitivity;

        this->yaw = xoffset;
        this->pitch = yoffset;

        glm::vec3 front;
        front.x = cos(glm::radians(pitch)) * cos(glm::radians(yaw));
        front.y = sin(glm::radians(pitch));
        front.z = cos(glm::radians(pitch)) * sin(glm::radians(yaw));

        this->camera_front = glm::normalize(front);
    }

    void OpenGLCamera::look_at()
    {
            glm::mat4 view = glm::mat4(1.0f);
        view = glm::lookAt(pos, camera_front, camera_up);
        shader->setMat4("view", view);
    }

    void OpenGLCamera::refresh()
    {
        // 计算与上一帧相差的时间
        float currframe = glfwGetTime();
        this->delta_time = currframe - last_frame;
        this->last_frame = currframe;

        look_at();
    }

}
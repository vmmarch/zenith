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
 * 相机系统
 *
 * @author 2B键盘
 */
#pragma once

#include "render/shader/shader.h"
#include <api/glfw-api.h>
#include <event/key-event.h>
#include <event/mouse-event.h>

namespace zenith
{
    class Camera
    {
    public:
        virtual ~Camera() = default;

        /**
         * 移动相机
         */
        virtual void move(glm::vec3 pos) = 0;

        /**
         * 旋转相机
         *
         * @param [i] x x坐标
         * @param [i] y y坐标
         */
        virtual void rotate(float, float) = 0;

        /**
         * 每一帧都需要调用这个方法去刷新相机属性
         */
        virtual void refresh() = 0;

        /** 相机位置 */
        virtual glm::vec3 get_pos() const = 0;

        /** 相机当前方向 */
        virtual glm::vec3 get_direction() const = 0;

        /** 相机竖向角度 */
        virtual glm::vec3 get_camera_up() const = 0;

        /** 相机横向角度 */
        virtual glm::vec3 get_camera_right() const = 0;

        /** 相机纵向角度 */
        virtual glm::vec3 get_camera_front() const = 0;

        /** 相机移动速度 */
	    virtual void set_speed(float __speed) = 0;
        virtual float get_speed() const = 0;

        // 创建相机
        static v_scope<Camera> __create(glm::vec3 pos, glm::vec3 upvec, glm::vec3 target);
    };

}

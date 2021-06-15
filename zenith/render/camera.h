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
#pragma once

#include "event/input.h"
#include <api/glfw-api.h>

#define YAW -90.0f
#define PITCH 0.0f
#define SPEED 3.0f
#define MOUSE_SENS 0.1f
#define ZOOM 45.0f
#define CONSTRAINT_PITCH 89.0f

enum camera_movement
{
    FORWARD, BACKWARD, LEFT, RIGHT
};

class Camera
{
public:
    explicit Camera(glm::vec3 pos = glm::vec3(0.0f, 0.0f, 5.0f),
           glm::vec3 up = glm::vec3(0.0f, 0.1f, 0.0f),
           float yaw = YAW, float pitch = PITCH);

    /**
     * 移动相机
     *
     * @param movement 方向枚举
     * @param delta_time 上一帧相差时间
     */
    void direction(camera_movement movement);

    /**
     * 移动视角
     *
     * @param x 鼠标X坐标
     * @param y 鼠标Y坐标
     * @param constraint_pitch 是否限制角度
     */
    void perspective(float x, float y, bool constraint_pitch = true);

    /**
     * 设置相机移动速度
     * @param speed 移动速度
     */
    void set_move_speed(float speed) { this->move_speed = speed; }

    /**
     * 缩放
     * @param value
     */
    void SetZoom(float value);

    /**
     * @return 视图矩阵
     */
    glm::mat4 get_view_matrix();

    glm::vec3 get_camera_position();

    float GetCameraZoom() const;

    [[nodiscard]] float get_screen_width() const { return screen_w; }
    [[nodiscard]] float get_screen_height() const { return screen_h; }
    [[nodiscard]] float get_screen_aspect_radio() const { return screen_w / screen_h; }

    /**
     * Get/Set 鼠标灵敏度
     * @param sensitivity 鼠标灵敏度
     */
    void set_mouse_sensitivity(float sensitivity) { mouse_sens = sensitivity; }
    float get_mouse_sensitivity() { return mouse_sens; }

    void update(float _screen_w, float _screen_h, float _delta_time)
    {
        this->screen_w = _screen_w;
        this->screen_h = _screen_h;
        this->delta_time = _delta_time;

        // 移动
        if(Input::pressed(ZENITH_KEY_W))
            direction(camera_movement::FORWARD);
        if(Input::pressed(ZENITH_KEY_S))
            direction(camera_movement::BACKWARD);
        if(Input::pressed(ZENITH_KEY_A))
            direction(camera_movement::LEFT);
        if(Input::pressed(ZENITH_KEY_D))
            direction(camera_movement::RIGHT);
    }

    glm::mat4 get_projection();

private:
    void update_camera_vector();

private:
    glm::vec3 pos;
    glm::vec3 front;
    glm::vec3 up;
    glm::vec3 right;
    glm::vec3 worldup;

    // 欧拉角
    float yaw, pitch;

    // update
    float screen_w{}, screen_h{}, delta_time{};

    // 相机参数
    float move_speed;   // 相机移动速度
    float mouse_sens;   // 鼠标灵敏度
    float camera_zoom;  // 缩放
};

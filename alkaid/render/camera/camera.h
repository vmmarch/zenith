﻿/*! ************************************************************************
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

namespace alkaid
{

    class Camera
    {
    public:
	Camera();
	virtual ~Camera() = default;
	
	virtual on_move(glm::vec3 pos) const = 0;
	virtual on_ratal(float, float) const = 0;
	virtual refresh() = 0;

	virtual glm::vec3 get_pos() const = 0;
	virtual glm::vec3 get_target() const = 0;
	virtual glm::vec3 get_direction() const = 0;
	virtual glm::vec3 get_upvec() const = 0;
	virtual glm::vec3 get_camera_up() const = 0;
	virtual glm::vec3 get_camera_right() const = 0;
	virtual glm::vec3 get_camera_front() const = 0;

	virtual glm::vec3 get_delta_time() const = 0;
	virtual glm::vec3 get_last_time() const = 0;

	virtual void set_delta_time(float);
	virtual void set_last_frame(float);

	virtual float get_last_xoffset() const = 0;
	virtual float get_last_yoffset() const = 0;

	virtual float get_speed() const = 0;

	virtual v_scope<Shader> get_shader();

	// 创建相机
	v_scope<Camera> __create(glm::vec3 pos, glm::vec3 upvec, glm::vec3 target);

    }

    class OpenGLCamera : public Camera
    {
    public:
	Camera(glm::vec3 __pos, glm::vec3 __upvec, glm::vec3 __target) 
		: pos(__pos), upvec(__upvec), target(__target)
	{
		this->direction = glm::normalize(pos - target);
		this->camera_right = glm::normalize(glm::cross(upvec, direction));
		this->camera_up = glm::cross(direction, right);
	}	

	void on_move(glm::vec3 pos) override { this->pos = pos; } // 移动相机
	
	// 旋转相机
	void on_rotal(float x, float y) override
	{
		float xoffset = x - last_xoffset;
		float yoffset = y - last_yoffset;
		this->last_xoffset = x;
		this->last_yoffset = y;

		xoffset *= sensitvity;
		yoffset *= sensitvity;

		this->yaw = xoffset;
		this->pitch = yoffset;

		glm::vec3 front;
		front.x = cos(glm::radians(pitch)) * cos(glm::radians(yaw));
		front.y = sin(glm::radians(pitch));
		front.z = cos(glm::radians(pitch)) * sin(glm::radians(yaw));

		this->camera_front = glm::normalize(front);
	}

	void look_at()
	{
		glm::mat4 view = glm::mat4(1.0f);
		view = glm::lookAt(pos, camera_front, camera_up);
		shader->setMat4("view", view)
	}

	// 每帧都需要调用，需要刷新相机的一些参数信息
	void refresh() override
	{
		// 计算与上一帧相差的时间
		float currframe = glfwGetTime();
		this->delta_time = currframe - last_frame;
		this->last_frame = currframe;
	}

	// -----------------------------------
	// 获取相机各项参数
	glm::vec3 get_pos() const override { return this->pos; }
	glm::vec3 get_target() const override { return this->target; }
	glm::vec3 get_direction() const override { return this->direction; }
	glm::vec3 get_upvec() const override { return this->upvec; }
	glm::vec3 get_camera_up() const override { return this->camera_up; }
	glm::vec3 get_camera_right() const override { return this->camera_right; }
	glm::vec3 get_camera_front() const override { return this->camera_front; }

	float get_delta_time() const override { return this->delta_time; }
	float get_last_frame() const override { return this->last_frame; }

	void set_delta_time(float time) override { this->delta_time = time; }
	void set_last_frame(float frame) override { this->last_frame = frame; }

	/*! 获取相机的移动速度 */
	void get_speed() override { return this->speed * this->delta_time; } 

	v_scope<Shader> get_shader() const override { return this->shader; }

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
    }
}

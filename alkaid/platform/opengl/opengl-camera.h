#pragam once

#include "render/camera/camera.h"

namespace alkiad
{
	
	// 旋转相机
	void OpenGLCamera::on_rotal(float x, float y)
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
	
	void OpenGLCamera::look_at()
	{
		glm::mat4 view = glm::mat4(1.0f);
			view = glm::lookAt(pos, camera_front, camera_up);
			shader->setMat4("view", view)	
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

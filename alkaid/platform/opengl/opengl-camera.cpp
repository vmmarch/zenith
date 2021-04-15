#include "opengl-camera.h"

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
		this->camera_up = glm::cross(direction, right);
	}	

	void on_move(glm::vec3 pos) override { this->pos = pos; } // 移动相机
	
	// 旋转相机
	void on_rotal(float x, float y) override;
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
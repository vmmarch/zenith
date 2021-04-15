#include "camera.h"
#include "tool/create-scope.h"

namespace alkaid
{
	v_scope<Camera> Camera::__create(glm::vec3 pos, glm::vec3 upvec, glm::vec3 target)
	{
		return __create_camera(pos, upvec, target);
	}
}

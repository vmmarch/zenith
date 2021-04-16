#include "texture.h"
#include "tool/create-scope.h"

namespace zenith
{
	static v_scope<Texture2D> __create()
	{
		return __create_texture2D();
	}
}
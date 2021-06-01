#include "texture.h"
#include "tool/create-scope.h"

namespace zenith
{
	static zenith_scope<Texture2D> Create()
	{
		return create_texture2D();
	}
}
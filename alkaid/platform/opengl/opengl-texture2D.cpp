#include "opengl-texture2D.h"
#include <api/glfw-api.h>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

namespace alkaid
{
	void OpenGLTexture2D::read_image(v_cc path)
	{
        this->image_data = stbi_load(path, &width, &height, &nrchannels, 0);
	}
	
	void OpenGLTexture2D::bind()
	{

	}
	
	void OpenGLTexture2D::unbind()
	{
	}
	
	void OpenGLTexture2D::set_mod(surrmod mod, int coor, float* color)
	{
	}
	
	void OpenGLTexture2D::set_filter(int zoom, 	filtermod filter)
	{
	}
}
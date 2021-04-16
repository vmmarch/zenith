#include "opengl-texture2D.h"
#include <api/glfw-api.h>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

namespace alkaid
{

    static void set_wrap_mod(int, void*, float* = 0);

	void OpenGLTexture2D::read_image(v_cc path)
	{
        this->image_data = stbi_load(path, &width, &height, &nrchannels, 0);
	}
	
	void OpenGLTexture2D::bind()
	{
        __glCreateAndBindTexture(texture_id);
        __glLoadTexture2DImage(0, width, height, GL_UNSIGNED_BYTE, image_data);
        __glGenMipmap2D();

        // 释放图像内存
        stbi_image_free(image_data);
	}
	
	void OpenGLTexture2D::unbind()
	{
	}
	
	void OpenGLTexture2D::set_mod(surrmod mod, int coor, float* color)
	{
	    // 重复纹理图像
	    if(surrmod::REPEAT == mod)
	        set_wrap_mod(coor, texture::wrapping::REPEAT);

	    // 重复镜像的纹理图像
	    if(surrmod::MIRRORED_REPEAT == mod)
	        set_wrap_mod(coor, texture::wrapping::MIRRORED_REPEAT);

        // 纹理坐标会被约束在0到1之间，超出的部分会重复纹理坐标的边缘，产生一种边缘被拉伸的效果。
	    if(surrmod::CLMAP_TO_EDGE == mod)
            set_wrap_mod(coor, texture::wrapping::CLMAP_TO_EDGE);

        // 	超出的坐标为用户指定的边缘颜色。
        if(surrmod::CLMAP_TO_BORDER == mod)
            set_wrap_mod(coor, texture::wrapping::CLMAP_TO_BORDER, color);
	}
	
	void OpenGLTexture2D::set_filter(int zoom, filtermod filter)
	{
	    if(zoom == MIN_FILTER)
	        __glTexture2D_Min_Filter_Parameteriv(filter == filtermod::NEAREST ? texture::filter::NEAREST : texture::filter::LINEAR);
	    else(zoom == MAG_FILTER)
	        __glTexture2D_Mag_Filter_Parameteriv(filter == filtermod::NEAREST ? texture::filter::NEAREST : texture::filter::LINEAR);
	}

	static void set_wrap_mod(int coor, void* mod, float* color)
	{
	    if(color == NULL)
	    {
	        if(coor == WRAP_S)
                __glTexture2D_WRAP_S_Parameteri(mod);
            else
                __glTexture2D_WRAP_T_Parameteri(mod);
	    } else
	    {
	        if(coor == WRAP_S)
                __glTexture2D_WRAP_S_Parameterfv(mod, color);
            else
                __glTexture2D_WRAP_T_Parameterfv(mod, color);
	    }
	}
}
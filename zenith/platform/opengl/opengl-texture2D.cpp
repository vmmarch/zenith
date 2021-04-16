#include "opengl-texture2D.h"
#include <api/glfw-api.h>

#define STB_IMAGE_IMPLEMENTATION

#include <stb_image.h>

namespace zenith
{

    static void set_wrap_mod(int, v_ui16, float * = 0);

    void OpenGLTexture2D::read_image(v_cc path)
    {
        this->image_data = stbi_load(path, &width, &height, &nrchannels, 0);
    }

    void OpenGLTexture2D::bind()
    {
        __glCreateAndBindTexture2D(texture_id);
        __glLoadTexture2DImage(0, width, height, GL_UNSIGNED_BYTE, image_data);
        __glGenMipmap2D();

        // 释放图像内存
        stbi_image_free(image_data);
    }

    void OpenGLTexture2D::unbind()
    {
        __glUnbindTexture2D();
    }

    void OpenGLTexture2D::set_mod(v_ui16 mod, int coor, float *color)
    {
        set_wrap_mod(coor, CLMAP_TO_BORDER, color);
    }

    void OpenGLTexture2D::set_filter(int zoom, v_ui16 filter)
    {
        if (zoom == MIN_FILTER)
        {
            __glTexture2D_Min_Filter_Parameteriv(filter);
        }

        if (zoom == MAG_FILTER)
        {
            __glTexture2D_Mag_Filter_Parameteriv(filter);
        }
    }

    static void set_wrap_mod(int coor, v_ui16 mod, float* color)
    {
        if (color == NULL)
        {
            if (coor == WRAP_S)
            {
                __glTexture2D_WRAP_S_Parameteri(mod);
            } else
            {
                __glTexture2D_WRAP_T_Parameteri(mod);
            }
        } else
        {
            if (coor == WRAP_S)
            {
                __glTexture2D_WRAP_S_Parameteri(mod);
                __glTexture2DBorderColor(color);
            } else
            {
                __glTexture2D_WRAP_T_Parameteri(mod);
                __glTexture2DBorderColor(color);
            }
        }
    }
}
#include "opengl-texture2D.h"
#include <api/glfw-api.h>

#define STB_IMAGE_IMPLEMENTATION

#include "../../../modules/stb_image.h"

namespace zenith
{

    static void set_wrap_mod(int, v_ui16, float * = 0);

    void OpenGLTexture2D::read_image(v_cc path)
    {
        this->image_data = stbi_load(path, &width, &height, &nrchannels, 0);
    }

    void OpenGLTexture2D::bind()
    {
        GLAPI_CreateAndBindTexture2D(texture_id);
        GLAPI_LoadTexture2DImage(0, width, height, GL_UNSIGNED_BYTE, image_data);
        GLAPI_GenMipmap2D();

        // 释放图像内存
        stbi_image_free(image_data);
    }

    void OpenGLTexture2D::unbind()
    {
        GLAPI_UnbindTexture2D();
    }

    void OpenGLTexture2D::set_mod(v_ui16 mod, int coor, float *color)
    {
        set_wrap_mod(coor, CLMAP_TO_BORDER, color);
    }

    void OpenGLTexture2D::set_filter(int zoom, v_ui16 filter)
    {
        if (zoom == MIN_FILTER)
        {
            GLAPI_Texture2D_Min_Filter_Parameteriv(filter);
        }

        if (zoom == MAG_FILTER)
        {
            GLAPI_Texture2D_Mag_Filter_Parameteriv(filter);
        }
    }

    static void set_wrap_mod(int coor, v_ui16 mod, float* color)
    {
        if (color == NULL)
        {
            if (coor == WRAP_S)
            {
                GLAPI_Texture2D_WRAP_S_Parameteri(mod);
            } else
            {
                GLAPI_Texture2D_WRAP_T_Parameteri(mod);
            }
        } else
        {
            if (coor == WRAP_S)
            {
                GLAPI_Texture2D_WRAP_S_Parameteri(mod);
                GLAPI_Texture2DBorderColor(color);
            } else
            {
                GLAPI_Texture2D_WRAP_T_Parameteri(mod);
                GLAPI_Texture2DBorderColor(color);
            }
        }
    }
}
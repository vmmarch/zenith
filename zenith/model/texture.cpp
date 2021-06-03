/*! ************************************************************************
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

/*! ===> Creates on 2021/6/3. <=== */

/*!
 * @author 2B键盘
 */
#include "texture.h"
#include <zenith/glob.h>
#include <zenith/type.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

namespace zenith
{
    Texture::Texture(const char *file, GLenum _type) : type(_type)
    {
        load_form_file(file);
    }

    Texture::~Texture()
    {
        glDeleteTextures(1, &id);
    }

    unsigned int Texture::get_id() const
    {
        return this->id;
    }

    void Texture::bind(unsigned int texture_unit)
    {
        glActiveTexture(GL_TEXTURE0 + texture_unit);
        glBindTexture(type, id);
    }

    void Texture::unbind()
    {
        glActiveTexture(0);
        glBindTexture(type, 0);
    }

    void Texture::load_form_file(const char *file)
    {
        unsigned char* image = stbi_load(file, &width, &height, nullptr, 0);

        glGenTextures(1, &id);
        glBindTexture(type, id);

        glTexParameteri(type, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(type, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(type, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(type, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

        if(image)
        {
            glTexImage2D(type, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
            glGenerateMipmap(type);
        } else
        {
            ZENITH_ERROR(TEXTURE_LOAD_FAILED, file);
        }

        unbind();
        stbi_image_free(image);
    }

}
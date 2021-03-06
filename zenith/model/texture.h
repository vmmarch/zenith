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

#pragma once

#include<iostream>
#include<string>

#include <glfw-api.h>
#include <stb_image.h>

class Texture
{
public:
    Texture(const char *file, GLenum type = GL_TEXTURE_2D);
    ~Texture();
    inline unsigned int get_id() const;
    void bind(GLenum unit);
    void unbind();

private:
    void load_form_file(const char *file);

private:
    GLuint id;
    int width;
    int height;
    GLuint type;
};

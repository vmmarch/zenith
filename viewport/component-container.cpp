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

/*! ===> Creates on 2021/3/29. <=== */

/*!
 * @author orvals
 */
#include "component-container.h"

namespace zenith
{
    void comps_cntr::add_comps(zenith::component *__comps)
    {
        this->comps[__comps->get_comps_name()] = __comps;
    }

//    void comps_cntr::add_font(font font)
//    {
//        this->fonts[font.name] = font;
//    }

    font *comps_cntr::create_font(const char *__font_name)
    {
        return create_font(__font_name, NULL);
    }

    font *comps_cntr::create_font(const char *__font_name, const ImWchar *__im_wchar)
    {
        auto __font = new font;
        fonts[__font_name] = __font;

        // set font default ImWchar
        if (__im_wchar == NULL)
        {
            __font->set_im_wchar(imGuiIO->Fonts->GetGlyphRangesChineseFull());
        } else
        {
            __font->set_im_wchar(__im_wchar);
        }

        return __font;
    }

    font *comps_cntr::get_font(const char *name)
    {
        return this->fonts.at(name);
    }

    void comps_cntr::apply_font(const char *font_name)
    {
        font *__font = get_font(font_name);
        if (__font == NULL)
        {
            ZENITH_LOGGER_ERROR(APPLY_FONT_ERROR, font_name);
            return;
        }

        auto cfg = __font->cfg;
        if (cfg == NULL)
        {
            imGuiIO->Fonts->AddFontFromFileTTF(__font->font_source_path, __font->size_pixels, NULL,
                                               __font->get_im_wchar());
        } else
        {
            imGuiIO->Fonts->AddFontFromFileTTF(__font->font_source_path, __font->size_pixels, cfg,
                                               __font->get_im_wchar());
        }
    }

    zenith::component* comps_cntr::get_comps(const char *name)
    {
        return this->comps.at(name);
    }

    void comps_cntr::set_GLFWwindow(GLFWwindow *_window)
    {
        this->__window__ = _window;
    }

    GLFWwindow* comps_cntr::get_GLFWwindow()
    {
        return this->__window__;
    }
}


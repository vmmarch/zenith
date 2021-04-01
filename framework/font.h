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

/*! ===> Creates on 2021/3/31. <=== */

/*!
 * @author orvals
 */
#ifndef ZENITH_FONT_H
#define ZENITH_FONT_H

namespace zenith
{
    struct font
    {
        ImFontConfig* cfg;
        const char *font_source_path;
        float size_pixels;

        void set_im_wchar(const ImWchar *imwchar) { this->im_wchar = imwchar; }
        const char *get_name() { return name; }
        const ImWchar *get_im_wchar() { return im_wchar; }

    private:
        const char* name;
        const ImWchar *im_wchar;
    };
}

#endif //ZENITH_FONT_H

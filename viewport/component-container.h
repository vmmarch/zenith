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
#include "component/zenith-component.h"
#include "zenith-font.h"
#include <map>

typedef map<const char *, zenith::font*> fonts_map;

namespace zenith
{
    class comps_cntr
    {
    public:
        ImGuiIO *imGuiIO;

        ~comps_cntr()
        {
            delete menu;
        }
        void add_menu_comps(zenith::menu *);
        component *get_menu_comps();
        // void add_font(font);
        font *create_font(const char*);
        font *create_font(const char*, const ImWchar*);
        font *get_font(const char *); // 获取字体，根据name
        void apply_font(const char*);
    private:
        zenith::menu *menu = NULL;
        fonts_map fonts;
    };
}
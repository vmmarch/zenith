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
#include "engine-iface-config.h"

/*! =================================================>> */
/*! */
#define COMPS_MENU_BAR "#menu_bar"

void glfw(GLFWwindow *window)
{
    glfwHideWindow(window);
}

void iface(zenith::comps_cntr *_comps)
{

    /*! ============================================================================ */
    /*! font config */
    ImFontConfig cfg;
    cfg.OversampleH = cfg.OversampleV = 1;

    zenith::font *font_s = _comps->create_font("simsun", _comps->imGuiIO->Fonts->GetGlyphRangesChineseFull());
    font_s->size_pixels = 16.0f;
    font_s->font_source_path = "../resources/font/simsun.ttc";
    font_s->cfg = &cfg;

    _comps->apply_font("simsun");

    /*! ============================================================================ */
    /*! menu config */
    auto menu = new zenith::menu(COMPS_MENU_BAR);
    auto __FILE_OPT__ = new zenith::menu_node(GUI_TEXT_FILE);
    menu->add_menu_node(__FILE_OPT__);

    // create button
    auto __FILE_CREATE_OPT__ = __FILE_OPT__->add_menu_children(GUI_TEXT_CREATE);
    __FILE_CREATE_OPT__->add_item_children(GUI_TEXT_CREATE_PROJECT);

    // open button
    auto __FILE_OPEN_OPT_ = __FILE_OPT__->add_menu_children(GUI_TEXT_OPEN);
    __FILE_OPEN_OPT_->add_item_children(GUI_TEXT_OPEN_PROJECT);
    __FILE_OPEN_OPT_->add_item_children(GUI_TEXT_OPEN_FOLDER);

    __FILE_OPT__->add_item_children(GUI_TEXT_IMPORT);
    __FILE_OPT__->add_item_children(GUI_TEXT_SETTING, GUI_TEXT_SHORTNAME_SETTING);
    __FILE_OPT__->add_item_children(GUI_TEXT_RESTART);
    __FILE_OPT__->add_item_children(GUI_TEXT_EXIT);

    _comps->add_comps(menu);

    auto window = new zenith::window("test");
    window->set_GLFWwindow(_comps->get_GLFWwindow());
    window->__flag_n_resize();
    _comps->add_comps(window);
}

void render(__framework__ *viewport, zenith::comps_cntr *_comps)
{
//     ImGui::ShowDemoWindow();
     viewport->render("test");
}
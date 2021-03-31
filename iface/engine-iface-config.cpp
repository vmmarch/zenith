//
// @author orvals
//
#include "engine-iface-config.h"

void custom_iface(zenith::comps_cntr *_comps)
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
    auto menu = new zenith::menu();
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

    _comps->add_menu_comps(menu);
}

void render_iface(state_manager *state, zenith::comps_cntr *_comps)
{
    state->render(_comps->get_menu_comps());
}
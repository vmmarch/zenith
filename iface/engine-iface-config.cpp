//
// @author orvals
//
#include "engine-iface-config.h"

void custom_iface(comps_container *_comps)
{
    auto menu = new zenith::menu();
    auto node = new zenith::menu_node(GUI_TEXT_FILE);
    menu->add_menu_node(node);

    // create button
    auto create = node->add_menu_children(GUI_TEXT_CREATE);
    create->add_item_children(GUI_TEXT_CREATE_PROJECT);

    // open button
    auto open = node->add_menu_children(GUI_TEXT_OPEN);
    open->add_item_children(GUI_TEXT_OPEN_PROJECT);
    open->add_item_children(GUI_TEXT_OPEN_FOLDER);

    node->add_item_children(GUI_TEXT_IMPORT);
    node->add_item_children(GUI_TEXT_SETTING, GUI_TEXT_SHORTNAME_SETTING);
    node->add_item_children(GUI_TEXT_RESTART);
    node->add_item_children(GUI_TEXT_EXIT);

    _comps->add_menu_comps(menu);
}

void font_iface(ImFontAtlas* font)
{
    ImFontConfig cfg;
    cfg.OversampleH = cfg.OversampleV = 1;

    font->AddFontFromFileTTF("../resources/font/simsun.ttc", 16.0f, &cfg, font->GetGlyphRangesChineseFull());
}

void render_iface(state_manager *state, comps_container *_comps)
{
    state->render(_comps->get_menu_comps());
}
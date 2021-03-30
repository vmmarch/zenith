//
// @author orvals
//
#include "engine-iface-config.h"

void custom_iface(comps_container *_comps)
{
    auto menu = new zenith::menu();
    auto node = new zenith::menu_node(GUI_FILE);
    menu->add_menu_node(node);
    node->add_menu_children("aaaa")->add_item_children("a-1");
    node->add_item_children("bbbb");

    _comps->add_menu_comps(menu);
}

void render_iface(state_manager *state, comps_container *_comps)
{
    state->render(_comps->get_menu_comps());
}
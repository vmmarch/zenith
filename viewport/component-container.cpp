#include "component-container.h"

void comps_container::add_menu_comps(zenith::menu* menu)
{
    this->_menu = menu;
}

component *comps_container::get_menu_comps()
{
    return this->_menu;
}

//
// @author orvals
//
#include "component/zenith-component.h"

class comps_container
{
public:
    ~comps_container()
    {
        delete _menu;
    }
    void add_menu_comps(zenith::menu*);
    component *get_menu_comps();

private:
    zenith::menu* _menu = NULL;
};
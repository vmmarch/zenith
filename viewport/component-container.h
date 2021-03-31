//
// @author orvals
//
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
#include "component-container.h"

namespace zenith
{
    void comps_cntr::add_menu_comps(zenith::menu *__menu)
    {
        this->menu = __menu;
    }

    component *comps_cntr::get_menu_comps()
    {
        return this->menu;
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
}


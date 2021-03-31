//
// Created by aorus on 2021/3/31.
//

#ifndef ZENITH_ZENITH_FONT_H
#define ZENITH_ZENITH_FONT_H

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

#endif //ZENITH_ZENITH_FONT_H

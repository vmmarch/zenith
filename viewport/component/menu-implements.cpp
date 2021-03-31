//
// Created by aorus on 2021/3/29.
//

#include "menu-define.h"

void _render_menu(vector<zenith::menu_node *> children)
{
    for (auto iter : children)
    {
        iter->vrender();
    }
}

void _render_item(vector<zenith::menu_node *> children)
{
    if (!children.empty())
    {
        for (auto iter : children)
        {
            if (iter->is_menu())
            {
                if (ImGui::BeginMenu(iter->get_name()))
                { _render_item(iter->get_children()); ImGui::EndMenu(); }
            } else
            {
                const char* shortname = iter->get_shortname();
                if(shortname == NULL)
                {
                    if (ImGui::MenuItem(iter->get_name()))
                    { iter->execute(); }
                }else
                {
                    if (ImGui::MenuItem(iter->get_name(), shortname))
                    { iter->execute(); }
                }
                _render_item(iter->get_children());
            }
        }
    }
}

namespace zenith
{
    /*! /////////////////////////////////////////////////////////////////////// */
    /*! class: menu */
    menu_node *menu::add_menu_node(menu_node *node)
    {
        this->children.push_back(node);
        return node;
    }

    void menu::vrender()
    {
        if (ImGui::BeginMainMenuBar())
        {
            _render_menu(this->children);
            ImGui::EndMainMenuBar();
        }
    }

    /*! /////////////////////////////////////////////////////////////////////// */
    /*! class: menu_node */
    menu_node::menu_node(const char *name, menu_type type)
    {
        this->name = name;
        this->type = type;
    }

    menu_node *menu_node::add_menu_children(const char *_name)
    {
        auto node = new menu_node(_name, NODE_TYPE_MENU);
        this->children.push_back(node);

        return node;
    }

    menu_node *menu_node::add_item_children(const char *_name, func_button_pressed _pressed_func)
    {
        return add_item_children(_name, NULL, _pressed_func);
    }

    menu_node *menu_node::add_item_children(const char *__name, const char *__shortname, func_button_pressed __pressed_func)
    {
        auto node = new menu_node(__name, NODE_TYPE_ITEM);

        if(__pressed_func != NULL)
            node->button_press_func = __pressed_func;

        if(__shortname != NULL)
            node->set_shortname(__shortname);

        this->children.push_back(node);
        return node;
    }

    void menu_node::vrender()
    {
        if (ImGui::BeginMenu(this->name))
        {
            _render_item(this->children);
            ImGui::EndMenu();
        }
    }

    const char *menu_node::get_name()
    {
        return this->name;
    }

    void menu_node::set_name(const char *_name)
    {
        this->name = _name;
    }

    vector<menu_node *> menu_node::get_children()
    {
        return this->children;
    }

    bool menu_node::is_menu()
    {
        return this->type == NODE_TYPE_MENU;
    }

    void menu_node::execute()
    {
        if(this->button_press_func != NULL)
            button_press_func();
    }

    void menu_node::set_shortname(const char *__shortname)
    {
        this->shortname = __shortname;
    }

    const char *menu_node::get_shortname()
    {
        return this->shortname;
    }

}
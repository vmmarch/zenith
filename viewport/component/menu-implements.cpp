//
// Created by aorus on 2021/3/29.
//

#include "menu-define.h"

void _render_menu(vector<zenith::menu_node *> children)
{
    for (auto iter : children)
    {
        iter->render();
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
                if (ImGui::MenuItem(iter->get_name()))
                { iter->execute(); }
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

    void menu::render()
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
        auto node = new menu_node(_name, NODE_TYPE_ITEM);
        if(_pressed_func != NULL)
            node->button_press_func = _pressed_func;

        this->children.push_back(node);
        return node;
    }

    void menu_node::render()
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

}
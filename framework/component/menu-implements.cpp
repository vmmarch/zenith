/*! ************************************************************************
 *
 * Copyright (C) 2020 dahan All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *! ************************************************************************/

/*! ===> Creates on 2021/3/29. <=== */

/*!
 * @author orvals
 */
#include "component.h"

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
                // 当前菜单选项是否存在shortname
                if(shortname == NULL)
                {
                    if (ImGui::MenuItem(iter->get_name())) // 渲染没有shortname的选项
                    { iter->execute(); }
                }else
                {
                    if (ImGui::MenuItem(iter->get_name(), shortname)) // 渲染带有shortname的选项
                    { iter->execute(); }
                }

                // 如果它存在子选项的话就继续去渲染当前菜单子集
                _render_item(iter->get_children());
            }
        }
    }
}

namespace zenith
{
    /*! /////////////////////////////////////////////////////////////////////// */
    /*! class: menu */

    menu::menu(const char* name)
    {
        this->comps_name = name;
    }

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

    const char *menu_node::get_name() const
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

    const char *menu_node::get_shortname() const
    {
        return this->shortname;
    }

}
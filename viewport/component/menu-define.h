//
// Created by aorus on 2021/3/29.
//


//    if(is_display_menu_bar)
//        if (ImGui::BeginMainMenuBar())
//        {
//            if (ImGui::BeginMenu("File"))
//            {
//                ImGui::EndMenu();
//            }
//            if (ImGui::BeginMenu("Edit"))
//            {
//                if (ImGui::MenuItem("Undo", "CTRL+Z")) {}
//                if (ImGui::MenuItem("Redo", "CTRL+Y", false, false)) {}  // Disabled item
//                ImGui::Separator();
//                if (ImGui::MenuItem("Cut", "CTRL+X")) {}
//                if (ImGui::MenuItem("Copy", "CTRL+C")) {}
//                if (ImGui::MenuItem("Paste", "CTRL+V")) {}
//                ImGui::EndMenu();
//            }
//            ImGui::EndMainMenuBar();
//        }

#ifndef ZENITH_MENU_DEFINE_H
#define ZENITH_MENU_DEFINE_H

#include "component.h"
#include <vector>

#define NODE_TYPE_MENU 0
#define NODE_TYPE_ITEM 1

typedef unsigned int menu_type;

using namespace std;

namespace zenith
{
    class menu_node;

    class menu : public component
    {
    public:
        menu_node *add_menu_node(menu_node *node); // 添加菜单节点
        void render();                            // 渲染

    private:
        vector<menu_node *> children;
    };

class menu_node : public component
    {
    public:
        menu_node(const char *name, menu_type= NODE_TYPE_MENU);
        menu_node* add_children(const char *name, menu_type= NODE_TYPE_ITEM);
        void render();
        const char *get_name();
        void set_name(const char *);
        vector<menu_node *> get_children();

    bool is_menu();

private:
        const char *name;
        menu_type type;
        vector<menu_node *> children;
};

}
#endif //ZENITH_MENU_DEFINE_H

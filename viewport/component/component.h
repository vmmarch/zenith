/*! ********************************************************************************************************* //
 *                                                                                                            //
 * Copyright (C) 2020 dahan All rights reserved.                                                              //
 *                                                                                                            //
 * Licensed under the Apache License, Version 2.0 (the "License");                                            //
 * you may not use this file except in compliance with the License.                                           //
 * You may obtain a copy of the License at                                                                    //
 *                                                                                                            //
 *     http://www.apache.org/licenses/LICENSE-2.0                                                             //
 *                                                                                                            //
 * Unless required by applicable law or agreed to in writing, software                                        //
 * distributed under the License is distributed on an "AS IS" BASIS,                                          //
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.                                   //
 * See the License for the specific language governing permissions and                                        //
 * limitations under the License.                                                                             //
 *                                                                                                            //
 *! ********************************************************************************************************* //
                                                                                                              //
/*! ===> Creates on 2021/3/30. <=== */                                                                        //
                                                                                                              //
/*!                                                                                                           //
 * @author orvals                                                                                             //
 */                                                                                                           //
#ifndef ZENITH_COMPONENT_H                                                                                    //
#define ZENITH_COMPONENT_H                                                                                    //
                                                                                                              //
#include "layout.h"                                                                                           //
#include <assert.h>                                                                                           //
#include <vector>                                                                                             //
                                                                                                              //
#define NODE_TYPE_MENU 0                                                                                      //
#define NODE_TYPE_ITEM 1                                                                                      //
                                                                                                              //
using namespace std;                                                                                          //
                                                                                                              //
typedef unsigned int menu_type;                                                                               //
typedef void (*func_button_pressed)(); // pressd button callback                                              //
                                                                                                              //
namespace zenith                                                                                              //
{                                                                                                             //
                                                                                                              //
    /*! ===================================================================================================== */
    /*! all component for father class */                                                                     //
    class component                                                                                           //
    {                                                                                                         //
    public:                                                                                                   //
        bool get_should_be_render();                                                                          //
        void set_should_be_render(bool render);  // is render this commponet，default true.                   //
        virtual void vrender() = 0;              // render                                                    //
        void set_comps_name(const char* name);                                                                //
        const char* get_comps_name();                                                                         //
                                                                                                              //
    protected:                                                                                                //
        const char* comps_name;                                                                               //
                                                                                                              //
    private:                                                                                                  //
        bool should_be_render = true;                                                                         //
    };                                                                                                        //
                                                                                                              //
    class menu_node;                                                                                          //
                                                                                                              //
    /*! ===================================================================================================== */
    /*! menu bar component，create and called vrender to render */                                            //
    class menu : public component                                                                             //
    {                                                                                                         //
    public:                                                                                                   //
        menu(const char*);                                                                                    //
        menu_node *add_menu_node(menu_node *node);  // add menu node                                          //
        void vrender();                             // render                                                 //
                                                                                                              //
    private:                                                                                                  //
        vector<menu_node *> children;                                                                         //
    };                                                                                                        //
                                                                                                              //
    /*! ===================================================================================================== */
    /*! submen or two leve menu */                                                                            //
    class menu_node : public component                                                                        //
    {                                                                                                         //
    public:                                                                                                   //
        menu_node(const char *name, menu_type= NODE_TYPE_MENU);                                               //
        menu_node *add_menu_children(const char *name);                                                       //
        menu_node *add_item_children(const char *name, func_button_pressed= NULL);                            //
        menu_node *add_item_children(const char *name, const char *, func_button_pressed= NULL);              //
        void vrender();                                                                                       //
        const char *get_name() const;                                                                         //
        void set_name(const char *);                                                                          //
        vector<menu_node *> get_children();                                                                   //
        bool is_menu(); // current node type is NODE_TYPE_MENU                                                //
        void execute(); // execute pressed_func function pointer                                              //
        void set_shortname(const char *string);                                                               //
        const char *get_shortname() const;                                                                    //
                                                                                                              //
    private:                                                                                                  //
        func_button_pressed button_press_func = NULL;                                                         //
        const char *name;                                                                                     //
        const char *shortname;                                                                                //
        menu_type type;                                                                                       //
        vector<menu_node *> children;                                                                         //
    };                                                                                                        //
                                                                                                              //
    /*! ===================================================================================================== */
    /*! 子窗口 */                                                                                              //
    class window : public component                                                                           //
    {                                                                                                         //
    public:                                                                                                   //
        window(const char*);                                                                                  //
        void vrender();                                                                                       //
        void set_GLFWwindow(GLFWwindow*);                                                                     //
        const char* get_title        ();                                                                      //
        /*! ================================================================================================= */
        /*! window config */
        ////////////////////////////////////////////////////////////////////////////////////////////////////////
        /*|*/      void __no_titlebar           () { titlebar       =    false;  }                            //
        /*|*/      void __no_scrollbar          () { scrollbar      =    false;  }                            //
        /*|*/      void __no_menu               () { menu           =    false;  }                            //
        /*|*/      void __no_move               () { move           =    false;  }                            //
        /*|*/      void __no_resize             () { resize         =    false;  }                            //
        /*|*/      void __no_collapse           () { collapse       =    false;  }                            //
        /*|*/      void __no_close              () { close          =    false;  }                            //
        /*|*/      void __no_nav                () { nav            =    false;  }                            //
        /*|*/      void __no_background         () { background     =    false;  }                            //
        /*|*/      void __no_bring_to_front     () { bring_to_front =    false;  }                            //
        /*|*/      void __no_docking            () { docking        =    false;  }                            //
        /*|*/                                                                                                 //
        /*|*/      void __yes_titlebar          () { titlebar       =    true;   }                            //
        /*|*/      void __yes_scrollbar         () { scrollbar      =    true;   }                            //
        /*|*/      void __yes_menu              () { menu           =    true;   }                            //
        /*|*/      void __yes_resize            () { move           =    true;   }                            //
        /*|*/      void __yes_collapse          () { resize         =    true;   }                            //
        /*|*/      void __yes_close             () { collapse       =    true;   }                            //
        /*|*/      void __yes_nav               () { close          =    true;   }                            //
        /*|*/      void __yes_background        () { nav            =    true;   }                            //
        /*|*/      void __yes_bring_to_front    () { background     =    true;   }                            //
        /*|*/      void __yes_docking           () { bring_to_front =    true;   }                            //
        ////////////////////////////////////////////////////////////////////////////////////////////////////////
        /*! ================================================================================================= */
    private:                                                                                                  //
        bool* p_open;                                                                                         //
        GLFWwindow* __window__;                                                                               //
        const char* title;                                                                                    //
                                                                                                              //
        bool titlebar;                                                                                        //
        bool scrollbar;                                                                                       //
        bool menu;                                                                                            //
        bool move;                                                                                            //
        bool resize;                                                                                          //
        bool collapse;                                                                                        //
        bool close;                                                                                           //
        bool nav;                                                                                             //
        bool background;                                                                                      //
        bool bring_to_front;                                                                                  //
        bool docking;                                                                                         //
    };                                                                                                        //
                                                                                                              //
}                                                                                                             //
                                                                                                              //
#endif //ZENITH_COMPONENT_H                                                                                   //

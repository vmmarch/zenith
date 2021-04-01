#include "framework.h"

void imgui_envconf()
{

}

int main(int argc, char **argv)
{
     auto app = new framework(1000, 800);
     app->render(imgui_envconf);

     return 0;
}

#include "application.h"
#include <zenith.h>

int main(int argc, char **argv)
{
    auto app = new zenith::Application();
    app->StartEngine();
    return 0;
}

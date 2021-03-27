#include "launcher.h"

namespace zenith
{
    APPLICATION *CreateApplication()
    {
        return new Application();
    }
}

int main(int argc, char **argv)
{
    auto app = zenith::CreateApplication();
    return app->StartEngine();
}

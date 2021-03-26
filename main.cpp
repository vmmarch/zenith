#include "launcher.h"

namespace zenith
{
    zenith::APPLICATION *CreateApplication()
    {
        return new zenith::Application();
    }
}

int main(int argc, char** argv)
{
    auto app = zenith::CreateApplication();
    return app->StartEngine();
}

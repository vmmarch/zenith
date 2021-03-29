#include "launcher.h"

namespace zenith
{
    APPLICATION *CreateApplication(int w, int h)
    {
        return new Application(w, h);
    }
}

int main(int argc, char **argv)
{
    auto app = zenith::CreateApplication(1200, 800);
    return app->StartEngine();
}

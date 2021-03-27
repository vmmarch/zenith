#include "launcher.h"

namespace zenith
{
    Application::Application()
    {
        // do nothing...
    }

    Application::~Application()
    {
        delete this->viewport;
    }

    void Application::InitializeViewport(int w, int h)
    {
        if (w == -1 && h == -1)
        {
            this->viewport = new Viewport(600, 600);
        } else
        {
            this->viewport = new Viewport(w, h);
        }

        this->viewport->ViewportInitialize();
    }

    void Application::TurnOffEngine(CALLBACK_BEFORE_ENGINE_SHUTDOWN func)
    {
        func();
        is_stop = true;
    }

    int Application::StartEngine()
    {
        InitializeViewport();
        // 展示viewport
        this->viewport->StartLoop();

        return EXIT_SUCCESS;
    }
}
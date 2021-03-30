#include "launcher.h"

namespace zenith
{
    Application::Application(int w, int h)
    {
        if (w == -1 && h == -1)
        {
            this->viewport = new child_window(600, 600);
        } else
        {
            this->viewport = new child_window(w, h);
        }
    }

    Application::~Application()
    {
        delete this->viewport;
    }

    void Application::TurnOffEngine(CALLBACK_BEFORE_ENGINE_SHUTDOWN func)
    {
        func();
        is_stop = true;
    }

    int Application::StartEngine()
    {
        // 展示viewport
        this->viewport->Display(custom_iface, render_iface);

        return EXIT_SUCCESS;
    }
}
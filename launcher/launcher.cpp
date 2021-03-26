#include "launcher.h"

namespace zenith
{
    Application::Application()
    {
        // do nothing...
    }

    Application::~Application()
    {
        // do nothing...
    }

    void Application::TurnOffEngine(CALLBACK_BEFORE_ENGINE_SHUTDOWN func)
    {
        func();
        is_stop = true;
    }

    int Application::StartEngine()
    {
        while(!is_stop)
        {
            // start game engine...
        }

        return EXIT_SUCCESS;
    }

}
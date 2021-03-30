#include <zenith/zenith.h>
#include "child-window.h"

typedef void (*CALLBACK_BEFORE_ENGINE_SHUTDOWN)(); // shutdown engine before callback process. 

namespace zenith
{
    class Application
    {
    public:
        Application(int= -1, int= -1);
        ~Application();
        int StartEngine();
        void TurnOffEngine(CALLBACK_BEFORE_ENGINE_SHUTDOWN); // shutdown engine.
    private:
        bool is_stop = false; // judge engine is close.
        child_window *viewport;
    };

    typedef Application APPLICATION;

    APPLICATION *CreateApplication(int = -1, int = -1); // create engine application.
}

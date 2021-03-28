#include <zenith/zenith.h>
#include "viewport.h"

typedef void (*CALLBACK_BEFORE_ENGINE_SHUTDOWN)(); // shutdown engine before callback process. 

namespace zenith
{
    class Application
    {
    public:
        Application();
        ~Application();
        void InitializeViewport(int= -1, int= -1);
        int StartEngine();
        void TurnOffEngine(CALLBACK_BEFORE_ENGINE_SHUTDOWN); // shutdown engine.

    private:
        bool is_stop = false; // judge engine is close.
        Viewport *viewport;
    };

    typedef Application APPLICATION;

    APPLICATION *CreateApplication(); // create engine application.
}

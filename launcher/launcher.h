#include <zenith/zenith.h>
#include "viewport.h"

typedef void (*CALLBACK_BEFORE_ENGINE_SHUTDOWN)(); // 关闭引擎之前的回调函数

namespace zenith
{
    class Application
    {
    public:
        Application();
        ~Application();
        void InitializeViewport(int= -1, int= -1);
        int StartEngine();
        void TurnOffEngine(CALLBACK_BEFORE_ENGINE_SHUTDOWN); // 关闭zenith

    private:
        bool is_stop = false;
        Viewport *viewport;
    };

    typedef Application APPLICATION;

    APPLICATION *CreateApplication();
}
#include "zenith.h"

namespace zenith
{

    typedef void (*CALLBACK_BEFORE_ENGINE_SHUTDOWN)(); // 关闭引擎之前的回调函数

    class Application
    {
    public:
        Application();
        ~Application();
        int StartEngine();
        void TurnOffEngine(CALLBACK_BEFORE_ENGINE_SHUTDOWN); // 关闭zenith

    private:
        bool is_stop = false;
    };

    typedef Application APPLICATION;

    APPLICATION *CreateApplication();

}
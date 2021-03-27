#include <zenith/zenith.h>
#include "viewport.h"

typedef void (*CALLBACK_BEFORE_ENGINE_SHUTDOWN)(); // �ر�����֮ǰ�Ļص�����

namespace zenith
{
    class Application
    {
    public:
        Application();
        ~Application();
        void InitializeViewport(int= -1, int= -1);
        int StartEngine();
        void TurnOffEngine(CALLBACK_BEFORE_ENGINE_SHUTDOWN); // �ر�zenith

    private:
        bool is_stop = false;
        Viewport *viewport;
    };

    typedef Application APPLICATION;

    APPLICATION *CreateApplication();
}
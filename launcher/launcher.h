#include "zenith.h"

namespace zenith
{

    typedef void (*CALLBACK_BEFORE_ENGINE_SHUTDOWN)(); // �ر�����֮ǰ�Ļص�����

    class Application
    {
    public:
        Application();
        ~Application();
        int StartEngine();
        void TurnOffEngine(CALLBACK_BEFORE_ENGINE_SHUTDOWN); // �ر�zenith

    private:
        bool is_stop = false;
    };

    typedef Application APPLICATION;

    APPLICATION *CreateApplication();

}
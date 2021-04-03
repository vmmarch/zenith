#pragma once
#include <cstdint>


namespace zenith
{
    typedef int RenderPackageType;
    typedef void* EventRef;
    enum WindowEventType {
        
    };
    struct WindowEvent {
        WindowEventType type : 32;
        void* data;
    };
    /// Author: mmc1234
    class Window
    {
    private:
        void *share;
        void *handle;
    public:
        bool Open(const char *title, const int width, const int height);
        bool Close();
        bool IsOpen();
        void PostEvent(const WindowEvent *event);
        WindowEvent* PollEvent();
        void* getHandle() const {
            return handle;
        }

        Window(void* shareIn) {
            share = shareIn;
        }
    };
}
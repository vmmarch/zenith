#include "NativeWindow.h"
#include <glfw/glfw3.h>

using namespace zenith;


bool Window::Open(const char *title, const int width, const int height) {
    if(!IsOpen()) {
        // TODO call create
        if(getHandle() == 0) {
            // TODO print error
        }
    }
    return false;
}
bool Window::Close() {
    if(IsOpen()) {
        // TODO call destroy
        handle = 0;
        return true;
    }
    return false;
}
bool Window::IsOpen() {
    return this->getHandle() != 0;
}
void Window::PostEvent(const WindowEvent *event) {

}
WindowEvent* Window::PollEvent() {

}
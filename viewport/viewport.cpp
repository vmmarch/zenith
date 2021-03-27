#include "viewport.h"

void framebuffer_size_callback(GLFWwindow *window, int width, int height);

Viewport::Viewport(int width, int height)
{
    this->width = width;
    this->height = height;
}

int Viewport::ViewportInitialize()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    ///////////////////////////////
    // 获取监视器
    GLFWmonitor *monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode *mode = glfwGetVideoMode(monitor);

    glfwWindowHint(GLFW_RED_BITS, mode->redBits);
    glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
    glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
    glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);

    this->kWindowHandle = glfwCreateWindow(mode->width, mode->height, "", monitor, NULL);
    if (this->kWindowHandle == NULL)
    {
        ZENITH_LOGGER_ERROR("创建视窗失败！");
        glfwTerminate();
        return EXIT_FAILURE;
    }

    glfwMakeContextCurrent(this->kWindowHandle);
    glfwSetFramebufferSizeCallback(this->kWindowHandle, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
    {
        ZENITH_LOGGER_ERROR("初始化GLAD失败");
        return EXIT_FAILURE;
    }

    glfwSetFramebufferSizeCallback(this->kWindowHandle, framebuffer_size_callback);

    return EXIT_SUCCESS;
}

void Viewport::StartLoop()
{
    while (!glfwWindowShouldClose(this->kWindowHandle))
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(this->kWindowHandle);
        glfwPollEvents();
    }

    glfwTerminate();
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}
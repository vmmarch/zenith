//
// Created by aorus on 2021/3/25.
//

#pragma once

#include "core/application.h"

#ifdef ZENITH_PLATFORM_WINDOWS

int main(int argc, char** argv)
{

    auto app = zenith::createApplication();

    ZENITH_LOGGER_INFO("test info log");
    ZENITH_LOGGER_ERROR("test error log");

    app->startup();
    delete app;
}

#endif
//
// Created by aorus on 2021/3/25.
//

#pragma once

#include "application.h"

#ifdef ZENITH_PLATFORM_WINDOWS

extern zenith::app zenith::createApplication();

int main(int argc, char** argv)
{

    auto app = zenith::createApplication();
    app->run();
    delete app;
}

#endif
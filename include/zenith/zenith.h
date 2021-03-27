//
// Created by aorus on 2021/3/25.
//

#pragma once

#include <cstdarg>
#include <iostream>

typedef const char *zenith_uc;

void info(zenith_uc msg, ...)
{
    printf("[INFO] - %s\n", msg);
}

void error(zenith_uc msg, ...)
{
    printf("[ERROR] - %s\n", msg);
}

#define ZENITH_LOGGER_INFO(...) info(__VA_ARGS__)
#define ZENITH_LOGGER_ERROR(...) error(__VA_ARGS__)

#ifdef ZENITH_PLATFORM_WINDOWS
    #ifdef ZENITH_BUILD_DLL
        #define ZENITH __declspec(dllexport)
    #else
        #define ZENITH_API __declspec(dllimport)
    #endif
#else
    #error Zenith only support Windows platform!
#endif

//
// Created by aorus on 2021/3/25.
//

#ifndef ZENITH_CORE_H
#define ZENITH_CORE_H

#include <stdio.h>
#include <cstdarg>
#include <iostream>

typedef const char *zenith_uc;

void info(zenith_uc msg, ...)
{
    va_list va;
    va_start(va, msg);
    std::string str = "[INFO] - ";
    str += msg;
    printf(str.c_str(), va);
    printf("\n");
    va_end(va);
}

void error(zenith_uc msg, ...)
{
    va_list va;
    va_start(va, msg);
    std::string str = "[ERROR] - ";
    str += msg;
    printf(str.c_str(), va);
    printf("\n");
    va_end(va);
}

#define ZENITH_LOGGER_INFO(...) info(__VA_ARGS__)
#define ZENITH_LOGGER_ERROR(...) error(__VA_ARGS__)

#ifdef ZENITH_PLATFORM_WINDOWS
#ifdef ZENITH_BUILD_DLL
#define ZENITH_API __declspec(dllexport)
#else
#define ZENITH_API __declspec(dllimport)
#endif
#else
#error Zenith only support Windows platform!
#endif

#endif // AFTERLIFE_CORE_H

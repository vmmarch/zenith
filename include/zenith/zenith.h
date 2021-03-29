//
// Created by aorus on 2021/3/25.
//

#pragma once

#include <cstdarg>
#include <iostream>

typedef const char      zenith_cc;
typedef unsigned char   zenith_uc;

extern void info(zenith_cc *msg, ...);
extern void error(char const*, ...);

extern void ZENITH_LOGGER_INFO(char const*, ...);
extern void ZENITH_LOGGER_ERROR(char const*, ...);
extern void ZENITH_FATAL_ERROR(char const*, ...); // 如果是致命错误就退出引擎

#ifdef ZENITH_PLATFORM_WINDOWS
    #ifdef ZENITH_BUILD_DLL
        #define ZENITH __declspec(dllexport)
    #else
        #define ZENITH_API __declspec(dllimport)
    #endif
#else
    #error Zenith only support Windows platform!
#endif

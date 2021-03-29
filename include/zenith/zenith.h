//
// Created by aorus on 2021/3/25.
//

#pragma once

#include <iostream>
#include <cstring>

typedef unsigned char zenith_uc;

extern void INFO(std::string *__fmt, ...);
extern void ERROR(std::string *__fmt, ...);

extern void ZENITH_LOGGER_INFO(std::string, ...);
extern void ZENITH_LOGGER_ERROR(std::string, ...);
extern void ZENITH_FATAL_ERROR(std::string, ...); // 如果是致命错误就退出引擎

#ifdef ZENITH_PLATFORM_WINDOWS
    #ifdef ZENITH_BUILD_DLL
        #define ZENITH __declspec(dllexport)
    #else
        #define ZENITH_API __declspec(dllimport)
    #endif
#else
    #error Zenith only support Windows platform!
#endif

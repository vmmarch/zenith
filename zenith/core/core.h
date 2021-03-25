//
// Created by aorus on 2021/3/25.
//

#ifndef ZENITH_CORE_H
#define ZENITH_CORE_H

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

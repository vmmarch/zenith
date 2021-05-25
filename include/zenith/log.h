/*! ************************************************************************
 *
 * Copyright (C) 2020 dahan All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *! ************************************************************************/

/*! ===> Creates on 2021/4/18. <=== */

/*!
 * @author 2B键盘
 */
#pragma once

#include <zenith/type.h>
#include <string>
#include <cstring>
#include <stdarg.h>
#include <vector>

namespace zenith
{
    enum level
    {
        INFO, DEBUG, WARN, ERR
    };

    static const char *__get_level_value(level lev)
    {
        switch (lev)
        {
            case level::INFO:
                return "INFO";
            case level::DEBUG:
                return "DEBUG";
            case level::WARN:
                return "WARN";
            default:
                return "ERROR";
        }

    }

    /**
     * 字符格式化
     * @param fmt 格式化的原字符串
     * @param ... 可变参数列表
     */
    static void __logc(const char *fmt, ...)
    {
        va_list args;
        va_start(args, fmt);

        size_t len;

#ifdef __ZENITH_PLATFORM_WINDOWS__
        len = _vscprintf(fmt, args) + 1; // Used MinGW
#elif __ZENITH_PLATFORM_MACOS__
        len = 0;
#else
#   error NOT SUPPORT THIS PLATFORM.
#endif
        std::vector<char> vbuf(len, '\0');

        int nwrite;
#ifdef __ZENITH_PLATFORM_WINDOWS__
        nwrite = _vsnprintf_s(&vbuf[0], vbuf.size(), len, fmt, args);
#elif __ZENITH_PLATFORM_MACOS__
        nwrite = 0;
#else
#   error NOT SUPPORT THIS PLATFORM.
#endif

        if(nwrite > 0)
        {
            printf("%s\n", &vbuf[0]);
        }
        va_end(args);
    }

    template<typename FMT, typename... Args>
    void log(FMT &__fmt, level lev, Args &&... args)
    {
        char buf[2048];
        snprintf(buf, sizeof(buf), "[%s] [%s] - %s", "2020-04:20 00:26", __get_level_value(lev), __fmt);
        __logc(buf, std::forward<Args>(args)...);
    }

    template<typename FMT, typename... Args>
    void zenithloggerinfo(FMT &__fmt, Args &&... args)
    {
        log(__fmt, level::INFO, std::forward<Args>(args)...);
    }

    template<typename FMT, typename... Args>
    void zenithloggerdebug(FMT &__fmt, Args &&... args)
    {
        log(__fmt, level::DEBUG, std::forward<Args>(args)...);
    }

    template<typename FMT, typename... Args>
    void zenithloggerwarn(FMT &__fmt, Args &&... args)
    {
        log(__fmt, level::WARN, std::forward<Args>(args)...);
    }

    template<typename FMT, typename... Args>
    void zenithloggererror(FMT &__fmt, Args &&... args)
    {
        log(__fmt, level::ERR, std::forward<Args>(args)...);
    }
}
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

    static void __logc(const char *fmt, ...)
    {
        va_list ap;
        va_start(ap, fmt);

        // 1、计算得到长度
        //---------------------------------------------------
        // 返回 成功写入的字符个数
        int count_write = snprintf(NULL, 0, fmt, ap);
        va_end(ap);

        // 长度为空
        if (0 >= count_write)
            return;

        count_write++;

        // 2、构造字符串再输出
        //---------------------------------------------------
        va_start(ap, fmt);

        char *pbuf_out = NULL;
        pbuf_out = (char *) malloc(count_write);
        if (NULL == pbuf_out)
        {
            va_end(ap);
            return;
        }

        // 构造输出
        vsnprintf(pbuf_out, count_write, fmt, ap);
        // 释放空间
        va_end(ap);

        std::cout << pbuf_out << "\n";

        // 释放内存空间
        free(pbuf_out);
        pbuf_out = NULL;
    }

    template<typename FMT, typename... Args>
    void log(FMT &__fmt, level lev, Args &&... args)
    {
        char buf[2048];
        snprintf(buf, sizeof(buf), "[%s] [%s] - %s", "2020-04:20 00:26", __get_level_value(lev), __fmt);
        __logc(buf, std::forward<Args>(args)...);
    }

    template<typename FMT, typename... Args>
    void ZENITHLOGGERINFO(FMT &__fmt, Args &&... args)
    {
        log(__fmt, level::INFO, std::forward<Args>(args)...);
    }

    template<typename FMT, typename... Args>
    void ZENITHLOGGERDEBUG(FMT &__fmt, Args &&... args)
    {
        log(__fmt, level::DEBUG, std::forward<Args>(args)...);
    }

    template<typename FMT, typename... Args>
    void ZENITHLOGGERWARN(FMT &__fmt, Args &&... args)
    {
        log(__fmt, level::WARN, std::forward<Args>(args)...);
    }

    template<typename FMT, typename... Args>
    void ZENITHLOGGERERROR(FMT &__fmt, Args &&... args)
    {
        log(__fmt, level::ERR, std::forward<Args>(args)...);
    }
}
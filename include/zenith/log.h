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
#include <zenith/string.h>

#define OUT_MESSAGE "[{}] [{}] - {}\0"

enum level
{
    INFO, DEBUG, WARN, ERR
};

template<typename FMT, typename... Args>
void log(FMT &__fmt, level lev, Args &&... args)
{
    std::string out = stringf(OUT_MESSAGE, "2029990", "lev", "aaa");
    std::cout << out << std::endl;
//    out += __fmt;
//    std::cout << out.c_str() << std::endl;
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
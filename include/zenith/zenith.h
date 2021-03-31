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

/*! ===> Creates on 2021/3/25. <=== */

/*!
 * @author orvals
 */
#pragma once

#include <iostream>
#include <cstring>

typedef unsigned char zenith_uc;

extern void INFO(std::string __fmt, ...);
extern void ERROR(std::string __fmt, ...);

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

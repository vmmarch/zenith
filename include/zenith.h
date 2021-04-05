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
 * @author 2B键盘
 */
#pragma once

#include <memory>
#include <iostream>

typedef const char* v_cc;
typedef unsigned char v_uchar;
typedef unsigned int v_uint;
typedef uint8_t v_uint8t;
typedef uint16_t v_uint16t;
typedef uint32_t v_uint32t;

template<typename T>
using v_scope = std::unique_ptr<T>;

template<typename T, typename ... Args>
constexpr v_scope<T> CreateScope(Args&& ... args)
{
    return std::make_unique<T>(std::forward<Args>(args)...);
}

namespace zenith
{
        template<typename T>
        using Ref = std::shared_ptr<T>;
        template<typename T, typename... Args>
        constexpr Ref<T> CreateRef(Args&&... args)
        {
            return std::make_shared<T>(std::forward<Args>(args)...);
        }
}

#define __ZENITH_INFO__(...)
#define __ZENITH_DEBUG__(...)
#define __ZENITH_WARN__(...)
#define __ZENITH_ERROR__(...)

#define __BIT__(x) (1 << x)

#define __ZENITH_BIND_EVENT_FN__(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)> (args)...); }

#ifdef __ZENITH_PLATFORM_WINDOWS__
    #ifdef __ZENITH_BUILD_DLL__
        #define ZENITH_API __declspec(dllexport)
    #else
        #define ZENITH_API __declspec(dllimport)
    #endif
#else
    #error Zenith only support Windows platform!
#endif

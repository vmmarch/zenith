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
#include <alkaid/globalization.h>

typedef const char* v_cc;
typedef unsigned char v_uc;
typedef unsigned int v_ui1;
typedef uint8_t v_ui8;
typedef uint16_t v_ui16;
typedef uint32_t v_ui32;
typedef void* v_any;
typedef int v_suc;

// =================================================================
// vec2
struct v_vec2
{
    v_ui16 x, y;
    v_vec2(v_ui16 _x, v_ui16 _y) : x(_x), y(_y) {}
};

static v_vec2 create_vec2(v_ui16 x, v_ui16 y)
{
    return v_vec2(x, y);
}

static const v_vec2 empty_vec2 = create_vec2(0, 0);

template<typename T>
using v_scope = std::unique_ptr<T>;

template<typename T, typename ... Args>
constexpr v_scope<T> create_scope(Args&& ... args)
{
    return std::make_unique<T>(std::forward<Args>(args)...);
}

namespace alkaid
{
        template<typename T>
        using Ref = std::shared_ptr<T>;

        template<typename T, typename... Args>
        constexpr Ref<T> create_ref(Args&&... args)
        {
            return std::make_shared<T>(std::forward<Args>(args)...);
        }
}

#define __ALKAID_INFO(...)
#define __ALKAID_DEBUG(...)
#define __ALKAID_WARN(...)
#define __ALKAID_ERROR(...)

#define __BIT__(x) (1 << x)

#define __ALKAID_BIND_EVENT_FN__(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)> (args)...); }

#ifdef __ALKAID_PLATFORM_WINDOWS__
    #ifdef __ALKAID_BUILD_DLL__
        #define XM_API __declspec(dllexport)
    #else
        #define XM_API __declspec(dllimport)
    #endif
#else
    #error alkaid only support Windows platform!
#endif

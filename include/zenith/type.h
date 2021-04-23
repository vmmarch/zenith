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
#include <zenith/globalization.h>
#include <zenith/log.h>

#define EXTAPI extern

#define ZENITH_CHAR             1
#define ZENITH_INT              4
#define ZENITH_SHORT            2
#define ZENITH_SHORT_INT        2
#define ZENITH_UNSIGNED_INT     4
#define ZENITH_LONG             4
#define ZENITH_FLOAT            4
#define ZENITH_UINT8_T          1
#define ZENITH_UINT16_T         1
#define ZENITH_UINT32_T         1
#define ZENITH_VOID             8

typedef const char *v_cc;
typedef unsigned char v_uc;
typedef unsigned int v_ui1;
typedef uint8_t v_ui8;
typedef uint16_t v_ui16;
typedef uint32_t v_ui32;
typedef void *v_any;
typedef int v_suc;

typedef void (*zenith_noparam_fn)();

template<typename T>
using v_scope = std::unique_ptr<T>;

template<typename T>
using v_shared = std::shared_ptr<T>;

#define ZENAPI extern

namespace zenith
{
    namespace render
    {

        /**
         * 渲染API
         */
        enum api { NONE, GL, DX };

        /*!
         * @enum [i] TYPE_FILL 默认模式
         * @enum [i] TYPE_LINE 使用线来绘制
         */
        enum type_t { FILL, LINE };
    }

    // =================================================================
    // vec2
    struct v_vec2
    {
        v_ui16 x, y;

        v_vec2(v_ui16 _x, v_ui16 _y) : x(_x), y(_y)
        {}
    };

    static v_vec2 __create_vec2(v_ui16 x, v_ui16 y)
    {
        return v_vec2(x, y);
    }

    static const v_vec2 empty_vec2 = __create_vec2(0, 0);

    template<typename T, typename ... Args>
    constexpr v_scope<T> __create_scope(Args &&... args)
    {
        return std::make_unique<T>(std::forward<Args>(args)...);
    }

    template<typename T>
    using Ref = std::shared_ptr<T>;

    template<typename T, typename... Args>
    constexpr Ref<T> __create_ref(Args &&... args)
    {
        return std::make_shared<T>(std::forward<Args>(args)...);
    }

    template<typename FMT, typename... Args>
    EXTAPI void zenithloggerinfo(FMT &, Args &&...);
    template<typename FMT, typename... Args>
    EXTAPI void zenithloggerdebug(FMT &, Args &&...);
    template<typename FMT, typename... Args>
    EXTAPI void zenithloggerwarn(FMT &, Args &&...);
    template<typename FMT, typename... Args>
    EXTAPI void zenithloggererror(FMT &, Args &&...);
}

#define ZENITH_INFO(...) zenith::zenithloggerinfo(__VA_ARGS__)
#define ZENITH_DEBUG(...) zenith::zenithloggerdebug(__VA_ARGS__)
#define ZENITH_WARN(...) zenith::zenithloggerwarn(__VA_ARGS__)
#define ZENITH_ERROR(...) zenith::zenithloggererror(__VA_ARGS__)


#define __BIT__(x) (1 << x)

#define ZENITH_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)> (args)...); }

#ifdef __ZENITH_PLATFORM_WINDOWS__
#ifdef __ZENITH_BUILD_DLL__
#define ZENITHAPI __declspec(dllexport)
#else
#define ZENITHAPI __declspec(dllimport)
#endif
#else
#error zenith only support Windows platform!
#endif

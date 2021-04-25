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

/*! ===> Creates on 2021/4/14. <=== */

/*!
 * @author 2B键盘
 */
#pragma once

#include <zenith/type.h>

// -----------------------------------------------
// 2D坐标标识
#define WRAP_S 0
#define WRAP_T 1

// -----------------------------------------------
// 纹理缩放
#define MIN_FILTER 0 // 缩小(Minify)
#define MAG_FILTER 1 // 放大(Magnify)

namespace zenith
{

    class Texture2D
    {
    public:
        virtual ~Texture2D() = default;

        /** 读取纹理图片 */
        virtual void read_image(v_cc) = 0;

        /** 绑定纹理 */
        virtual void bind() = 0;

        /** 纹理接触绑定 */
        virtual void unbind() = 0;

        /**
         * 设置纹理环绕方式
         *
         * @param [i] mod 纹理环绕方式
         * @param [i] coor 坐标设置
         * @param [i] color 颜色, 只有CLMAP_TO_BORDER才有这个参数。
         */
        virtual void SetMod(v_ui16, int, float * = NULL) = 0;

        /**
         * 设置纹理过滤方式
         *
         * @param [i] zoom 纹理缩放处理
         * @param [i] filter 纹理过滤方式
         */
        virtual void SetFilter(int, v_ui16) = 0;

        // 创建纹理
        static v_scope<Texture2D> __create();
    };

}
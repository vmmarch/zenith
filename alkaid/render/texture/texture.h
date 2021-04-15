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

#include <alkaid/type.h>

// -----------------------------------------------
// 2D坐标标识
#define WRAP_S 0
#define WRAP_T 1

// -----------------------------------------------
// 纹理缩放
#define MIN_FILTER 0 // 缩小(Minify)
#define MAG_FILTER 1 // 放大(Magnify)

namespace alkaid
{

    enum surrmod
    {
        NONE,
        REPEAT, // 默认环绕方式，重复纹理图像
        MIRRORED_REPEAT, // 和上面那个相同，只是每次纹理是镜像放置的。
        CLMAP_TO_EDGE, // 纹理坐标会被约束在0到1之间，超出的部分会重复纹理坐标的边缘，产生一种边缘被拉伸的效果。
        CLMAP_TO_BORDER, // 超出的坐标为用户指定的边缘颜色

        // -----------------------------------------------
        // 多级渐远纹理
        NEAREST_MIPMAP_NEAREST, // 使用最邻近的多级渐远纹理来匹配像素大小，并使用邻近插值进行纹理采样
        LINEAR_MIPMAP_NEAREST, // 使用最邻近的多级渐远纹理级别，并使用线性插值进行采样
        NEAREST_MIPMAP_LINEAR, // 在两个最匹配像素大小的多级渐远纹理之间进行线性插值，使用邻近插值进行采样
        LINEAR_MIPMAP_LINEAR // 在两个邻近的多级渐远纹理之间使用线性插值，并使用线性插值进行采样
    };

    enum filtermod
    {
        // 邻近过滤
        NEAREST,

        // 线性过滤
        LINEAR
    };

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
        virtual void set_mod(surrmod, int, float * = NULL) = 0;

        /**
         * 设置纹理过滤方式
         *
         * @param [i] zoom 纹理缩放处理
         * @param [i] filter 纹理过滤方式
         */
        virtual void set_filter(int, filtermod) = 0;

        /** 获取纹理ID */
        virtual v_ui1 getId() const { return texture_id; }

        static v_scope<Texture2D> __create();

    private:
        v_ui1 texture_id;

    };

}
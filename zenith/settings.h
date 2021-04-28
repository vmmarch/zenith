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

/*! ===> Creates on 2021/4/23. <=== */

/*!
 * @author 2B键盘
 */
#ifndef ZENITH_SETTINGS_H
#define ZENITH_SETTINGS_H

#include <zenith/glob.h>
#include <zenith/type.h>
#include <api/glfw-api.h>

#define ZENITH_TRUE  true
#define ZENITH_FALSE false

const static int KEY_MULTISAMPLE                      = 0;        // 多重采样抗锯齿
const static int KEY_DEPTHTEST                        = 1;        // 深度测试
const static int KEY_CURSOR_MOVE_CAMER                = 2;        // 禁止鼠标移动相机

namespace zenith
{
    /**
     * 设置配置参数
     *
     * @param k KEY_XXX
     * @param v V_XXX
     */
    EXTAPI void SetValue(int k, bool v);

    /**
     * 判断当前配置是否开启
     */
    EXTAPI bool GetValue(int k);

    /**
     * 重新加载配置
     */
    EXTAPI void RELOAD_SETTING();
}

#endif
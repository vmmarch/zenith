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

/*! ===> Creates on 2021/5/1. <=== */

/*!
 * @author 2B键盘
 */
#pragma once

typedef uint32_t zenith_enum;

/**
 * 绘制普通三角形
 */
#define ZENITH_TRIANGLES 0x001

/**
 * 绘制扇形序列三角形
 */
#define ZENITH_TRIANGLE_FAN 0x002

/**
 * 绘制一条线
 */
#define ZENITH_LINES 0x003

/**
 * 绘制顶点数组
 */
#define ZENITH_ARRAYS 0x004

/**
 * 绘制索引
 */
#define ZENITH_INDEX 0x005

/**
 * 填充渲染模式（默认）
 */
#define ZENITH_FILL 0x006

/**
 * 线性渲染模式
 */
#define ZENITH_LINE 0x006

#define ZENITH_MODEL_OBJ 0x007
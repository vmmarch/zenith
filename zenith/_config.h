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

/*! ===> Creates on 2021/6/16. <=== */

/*!
 * 项目中一些初始化或固定的参数配置
 *
 * @author 2B键盘
 */
#ifndef ZENITH__CONFIG_H
#define ZENITH__CONFIG_H

#include <glm-api.h>

/**
 * 模型的初始大小
 */
#define MODEL_SCALE                         glm::vec3(0.1f)

/**
 * Mesh旋转角度
 */
#define MESH_ROTATION                       glm::vec3(0.f)

/**
 * Mesh坐标
 */
#define MODEL_POSITION                      glm::vec3(0.f)

/**
 * Mesh初始坐标
 */
#define MESH_ORIGIN                         glm::vec3(0.f)

#define MATER_AMBIENT                       glm::vec3(0.1f)

#define MATER_DIFFUSE                       glm::vec3(1.0f)

#define MATER_SPECULAR                      glm::vec3(1.0f)

#define MATER_DIFFUSE_TEX                   0

#define MATER_SPECULAR_TEX                  1

/**
 * 相机初始位置
 */
#define CAMERA_POSITION                     glm::vec3(0.0f, 0.0f, 5.0f)

/**
 * 相机初始Z轴
 */
#define CAMERA_UP                           glm::vec3(0.0f, 0.1f, 0.0f)

/**
 * 相机最大旋转角度
 */
#define CAMERA_YAW                          -90.0f

/**
 * 相机最大倾斜角度
 */
#define CAMERA_PITCH                        0.0f

/**
 * 相机默认移动速度
 */
#define CAMERA_SPEED                        3.0f

/**
 * 相机旋转灵敏度
 */
#define CAMERA_MOUSE_SENS                   0.1f

/**
 * 相机投影大小
 */
#define CAMERA_ZOOM                         45.0f

/**
 * 相机约束间距
 */
#define CAMERA_CONSTRAINT_PITCH             89.0f

#endif //ZENITH__CONFIG_H

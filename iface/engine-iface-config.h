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

/*! ===> Creates on 2021/3/31. <=== */

/*!
 * 这个头文件作用在launcher.cpp, 用于配置视窗的布局以及各个组件等初始化操作。
 * 总体来说它可以理解为一个配置文件。
 *
 * This header file used in launcher.cpp. launcher.cpp in launcher dll. the engine-iface-config.h
 * is a config file. it is responsible for the layout and initialization of the components.
 *
 * @author orvals
 */
#ifndef ZENITH_ENGINE_IFACE_CONFIG_H
#define ZENITH_ENGINE_IFACE_CONFIG_H

#include "viewport.h"

void iface(zenith::comps_cntr*);
void glfw(GLFWwindow*);
void render(state_manager *state, zenith::comps_cntr*);

#endif // ===> ZENITH_ENGINE_IFACE_CONFIG_H <===

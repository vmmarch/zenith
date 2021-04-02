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
 * 国际化标准定义
 *
 * @author orvals
 */
#pragma once

#define __ENGINE_NAME__ "ZENITH3D ENGINE"

#define GUI_TEXT_SHORTNAME_SETTING "Ctrl+Shift+S"

#ifdef __IN_CHINA__
///////////////////////////////////////////////////////////
// __IN_CHINA__

// MENU MESSAGE
#define __GUI_TEXT_FILE__ "文件"
#define __GUI_TEXT_CREATE__ "新建"
#define __GUI_TEXT_CREATE_PROJECT__ "新建项目"

#define __GUI_TEXT_OPEN__ "打开"
#define __GUI_TEXT_OPEN_PROJECT__ "打开项目"
#define __GUI_TEXT_OPEN_FOLDER__ "打开文件夹"
#define __GUI_TEXT_IMPORT__ "导入"
#define __GUI_TEXT_SETTING__ "引擎配置"
#define __GUI_TEXT_RESTART__ "重启引擎"
#define __GUI_TEXT_EXIT__ "退出引擎"

// ERROR MESSAGE
#define __STARTUP_ERROR__ __ENGINE_NAME__ "启动失败"
#define __APPLY_FONT_ERROR__ __ENGINE_NAME__ "应用字体失败：未获取到字体信息【%s】" // %s font name

///////////////////////////////////////////////////////////
#else
#error error message not support other country
#endif
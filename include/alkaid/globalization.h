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
 * @author 2B键盘
 */
#pragma once

#define __ENGINE_NAME__ "XM3D ENGINE"

#define GUI_TEXT_SHORTNAME_SETTING "Ctrl+Shift+S"

#ifdef __ALKAID_IN_CHINA__
///////////////////////////////////////////////////////////
// __ALKAID_IN_CHINA__
#define __ERROR__ "错误："

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

// INFO MESSAGE
#define __CREATE_WINDOW_INFO__ "创建窗口信息：{}, {}, {}"
#define __CREATE_WINDOW_FAILED__ "窗口创建失败"
#define __GLFW_INIT_FAILED__ "GLFW初始化失败"
#define __OPENGL_INFO__ "OpenGL创建信息: "
#define __VENDOR_INFO__ "VENDOR: {}"
#define __RENDER_INFO__ "RENDER: {}"sss
#define __VERSION_INFO__ "VERSION: {}"

// WARN MESSAGE
#define __OPENGL_SUPPORT_VERSION__ "Zenith3D引擎需要使用4.5以上的OpenGL版本"

// ERROR MESSAGE
#define __STARTUP_ERROR__ __ENGINE_NAME__##"启动失败"
#define __CREATE_OPENGL_CONTEXT_ERROR__ __ERROR__##"创建OpenGLContext失败。原因：window == NULL"
#define __INIT_GLAD_ERROR__ __ERROR__##"初始化GLAD失败。"
#define __APPLY_FONT_ERROR__ __ENGINE_NAME__ __ERROR__##"应用字体失败：未获取到字体信息【%s】" // %s font name
#define __PLEASE_CHOOSE_RENDER_API__ __ERROR__##"请选择渲染API。"
#define __NOT_SUPPORT_DIRECTX_API__ __ERROR__##"暂不支持DirectX。"
#define __UNKNOWN_SHADER_TYPE__ __ERROR__##"位置着色器类型"
#define __LOAD_GLAD_FAILED__ __ERROR__##"加载GLAD失败"
#define __ONLY_SUPPORT_WINDOWS__ __ERROR__##"目前仅支持Windows平台"

///////////////////////////////////////////////////////////
#else
#error error message not support other country
#endif
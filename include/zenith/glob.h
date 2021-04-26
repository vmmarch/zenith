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

#define ENGINE_NAME "瑶光引擎"

#define GUI_TEXT_SHORTNAME_SETTING "Ctrl+Shift+S"

#ifdef __ZENITH_IN_CHINA__
///////////////////////////////////////////////////////////
// ZENITH_IN_CHINA

// MENU MESSAGE
#define GUI_TEXT_FILE "文件"
#define GUI_TEXT_CREATE "新建"
#define GUI_TEXT_CREATE_PROJECT "新建项目"

#define GUI_TEXT_OPEN "打开 "
#define GUI_TEXT_OPEN_PROJECT "打开项目"
#define GUI_TEXT_OPEN_FOLDER "打开文件夹"
#define GUI_TEXT_IMPORT "导入 "
#define GUI_TEXT_SETTING "引擎配置 "
#define GUI_TEXT_RESTART "重启引擎 "
#define GUI_TEXT_EXIT "退出引擎 "

#define GUI_TEXT_PROPERTIES "属性"
#define GUI_TEXT_RESOURCE_MANAGER "资源管理器"

// INFO MESSAGE
#define CREATE_WINDOW_INFO "创建窗口信息：%s, %d, %d"
#define CREATE_WINDOW_FAILED "窗口创建失败 "
#define GLFW_INIT_FAILED "GLFW初始化失败 "
#define OPENGL_INFO "OpenGL创建信息："
#define VENDOR_INFO "VENDOR: %s"
#define RENDER_INFO "RENDER: %s"
#define VERSION_INFO "VERSION: %s"

// DEBUG MESSAGE
#define IFSPLIT "----------------------------------------------"
#define ENDIFSPLIT "----------------------------------------------\n"
#define VERTEX_SHADER_DEBUG "顶点着色器源码:\n%s\n"
#define FRAGMENT_SHADER_DEBUG "片段着色器源码:\n%s\n"
#define CREATE_SHADER "创建着色器[%s]: %s"

// WARN MESSAGE
#define OPENGL_SUPPORT_VERSION "Zenith3D引擎需要使用4.5以上的OpenGL版本"

// ERROR MESSAGE
#define STARTUP_ERROR ENGINE_NAME##"启动失败"
#define CREATE_OPENGL_CONTEXT_ERROR "错误：创建OpenGLContext失败。原因：window == NULL"
#define INIT_GLAD_ERROR "错误：初始化GLAD失败。 "
#define APPLY_FONT_ERROR ENGINE_NAME "错误：应用字体失败：未获取到字体信息【%s】." // %s font name
#define PLEASE_CHOOSE_RENDER_API "错误：请选择渲染API"
#define NOT_SUPPORT_DIRECTX_API "错误：暂不支持DirectX"
#define UNKNOWN_SHADER_TYPE "错误：位置着色器类型"
#define LOAD_GLAD_FAILED "错误：加载GLAD失败"
#define ONLY_SUPPORT_WINDOWS "错误：目前仅支持Windows平台"
#define CANNOT_READ_FONT "错误：未获取到{}字体"
#define SHADER_FILE_NOT_EXIST "Shader文件不存在: %s"
#define SHADER_COMPILATION_ERROR "Shader编译错误，类型：%s, 信息：\n-------\n%s"
#define PROGRAM_LINKING_ERROR "程序链接错误，类型：%s, 信息：\n-------\n%s"
#define CREATE_SHADER_FAILED "创建着色器失败：%s"
#define VERTEX_BUFFER_HAS_NOT_LAYOUT "顶点数组没有布局"
#define READ_MODEL_ERROR "读取模型文件失败: %s"

///////////////////////////////////////////////////////////
#else
#   error error message not support other country
#endif
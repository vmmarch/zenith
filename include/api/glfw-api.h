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

/*! ===> Creates on 2021/4/5. <=== */

/*!
 * @author 2B键盘
 */
#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// ----------------------------------------------------
// 纹理环绕方式

// 默认环绕方式，重复纹理图像
#define REPEAT GL_REPEAT

// 和上面那个相同，只是每次纹理是镜像放置的。
#define MIRRORED_REPEAT GL_MIRRORED_REPEAT

// 纹理坐标会被约束在0到1之间，超出的部分会重复纹理坐标的边缘，产生一种边缘被拉伸的效果。
#define CLMAP_TO_EDGE GL_CLAMP_TO_EDGE

// 超出的坐标为用户指定的边缘颜色
#define CLMAP_TO_BORDER GL_CLAMP_TO_BORDER

// ----------------------------------------------------
// 多级渐远纹理环绕

// 使用最邻近的多级渐远纹理来匹配像素大小，并使用邻近插值进行纹理采样
#define NEAREST_MIPMAP_NEAREST GL_NEAREST_MIPMAP_NEAREST

// 使用最邻近的多级渐远纹理级别，并使用线性插值进行采样
#define LINEAR_MIPMAP_NEAREST GL_LINEAR_MIPMAP_NEAREST

// 在两个最匹配像素大小的多级渐远纹理之间进行线性插值，使用邻近插值进行采样
#define NEAREST_MIPMAP_LINEAR GL_NEAREST_MIPMAP_LINEAR

// 在两个邻近的多级渐远纹理之间使用线性插值，并使用线性插值进行采样
#define LINEAR_MIPMAP_LINEAR GL_LINEAR_MIPMAP_LINEAR

// ----------------------------------------------------
// 纹理过滤方式

// 邻近过滤
#define TEXTURE_NEAREST GL_NEAREST

// 线性过滤
#define TEXTURE_LINEAR GL_LINEAR

// ----------------------------------------------------
// glfw api
#define __glTextureGLenum(ms) ( ms ? GL_TEXTURE_2D_MULTISAMPLE : GL_TEXTURE_2D )

/**
 * 删除Buffer
 */
#define __glDeleteBuffer(buf) \
{ glDeleteBuffers(1, &buf); }

/**
 * 创建ArrayBuffer
 */
#define __glCreateArrayBuffer(buf, size, data, usage) \
{ glGenBuffers(1, &buf); glBindBuffer(GL_ARRAY_BUFFER, buf); glBufferData(GL_ARRAY_BUFFER, size, data, usage); }

/**
 * 绑定ArrayBuffer
 */
#define __glBindArrayBuffer(buf) \
{ glBindBuffer(GL_ARRAY_BUFFER, buf); }

/**
 * 绑定ElementArrayBuffer
 */
#define __glBindElemArrayBuffer(buf) \
{ glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buf); }

/**
 * 解绑ElementArrayBuffer
 */
#define __glUnbindElemArrayBuffer() \
{ glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }

/**
 * 解绑ArrayBuffer
 */
#define __glUnbindArrayBuffer() \
{ glBindBuffer(GL_ARRAY_BUFFER, 0); }

/**
 * 绑定着色器程序
 */
#define __glBindProgram(prog) \
{ glUseProgram(prog); }

/**
 * 解绑着色器程序
 */
#define __glUnbindProgram() \
{ glUseProgram(0); }

/**
 * 设置着色器 int array参数
 *
 * @param [i] values int值
 */
#define __glUniform1i(prog, name, value) \
{glUniform1i(glGetUniformLocation(prog, name), value); }

/**
 * 设置着色器 int array参数
 *
 * @param [i] count 数组大小
 * @param [i] values int数组
 */
#define __glUniformai(prog, name, count, values) \
{ glUniform1iv(glGetUniformLocation(prog, name), count, values); }

/**
 * 设置着色器 float参数
 *
 * @param [i] prog 着色器程序ID
 * @param [i] name 着色器属性名称
 * @param [i] value 单个float值
 */
#define __glUniform1f(prog, name, value) \
{ glUniform1f(glGetUniformLocation(prog, name), value); }

/**
 * 设置着色器 2f float参数
 *
 * @param [i] prog 着色器程序ID
 * @param [i] name 着色器属性名称
 * @param [i] x x float参数
 * @param [i] y y float参数
 */
#define __glUniform2f(prog, name, x, y) \
{ glUniform2f(glGetUniformLocation(prog, name), x, y); }

/**
 * 设置着色器 3f float参数
 *
 * @param [i] prog 着色器程序ID
 * @param [i] name 着色器属性名称
 * @param [i] x x float参数
 * @param [i] y y float参数
 * @param [i] z z float参数
 */
#define __glUniform3f(prog, name, x, y, z) \
{ glUniform3f(glGetUniformLocation(prog, name), x, y, z); }

/**
 * 设置着色器 4f float参数
 *
 * @param [i] prog 着色器程序ID
 * @param [i] name 着色器属性名称
 * @param [i] x x float参数
 * @param [i] y y float参数
 * @param [i] z z float参数
 * @param [i] w w float参数
 */
#define __glUniform4f(prog, name, x, y, z, w) \
{ glUniform4f(glGetUniformLocation(prog, name), x, y, z, w); }

/**
 * 设置着色器 3fv 矩阵参数
 *
 * @param [i] prog 着色器程序ID
 * @param [i] name 着色器属性名称
 * @param [i] mat3 float类型矩阵，3fv : x,y,z
 */
#define __glUniformMatrix3fv(prog, name, mat3) \
{ glUniformMatrix3fv(glGetUniformLocation(prog, name), 1, GL_FALSE, glm::value_ptr(mat3)); }

/**
 * 设置着色器 4fv 矩阵参数
 *
 * @param [i] prog 着色器程序ID
 * @param [i] name 着色器属性名称
 * @param [i] mat4 float类型矩阵，4fv : x,y,z,w
 */
#define __glUniformMatrix4fv(prog, name, mat4) \
{ glUniformMatrix4fv(glGetUniformLocation(prog, name), 1, GL_FALSE, glm::value_ptr(mat4)); }

/**
 * FrameBuffer
 *
 * @param [i] buf framebuffer id
 */
#define __glDelFramebuf(buf) \
{ glDeleteFramebuffers(1, &buf); }

/**
 * 删除纹理
 *
 * @param [i] tex 纹理id
 */
#define __glDelTexture(tex) \
{ glDeleteTextures(1, &tex); }

/**
 * 创建FrameBuffer，但不进行绑定
 *
 * @param [i] buf framebuffer id
 */
#define __glCreateFramebuf(buf) \
{ glCreateFramebuffers(1, &buf); }

/**
 * 创建并绑定FrameBuffer
 *
 * @param [i] buf framebuffer id
 */
#define __glCreateAndBindFramebuf(buf) \
{  __glCreateFramebuf(buf); glBindFramebuffer(GL_FRAMEBUFFER, buf); }

/** 获取GLFW Vendor */
#define __glGetVendor() \
{ glGetString(GL_VENDOR); }

/** 获取GLFW渲染信息 */
#define __glGetRenderer() \
{ glGetString(GL_RENDERER); }

/** 获取GLFW版本 */
#define __glGetVersion() \
{ glGetString(GL_VERSION); }

/**
 * 创建纹理
 *
 * @param [i] tex 纹理ID引用
 */
#define __glCreateTexture2D(tex) \
{ glGenTextures(1, &tex); }

/**
 * 创建并绑定纹理
 *
 * @param [i] tex 纹理ID引用
 */
#define __glCreateAndBindTexture2D(tex) \
{ __glCreateTexture2D(tex); glBindTexture(GL_TEXTURE_2D, tex); }

/**
 * 解除纹理绑定
 */
#define __glUnbindTexture2D() \
{ glBindTexture(GL_TEXTURE_2D, 0); }

/**
 * 加载纹理图片到已绑定的纹理对象上
 *
 * @param [i] mipmap_level 多级渐远纹理级别，默认为0
 * @param [i] width  图片宽度
 * @param [i] height 图片高度
 * @param [i] imgformat 图片以何种格式储存，例如：GL_UNSIGNED_BYTE
 * @param [i] data 图片数据
 */
#define __glLoadTexture2DImage(mipmap_level, width, height, imgformat, data) \
{ glTexImage2D(GL_TEXTURE_2D, mipmap_level, GL_RGB, width, height, 0, GL_RGB, imgformat, data); }

/**
 * 如果要使用多级渐远纹理必须手动设置所有不同的图像（不断递增__glLoadTexture2DImage的第一个参数）
 * 或者直接在生成纹理之后调用glGenerateMipmap。这会为当前绑定的纹理自动生成多级渐远纹理。
 *
 * <code>
 *     __glLoadTexture2DImage(0, width, height, GL_UNSIGNED_BYTE, data);
 *     __glGenMipmap2D();
 * </code>
 */
#define __glGenMipmap2D() { glGenerateMipmap(GL_TEXTURE_2D); }

/**
 * 设置S坐标轴的环绕方式（2D纹理的坐标轴有ST，和3D的XY是一样的）
 *
 * @param [i] mod 环绕方式
 */
#define __glTexture2D_WRAP_S_Parameteri(mod) \
{  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, mod); }

/**
 * 设置T坐标轴的环绕方式（2D纹理的坐标轴有ST，和3D的XY是一样的）
 *
 * @param [i] mod 环绕方式
 */
#define __glTexture2D_WRAP_T_Parameteri(mod) \
{  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, mod); }

/**
 * 设置BORDER_COLOR
 *
 * @param [i] color 设置边缘颜色
 */
#define __glTexture2DBorderColor(color) \
{  glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, color); }

/**
 * 设置2D纹理缩小过滤方式
 *
 * @param [i] filter 过滤方式
 */
#define __glTexture2D_Min_Filter_Parameteriv(filtermod) \
{  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filtermod); }

/**
 * 设置2D纹理放大过滤方式
 *
 * @param [i] filter 过滤方式
 */
#define __glTexture2D_Mag_Filter_Parameteriv(filtermod) \
{ glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filtermod); }

// ----------------------------------------------------
// enable and disable

/** 光照计算 */
#define __glEnableLight() { glEnable(GL_LIGHTING); }
#define __glDisableLight() { glDisable(GL_LIGHTING); }

/** 颜色追踪 */
#define __glEnableColorMaterial() { glEnable(GL_COLOR_MATERIAL); }
#define __glDisableColorMaterial() { glDisable(GL_COLOR_MATERIAL); }

/** 深度测试 */
#define __glEnableDepthTest() { glEnable(GL_DEPTH_TEST); }
#define __glDisableDepthTest() { glDisable(GL_DEPTH_TEST); }


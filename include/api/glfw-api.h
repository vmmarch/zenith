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
#include <api/glm-api.h>


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
#define GLAPI_TextureGLenum(ms) ( ms ? GL_TEXTURE_2D_MULTISAMPLE : GL_TEXTURE_2D )

/**
 * 绑定ArrayBuffer
 */
#define GLAPI_BindArrayBuffer(id) \
{ glBindBuffer(GL_ARRAY_BUFFER, id); }

/**
 * 解绑ArrayBuffer
 */
#define GLAPI_UnbindArrayBuffer() \
{ glBindBuffer(GL_ARRAY_BUFFER, 0); }

/**
 * 绑定ElementArrayBuffer
 */
#define GLAPI_CreateIndexBuffer(buf, size, data) \
{ glGenBuffers(1, &buf); glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buf); glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW); }

/**
 * 绑定ElementArrayBuffer
 */
#define GLAPI_BindIndexArrayBuffer(buf) \
{ glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buf); }

/**
 * 解绑ElementArrayBuffer
 */
#define GLAPI_UnbindIndexArrayBuffer() \
{ glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }

/**
 * 创建VertexArray
 */
#define GLAPI_CreateVertexArray(id) \
{ glGenVertexArrays(1, &id); }

/**
 * 创建并绑定VertexArray
 */
#define GLAPI_CreateAndBindVertexArray(id) \
{ glGenVertexArrays(1, &id); glBindVertexArray(id); }

#define GLAPI_CreateBuffer2(id1, id2) \
{ glGenBuffers(1, &id1); glGenBuffers(1, &id2); }

/**
 * 删除VertexArray
 */
#define GLAPI_DeleteVertexArray(id) \
{ glDeleteVertexArrays(1, &id); }

/**
 * 绑定VertexArray
 */
#define GLAPI_BindVertexArray(id) \
{ glBindVertexArray(id); }

/**
 * 解绑VertexArray
 */
#define GLAPI_UnbindVertexArray() \
{ glBindVertexArray(0); }

/**
 * 创建并绑定ArrayBuffer, 动态渲染
 *
 * @param [i] id unsigned int
 * @param [i] size 数组大小
 */
#define GLAPI_CreateDynamicVertexBufferAndBind(id, size) \
{ glGenBuffers(1, &id); GLAPI_BindArrayBuffer(id); glBufferData(GL_ARRAY_BUFFER, size, NULL, GL_DYNAMIC_DRAW); }

/**
 * 创建并绑定ArrayBuffer, 静态渲染
 *
 * @param [i] id unsigned int
 * @param [i] buf 顶点数据
 * @param [i] size 数组大小
 */
#define GLAPI_CreateStaticVertexBufferAndBind(id, buf, size) \
{ glGenBuffers(1, &id); GLAPI_BindArrayBuffer(id); glBufferData(GL_ARRAY_BUFFER, size, buf, GL_STATIC_DRAW); }

/**
 * 删除Buffer
 */
#define GLAPI_DeleteBuffer(buf) \
{ glDeleteBuffers(1, &buf); }

/**
 * 创建ArrayBuffer
 */
#define GLAPI_CreateArrayBuffer(buf, size, data, usage) \
{ glGenBuffers(1, &buf); glBindBuffer(GL_ARRAY_BUFFER, buf); glBufferData(GL_ARRAY_BUFFER, size, data, usage); }

/**
 * 绑定着色器程序
 */
#define GLAPI_BindProgram(prog) \
{ glUseProgram(prog); }

/**
 * 解绑着色器程序
 */
#define GLAPI_UnbindProgram() \
{ glUseProgram(0); }

/**
 * 设置着色器 int array参数
 *
 * @param [i] values int值
 */
#define GLAPI_Uniform1i(prog, name, value) \
{glUniform1i(glGetUniformLocation(prog, name), value); }

/**
 * 设置着色器 int array参数
 *
 * @param [i] count 数组大小
 * @param [i] values int数组
 */
#define GLAPI_Uniformai(prog, name, count, values) \
{ glUniform1iv(glGetUniformLocation(prog, name), count, values); }

/**
 * 设置着色器 float参数
 *
 * @param [i] prog 着色器程序ID
 * @param [i] name 着色器属性名称
 * @param [i] value 单个float值
 */
#define GLAPI_Uniform1f(prog, name, value) \
{ glUniform1f(glGetUniformLocation(prog, name), value); }

/**
 * 设置着色器 2f float参数
 *
 * @param [i] prog 着色器程序ID
 * @param [i] name 着色器属性名称
 * @param [i] x x float参数
 * @param [i] y y float参数
 */
#define GLAPI_Uniform2f(prog, name, x, y) \
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
#define GLAPI_Uniform3f(prog, name, x, y, z) \
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
#define GLAPI_Uniform4f(prog, name, x, y, z, w) \
{ glUniform4f(glGetUniformLocation(prog, name), x, y, z, w); }

/**
 * 设置着色器 3fv 矩阵参数
 *
 * @param [i] prog 着色器程序ID
 * @param [i] name 着色器属性名称
 * @param [i] mat3 float类型矩阵，3fv : x,y,z
 */
#define GLAPI_UniformMatrix3fv(prog, name, mat3) \
{ glUniformMatrix3fv(glGetUniformLocation(prog, name), 1, GL_FALSE, glm::value_ptr(mat3)); }

/**
 * 设置着色器 4fv 矩阵参数
 *
 * @param [i] prog 着色器程序ID
 * @param [i] name 着色器属性名称
 * @param [i] mat4 float类型矩阵，4fv : x,y,z,w
 */
#define GLAPI_UniformMatrix4fv(prog, name, mat4) \
{ glUniformMatrix4fv(glGetUniformLocation(prog, name), 1, GL_FALSE, glm::value_ptr(mat4)); }

/**
 * FrameBuffer
 *
 * @param [i] buf framebuffer id
 */
#define GLAPI_DelFramebuf(buf) \
{ glDeleteFramebuffers(1, &buf); }

/**
 * 删除纹理
 *
 * @param [i] tex 纹理id
 */
#define GLAPI_DelTexture(tex) \
{ glDeleteTextures(1, &tex); }

/**
 * 创建FrameBuffer，但不进行绑定
 *
 * @param [i] buf framebuffer id
 */
#define GLAPI_CreateFramebuf(buf) \
{ glCreateFramebuffers(1, &buf); }

/**
 * 创建并绑定FrameBuffer
 *
 * @param [i] buf framebuffer id
 */
#define GLAPI_CreateAndBindFrameBuf(buf) \
{  GLAPI_CreateFramebuf(buf); glBindFramebuffer(GL_FRAMEBUFFER, buf); }

/**
 * 创建纹理
 *
 * @param [i] tex 纹理ID引用
 */
#define GLAPI_CreateTexture2D(tex) \
{ glGenTextures(1, &tex); }

/**
 * 创建并绑定纹理
 *
 * @param [i] tex 纹理ID引用
 */
#define GLAPI_CreateAndBindTexture2D(tex) \
{ GLAPI_CreateTexture2D(tex); glBindTexture(GL_TEXTURE_2D, tex); }

/**
 * 解除纹理绑定
 */
#define GLAPI_UnbindTexture2D() \
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
#define GLAPI_LoadTexture2DImage(mipmap_level, width, height, imgformat, data) \
{ glTexImage2D(GL_TEXTURE_2D, mipmap_level, GL_RGB, width, height, 0, GL_RGB, imgformat, data); }

/**
 * 如果要使用多级渐远纹理必须手动设置所有不同的图像（不断递增GLAPI_LoadTexture2DImage的第一个参数）
 * 或者直接在生成纹理之后调用glGenerateMipmap。这会为当前绑定的纹理自动生成多级渐远纹理。
 *
 * <code>
 *     GLAPI_LoadTexture2DImage(0, width, height, GL_UNSIGNED_BYTE, data);
 *     GLAPI_GenMipmap2D();
 * </code>
 */
#define GLAPI_GenMipmap2D() { glGenerateMipmap(GL_TEXTURE_2D); }

/**
 * 设置S坐标轴的环绕方式（2D纹理的坐标轴有ST，和3D的XY是一样的）
 *
 * @param [i] mod 环绕方式
 */
#define GLAPI_Texture2D_WRAP_S_Parameteri(mod) \
{  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, mod); }

/**
 * 设置T坐标轴的环绕方式（2D纹理的坐标轴有ST，和3D的XY是一样的）
 *
 * @param [i] mod 环绕方式
 */
#define GLAPI_Texture2D_WRAP_T_Parameteri(mod) \
{  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, mod); }

/**
 * 设置BORDER_COLOR
 *
 * @param [i] color 设置边缘颜色
 */
#define GLAPI_Texture2DBorderColor(color) \
{  glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, color); }

/**
 * 设置2D纹理缩小过滤方式
 *
 * @param [i] filter 过滤方式
 */
#define GLAPI_Texture2D_Min_Filter_Parameteriv(filtermod) \
{  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filtermod); }

/**
 * 设置2D纹理放大过滤方式
 *
 * @param [i] filter 过滤方式
 */
#define GLAPI_Texture2D_Mag_Filter_Parameteriv(filtermod) \
{ glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filtermod); }

#ifdef __DEBUG__
/**
 * 画线
 */
#define GLAPI_DrawLineArrays(begin, count) \
{ glDrawArrays(GL_LINES, begin, count); }

/**
 * 通过索引画线
 */
#define GLAPI_DrawLineIndex(size, type) \
{ glDrawElements(GL_LINES, size, type, NULL); }

/**
 * 根据顶点数组画三角形
 */
#define GLAPI_DrawTriangleArrays(begin, count) \
{ glDrawArrays(GL_TRIANGLES, begin, count); }

/**
 * 通过索引画三角形
 */
#define GLAPI_DrawTriangleIndex(size, type) \
{ glDrawElements(GL_TRIANGLES, size, type, NULL); }
#endif

/**
 * 根据顶点数组画三角形
 */
#define GLAPI_DrawArray(mode, begin, count) \
{ glDrawArrays(mode, begin, count); }

/**
 * 通过索引画三角形
 */
#define GLAPI_DrawIndex(mode, size, type) \
{ glDrawElements(mode, size, type, NULL); }

// ----------------------------------------------------
// enable and disable

/** 多重采样抗锯齿 */
#define GLAPI_EnableMultisample() { glEnable(GL_MULTISAMPLE); }
#define GLAPI_DisableMultisample() { glDisable(GL_MULTISAMPLE); }

/** 颜色追踪 */
#define GLAPI_EnableColorMaterial() { glEnable(GL_COLOR_MATERIAL); }
#define GLAPI_DisableColorMaterial() { glDisable(GL_COLOR_MATERIAL); }

/** 深度测试 */
#define GLAPI_EnableDepthTest() { glEnable(GL_DEPTH_TEST); }
#define GLAPI_DisableDepthTest() { glDisable(GL_DEPTH_TEST); }

/** 获取GLFW Vendor */
const GLubyte* GLAPI_GetVendor();
/** 获取GLFW渲染信息 */
const GLubyte* GLAPI_GetRenderer();
/** 获取GLFW版本 */
const GLubyte* GLAPI_GetVersion();
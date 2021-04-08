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
#include <glm/gtc/type_ptr.hpp>

#define __glDeleteBuffer(buf)                                 { glDeleteBuffers(1, &buf); }
#define __glCreateArrayBuffer(buf, size, data, usage)         { glGenBuffers(1, &buf); glBindBuffer(GL_ARRAY_BUFFER, buf); \
                                                                  glBufferData(GL_ARRAY_BUFFER, size, data, usage); }
#define __glBindArrayBuffer(buf)                              { glBindBuffer(GL_ARRAY_BUFFER, buf); }
#define __glBindElemArrayBuffer(buf)                          { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buf); }
#define __glUnbindElemArrayBuffer()                           { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }
#define __glUnbindArrayBuffer()                               { glBindBuffer(GL_ARRAY_BUFFER, 0); }
#define __glBindProgram(prog)                                 { glUseProgram(prog); }
#define __glUnbindProgram()                                   { glUseProgram(0); }
#define __glUniform1i(prog, name, value)                      { glUniform1i(glGetUniformLocation(prog, name), value); }
#define __glUniformai(prog, name, count, values)              { glUniform1iv(glGetUniformLocation(prog, name), count, values); } // int array
#define __glUniform1f(prog, name, value)                      { glUniform1f(glGetUniformLocation(prog, name), value); }
#define __glUniform2f(prog, name, x, y)                       { glUniform2f(glGetUniformLocation(prog, name), x, y); }
#define __glUniform3f(prog, name, x, y, z)                    { glUniform3f(glGetUniformLocation(prog, name), x, y, z); }
#define __glUniform4f(prog, name, x, y, z, w)                 { glUniform4f(glGetUniformLocation(prog, name), x, y, z, w); }
#define __glUniformMatrix3fv(prog, name, mat3)                { glUniformMatrix3fv(glGetUniformLocation(prog, name), 1, GL_FALSE, glm::value_ptr(mat3)); }
#define __glUniformMatrix4fv(prog, name, mat4)                { glUniformMatrix4fv(glGetUniformLocation(prog, name), 1, GL_FALSE, glm::value_ptr(mat4)); }
#define __glDelFramebuf(buf)                                  { glDeleteFramebuffers(1, &buf); }
#define __glDelTexture(tex)                                   { glDeleteTextures(1, &tex); }
#define __glCreateFramebuf(buf)                               { glCreateFramebuffers(1, &buf); }
#define __glCreateAndBindFramebuf(buf, tar)                   {  __glCreateFramebuf(buf); glBindFramebuffer(GL_FRAMEBUFFER, buf); }
#define __glTextureGLenum(ms)                                 ( ms ? GL_TEXTURE_2D_MULTISAMPLE : GL_TEXTURE_2D )
#define __glGetVendor()                                       { glGetString(GL_VENDOR); }
#define __glGetRenderer()                                     { glGetString(GL_RENDERER); }
#define __glGetVersion()                                      { glGetString(GL_VERSION); }
#define __glEnableDepthTest()                                 { glEnable(GL_DEPTH_TEST); }
#define __glDisableDepthTest()                                { glDisable(GL_DEPTH_TEST); }
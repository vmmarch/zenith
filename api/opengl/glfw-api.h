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

#define __glDeleteBuffer__(bufs)                         { glDeleteBuffers(1, &bufs); }
#define __glCreateArrayBuffer__(bufs, size, data, usage) { glGenBuffers(1, &bufs); glBindBuffer(GL_ARRAY_BUFFER, bufs); glBufferData(GL_ARRAY_BUFFER, size, data, usage); }
#define __glBindArrayBuffer__(bufs)                      { glBindBuffer(GL_ARRAY_BUFFER, bufs); }
#define __glBindElemArrayBuffer__(bufs)                  { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufs); }
#define __glUnbindElemArrayBuffer__()                    { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }
#define __glUnbindArrayBuffer__()                        { glBindBuffer(GL_ARRAY_BUFFER, 0); }
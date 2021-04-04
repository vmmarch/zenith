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

/*! ===> Creates on 2021/4/4. <=== */

/*!
 * @author orvals
 */
#include "opengl-context.h"
#include <zenith.h>
#include <zenith/assert.h>

namespace zenith
{

    OpenGLContext::OpenGLContext(GLFWwindow *window) : m_Window(window)
    {
        __ZENITH_ASSERT__(window, __CREATE_OPENGL_CONTEXT_ERROR__)
    }

    void OpenGLContext::Initialize()
    {
        glfwMakeContextCurrent(m_Window);
        int success = gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);

        // print opengl info
        __ZENITH_ASSERT__(success, __INIT_GLAD_ERROR__)
        __ZENITH_INFO__(__OPENGL_INFO)
        __ZENITH_INFO__(__VENDOR_INFO__, glGetString(GL_VENDOR))
        __ZENITH_INFO__(__RENDER_INFO__, glGetString(GL_RENDER))
        __ZENITH_INFO__(__VERSION_INFO__, glGetString(GL_VERSION))

        __ZENITH_ASSERT__(GLVersion.major > 4 || (GLVersion.major == 4 && GLVersion.minor >= 5),
                          __OPENGL_SUPPORT_VERSION__)
    }

    void OpenGLContext::SwapBuffers() { glfwSwapBuffers(m_Window); }

}
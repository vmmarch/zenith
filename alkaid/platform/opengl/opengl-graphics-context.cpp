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

/*! ===> Creates on 2021/4/7. <=== */

/*!
 * @author 2B键盘
 */
#include "opengl-graphics-context.h"

namespace alkaid
{

    OpenGLGraphicsContext::OpenGLGraphicsContext(GLFWwindow* window)
    {
        this->window = window;
        initialize();
    }

    void OpenGLGraphicsContext::initialize()
    {
        glfwMakeContextCurrent(this->window);
        v_suc success = gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
        if(!success)
            __ALKAID_ERROR(__LOAD_GLAD_FAILED__);

        __ALKAID_INFO(__OPENGL_INFO__);
        __ALKAID_INFO(__VENDOR_INFO__, __glGetVendor());
        __ALKAID_INFO(__RENDER_INFO__, __glGetRender());
        __ALKAID_INFO(__VERSION_INFO__, __glGetVersion());
    }

    void OpenGLGraphicsContext::swap_buffers()
    {
        glfwSwapBuffers(this->window);
    }

}
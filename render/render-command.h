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
 * @author 2B键盘
 */
#pragma once
#include <zenith.h>
#include "render-api.h"

namespace zenith
{
    class RenderCommand
    {
    public:
        static void Initialize() { s_RenderAPI->Initialize(); }
        static void SetViewport(v_uint32t x, v_uint32t y, v_uint32t width, v_uint32t height)
        {
            s_RenderAPI->SetViewport(x, y, width, height);
        }

        static void SetClearColor(const glm::vec4& color)
        {
            s_RenderAPI->SetClearColor(color);
        }

        static void Clear()
        {
            s_RenderAPI->Clear();
        }
    private:
        static v_scope<RenderAPI> s_RenderAPI;
    };
}
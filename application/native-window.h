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

/*! ===> Creates on 2021/4/3. <=== */

/*!
 * @author 2B键盘
 */
#pragma once

#include <zenith.h>
#include "event.h"
#include <functional>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace zenith
{
    struct WindowProps
    {
        v_cc Title;
        int Width, Height;
    };

    typedef WindowProps v_winprops;

    class NativeWindow
    {
    public:
        using f_EventCallbackFn = std::function<void(Event&)>;
        virtual ~NativeWindow() = default;
        virtual void OnUpdate() = 0;
        virtual void GetSize(int &w, int &h) const = 0;
        virtual void SetEventCallbackFn(const f_EventCallbackFn &) = 0;
        virtual void SetVSync(bool) = 0;
        virtual bool GetVSync() = 0;
        virtual void CloseWindow()  = 0;
        virtual bool IsClose() const = 0;
        virtual void* GetWindowHandle() const = 0;
        static v_scope<NativeWindow> Create(const WindowProps &);
    };

}
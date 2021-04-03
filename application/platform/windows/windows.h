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
 * @author orvals
 */
#ifndef ZENITH_PLATFORM_WINDOWS_H
#define ZENITH_PLATFORM_WINDOWS_H

#include "window.h"

namespace zenith::platform::windows
{
    class Window : public WindowTemplate
    {
    public:
        Window(v_winprops&);
        ~Window();
        void Initialize(v_winprops&);
        void OnUpdate() override;
        void GetSize(int&, int&) const override;
        void SetEventCallbackFn(const f_EventCallbackFn&) override;
        void SetVSync(bool) override;
        bool GetVSync() override;
    private:
        struct WindowInfo
        {
            v_cc Title;
            v_uint Width, Height;
            bool VSync;

            f_EventCallbackFn EventCallback;
        };
        typedef WindowInfo v_info;

        v_info m_Info;
        GLFWwindow* m_Window;
    };
}

#endif // ===> ZENITH_PLATFORM_WINDOWS_H <===

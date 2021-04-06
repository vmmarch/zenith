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
#include "event/window-event.h"
#include <zenith/globalization.h>
#include <vector>
#include "event.h"
#include "layer/layer.h"
#include "native-window.h"

namespace zenith
{
    class Application
    {
    public:
        void OnEvent(Event&);
        bool WindowClose(WindowCloseEvent&);
        bool WindowResize(WindowResizeEvent&);
        void AddLayer(Layer&);
        void StartEngine();
        NativeWindow& GetWindow() { return *__window; }
    private:
        bool __Minimized = true;
        bool ___Running = true;
        v_scope<NativeWindow> __window;
    };
}
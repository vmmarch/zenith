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

/*! ===> Creates on 2021/4/6. <=== */

/*!
 * @author 2B键盘
 */
#pragma once

#include <zenith/type.h>
#include "window/window.h"
#include "event/event.h"
#include "render/camera.h"
#include "shader.h"
#include "event/mouse-event.h"
#include "sandbox/sandbox.h"

class Starter
{
public:
    Starter(zenith_char, int, int);

    ~Starter();

    void event(Event &); // 事件处理
    void domain();

    Window &GetWindow()
    { return *window; }

    // ===========================================================
    // event
    void close();

    void update(DeltaTime deltaTime);

    static Starter &instance()
    { return *__instance; }

private:
    void init_window(zenith_char, int, int);

private:
    int running = true;
    zenith_scope<Window> window;
    SandBox *sandbox;
    float last_frame_time = 0.0f;

    static Starter *__instance;
};
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

/*! ===> Creates on 2021/4/14. <=== */

/*!
 * @author 2B键盘
 */
#pragma once

#include "layer/layer.h"
#include <api/imgui-api.h>
#include "event/key-event.h"

namespace zenith
{
    class EditorLayer : public Layer
    {
    public:
        EditorLayer() : Layer("editor layer") {}

        void render() override;
        void update(DeltaTime) override;
        void event(Event&) override;
        void close() override;

    private:
        void initialize();
        void on_keypress(KeyPressedEvent&); // 处理键盘事件
    };
}
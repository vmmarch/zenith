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

/*! ===> Creates on 2021/4/23. <=== */

/*!
 * @author 2B键盘
 */
#pragma once

#include "layer/layer.h"
#include "render/renderer.h"
#include "layer/home-layer.h"
#include "layer/imgui-layer.h"
#include "tool/layer-vector.h"
#include "render/graphics-context.h"
#include "render/camera.h"
#include "render/renderer.h"
#include "window/window.h"

#include <vector>

namespace zenith
{

    class SandBox : public Layer
    {
    public:
        SandBox(Window* window);
        void render() override;
        void update(DeltaTime deltaTime) override;
        void event(Event&) override;
        void close() override {};

        /**
         * 绘制网格
         */
        void DrawGrid();
        void ClearColor(glm::vec4& color) { renderer->clear_color(color); }

    private:
        LayerStack layer_stack;
        ImGuiLayer* imlayer {};
        zenith_scope<Renderer> renderer;
        Camera camera;
        Window* window;
        float last_x, last_y;
        Layer* main_layer;
        bool cursor_hide = false;
    };

}
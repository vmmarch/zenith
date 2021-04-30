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
#pragma once

#include <zenith/type.h>
#include <render/renderer-config.h>
#include <api/glfw-api.h>
#include "buf/vertex-array.h"
#include "models/object.h"
#include "render/camera.h"

namespace zenith
{

    class Renderer
    {
    public:
        virtual ~Renderer() = default;

        // 设置清屏颜色
        virtual void clear_color(const glm::vec4& color) = 0;

        virtual void begin(Camera&) = 0;

        // 清屏
        virtual void clear() = 0;

        // 禁用深度测试
        virtual void disable_depth_test() = 0;

        // 开启深度测试
        virtual void enable_depth_test() = 0;

        // 渲染顶点数组
        virtual void DrawObjects() = 0;
        virtual void DrawObject(RenderObject&) = 0;
        virtual void DrawArray(const VertexArray&) = 0;
        virtual void DrawArray(const std::vector<VertexArray>&) = 0;
        virtual void DrawIndex(const VertexArray&) = 0;
        virtual void DrawIndex(const std::vector<VertexArray>&) = 0;

        // 画线
        virtual void DrawLines(RenderObject&) = 0;

        virtual std::vector<RenderObject> GetObjects() = 0;

        virtual RenderObject& GetObject0() = 0;
        virtual void submit(RenderObject&) = 0;

        // --------------------------------------------------
        // static

        // 创建渲染器
        static zenith_scope<Renderer> Create();

        // 获取当前API
        static render::api GetRenderAPI();

    private:
        std::vector<RenderObject> models;
        static render::api render_api;
    };

}
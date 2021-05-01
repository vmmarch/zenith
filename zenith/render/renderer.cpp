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
#include "renderer.h"
#include "tool/create-scope.h"

namespace zenith
{

    zenith_scope<AbsRenderer> Renderer::s_renderer = AbsRenderer::Create();

#ifdef __GLAPI
    render::api AbsRenderer::render_api = render::api::GL;
#elif __DXAPI
    #error ##NOT_SUPPORT_DIRECTX_API
#else
    #error ##PLEASE_CHOOSE_RENDER_API
#endif

    render::api AbsRenderer::GetRenderAPI()
    {
        return render_api;
    }

    zenith_scope<AbsRenderer> AbsRenderer::Create()
    {
        return __create_renderer();
    }

    // 设置清屏颜色
    void Renderer::clear_color(const glm::vec4 &color)
    {
        s_renderer->clear_color(color);
    }

    void Renderer::begin(Camera &camera)
    {
        s_renderer->begin(camera);
    }

    // 清屏
    void Renderer::clear()
    {
        s_renderer->clear();
    }

    // 渲染顶点数组
    void Renderer::DrawObjects()
    {
        s_renderer->DrawObjects();
    }

    void Renderer::DrawObject(RenderObject &object)
    {
        s_renderer->DrawObject(object);
    }

#ifdef __DEBUG__
    void Renderer::DrawArray(const VertexArray &array)
    {
        s_renderer->DrawArray(array);
    }

    void Renderer::DrawArray(const std::vector <VertexArray> &arrays)
    {
        s_renderer->DrawArray(arrays);
    }
#endif

    // 画线
    void Renderer::DrawLines(RenderObject &object)
    {
        s_renderer->DrawLines(object);
    }

    RenderObject& Renderer::GetObject0()
    {
        return s_renderer->GetObject0();
    }

    void Renderer::submit(RenderObject &object)
    {
        s_renderer->submit(object);
    }

}
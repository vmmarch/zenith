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
        return create_renderer();
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

    void Renderer::draw_models()
    {
        s_renderer->draw_models();
    }

    void Renderer::draw_model(Model &model)
    {
        s_renderer->draw_model(model);
    }

    void Renderer::submit(Model &model)
    {
        s_renderer->submit(model);
    }

}
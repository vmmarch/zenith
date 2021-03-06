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
#include <api/glfw-api.h>
#include "model/mesh.h"
#include <vector>

/**
 * 渲染图形上下文管理
 */
class GraphicsContext
{
public:
    virtual void swap_buffers() = 0; // 交换缓冲区

    /*! 获取当前选择的模型 */
    void SetCurrMesh(Mesh &model)
    {
        curr_model.reset(&model);
    }

    zenith_shared<Mesh> GetCurrModel()
    {
        return curr_model;
    }

    static GraphicsContext *instance()
    { return context; }

    static GraphicsContext *Create(zenith_any window);

private:
    zenith_shared<Mesh> curr_model;
    static GraphicsContext *context;
};
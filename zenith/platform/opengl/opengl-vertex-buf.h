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

/*! ===> Creates on 2021/4/20. <=== */

/*!
 * @author 2B键盘
 */
#pragma once

#include "buf/buf.h"

namespace zenith
{
    class OpenGLVertexBuf : public VertexBuf
    {
    public:
        OpenGLVertexBuf(v_ui32 size);
        OpenGLVertexBuf(float* buf, v_ui32 size);
        ~OpenGLVertexBuf() override;
        void bind() override;
        void unbind() override;
        void __data(float* buf, v_ui32 size) override;
        void __layout(const layout_t& layout) override { this->layout = layout; }
        const layout_t& __layout() const override { return layout; }

    private:
        v_ui32 render_id;
        layout_t layout;
    };

}
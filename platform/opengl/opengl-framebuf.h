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

#include "render/model/buf.h"

namespace zenith
{
    class OpenGLFramebuf : public buf::Framebuf
    {
    public:
        OpenGLFramebuf(const buf::FramebufSpecification &spec);

        virtual ~OpenGLFramebuf();

        void Invalidate();

        virtual void Bind() override;

        virtual void Unbind() override;

        virtual void Resize(v_uint32t width, v_uint32t height) override;

        virtual v_uint32t GetColorAttachmentRendererId(v_uint32t index = 0) const override { return __ColorAttachments[index]; }

        virtual const buf::FramebufSpecification& GetSpecification() const override { return __Specification; }

    private:
        v_uint32t __RendererId = 0;
        buf::FramebufSpecification __Specification;
        std::vector<buf::FramebufTextureSpecification> __ColorAttachmentSpecifications;
        buf::FramebufTextureSpecification __DepthAttachmentSpecification = buf::FramebufTextureFormat::None;
        std::vector<v_uint32t>  __ColorAttachments;
        v_uint32t __DepthAttachment = 0;
    };
}
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
#include "opengl-framebuf.h"
#include "tool/render-util.h"
#include <zenith/assert.h>

namespace zenith
{

    OpenGLFramebuf::OpenGLFramebuf(const buf::FramebufSpecification &spec)
            : __Specification(spec)
    {
        for (auto spec : __Specification.__Attachments.__Attachments)
        {
            if (!is_depth_format(spec.TextureFormat))
                __ColorAttachmentSpecifications.emplace_back(spec);
            else
                __DepthAttachmentSpecification = spec;
        }

        Invalidate();
    }

    OpenGLFramebuf::~OpenGLFramebuf()
    {
        __glDelFramebuf__(__RendererId);
        glDeleteTextures(__ColorAttachments.size(), __ColorAttachments.data());
        __glDelTexture__(__DepthAttachment);
    }

    void OpenGLFramebuf::Invalidate()
    {
        if (__RendererId)
        {
            __glDelFramebuf__(__RendererId);
            glDeleteTextures(__ColorAttachments.size(), __ColorAttachments.data());
            __glDelTexture__(__DepthAttachment);

            __ColorAttachments.clear();
            __DepthAttachment = 0;
        }

        __glCreateAndBindFramebuf__(__RendererId, GL_FRAMEBUFFER);
        bool multisample = __Specification.__Samples > 1;

        // Attachments
        if (__ColorAttachmentSpecifications.size())
        {
            __ColorAttachments.resize(__ColorAttachmentSpecifications.size());
            OpenGL::create_textures(multisample, __ColorAttachments.data(), __ColorAttachments.size());

            for (size_t i = 0; i < __ColorAttachments.size(); i++)
            {
                OpenGL::bind_texture(multisample, __ColorAttachments[i]);
                switch (__ColorAttachmentSpecifications[i].TextureFormat)
                {
                    case buf::FramebufTextureFormat::RGBA8:
                        OpenGL::attach_color_texture(__ColorAttachments[i], __Specification.__Samples, GL_RGBA8,
                                                  __Specification.__Width, __Specification.__Height, i);
                        break;
                }
            }
        }

        if (__DepthAttachmentSpecification.TextureFormat != buf::FramebufTextureFormat::None)
        {
            OpenGL::create_textures(multisample, &__DepthAttachment, 1);
            OpenGL::bind_texture(multisample, __DepthAttachment);
            switch (__DepthAttachmentSpecification.TextureFormat)
            {
                case buf::FramebufTextureFormat::DEPTH24STENCIL8:
                    OpenGL::attach_color_texture(__DepthAttachment, __Specification.__Samples, GL_DEPTH24_STENCIL8, GL_DEPTH_STENCIL_ATTACHMENT, __Specification.__Width, __Specification.__Height);
                    break;
            }
        }

        if (__ColorAttachments.size() > 1)
        {
            __ZENITH_ASSERT__(__ColorAttachments.size() <= 4, "");
            GLenum buffers[4] = { GL_COLOR_ATTACHMENT0, GL_COLOR_ATTACHMENT1, GL_COLOR_ATTACHMENT2, GL_COLOR_ATTACHMENT3 };
            glDrawBuffers(__ColorAttachments.size(), buffers);
        }
        else if (__ColorAttachments.empty())
        {
            // Only depth-pass
            glDrawBuffer(GL_NONE);
        }

        __ZENITH_ASSERT__(glCheckFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE, "Framebuffer is incomplete!");

        glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }

}
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

/*! ===> Creates on 2021/4/5. <=== */

/*!
 * @author 2B键盘
 */
#pragma once

#include "layer.h"
#include "event/key-event.h"
#include "render/camera/ortho-graphics-camera-controller.h"
#include "render/model/vec.h"
#include "render/shader/shader.h"

namespace zenith
{
    class EditorLayer : public Layer
    {
    public:
        EditorLayer();
        virtual ~EditorLayer() = default;

        virtual void OnAttach() override;
        virtual void OnDetach() override;

        void OnUpdate(Timestep timestep) override;
        virtual void OnImGuiRender() override;
        void OnEvent(Event&) override;

    private:
        OrthoGraphicsCameraController cameraController;

        // temp
        Ref<vec::VertexArray> __SquareVA;
        Ref<Shader> __FlatColorShader;
        Ref<buf::Framebuf> __Framebuf;

        void NewScene();
        void OpenScene();
        void SaveSceneAs();
        bool OnKeyPressed(KeyPressedEvent&);
    };
}
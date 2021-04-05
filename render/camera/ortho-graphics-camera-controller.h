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
#include "tool/timestep.h"
#include "event/mouse-event.h"
#include "event/window-event.h"
#include "render/camera/ortho-graphics-camera.h"

namespace zenith
{
    class OrthoGraphicsCameraController
    {
    public:
        OrthoGraphicsCameraController(float aspectRation, bool rotation = false);
        void OnUpdate(Timestep timestep);
        void OnEvent(Event&);

        void OnResize(float width, float height);

        OrthoGraphicsCamera& GetCamera() { return m_Camera; }
        const OrthoGraphicsCamera& GetCamera() const { return m_Camera; }

        float GetZoomLevel() const { return m_ZoomLevel; }
        float SetZoomLevel(float level) { return m_ZoomLevel = level; }

    private:
        float m_ZoomLevel = 1.0f;
        OrthoGraphicsCamera m_Camera;

        bool OnMouseScrolled(MouseScrolledEvent&);
        bool OnWindowResized(WindowResizeEvent&);
    };
}
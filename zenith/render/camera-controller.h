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

/*! ===> Creates on 2021/4/24. <=== */

/*!
 * @author 2B键盘
 */
#pragma once

#include "tool/timestep.h"
#include "event/event.h"
#include "event/mouse-event.h"
#include "event/key-event.h"
#include "event/window-event.h"
#include "camera.h"

namespace zenith
{
    class CameraController
    {
    public:
        explicit CameraController(float aspect_ratio);

        void event(Event&);
        void update(Timestep timestep);

        Camera& __camera() { return camera; }
        [[nodiscard]] const Camera& __camera() const { return camera; }

    private:
        void mouse_scrolled(MouseButtonScrolledEvent&);
        void window_resize(WindowResizeEvent&);

    private:
        float aspect_ratio{};
        float zoomlevel = 1.0f;

        float camera_rotation = 0.0f;
        float camera_rotation_speed = 1.0f;
        float camera_translation_speed = 1.0f;
        glm::vec3 position = { 0.0f, 0.0f, 0.0f };
        Camera camera;
    };
}
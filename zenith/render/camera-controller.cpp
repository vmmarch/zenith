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
#include "camera-controller.h"
#include "event/input.h"

namespace zenith
{
    CameraController::CameraController(float aspect_ratio)
            : camera(-aspect_ratio * zoomlevel, aspect_ratio * zoomlevel,
                     -zoomlevel, zoomlevel)
    {
    }

    void CameraController::update(Timestep timestep)
    {
        if (Input::pressed(ZN_KEY_A))
            position.x -= camera_translation_speed * timestep;
        if (Input::pressed(ZN_KEY_D))
            position.x += camera_translation_speed * timestep;
        if (Input::pressed(ZN_KEY_W))
            position.y -= camera_translation_speed * timestep;
        if (Input::pressed(ZN_KEY_S))
            position.y += camera_translation_speed * timestep;

        if (Input::pressed(ZN_KEY_Q))
            camera.__rotation((camera_rotation += camera_rotation_speed));
        if (Input::pressed(ZN_KEY_E))
            camera.__rotation((camera_rotation -= camera_rotation_speed));

        camera.__position(position);
    }

    void CameraController::event(Event &e)
    {
        if (e.__event_type() == event::type::EVENT_MOUSE_SCROLLED)
            mouse_scrolled(dynamic_cast<MouseButtonScrolledEvent &>(e));
        if (e.__event_type() == event::type::EVENT_WINDOW_RESIZE)
            window_resize(dynamic_cast<WindowResizeEvent &>(e));
    }

    void CameraController::mouse_scrolled(MouseButtonScrolledEvent &e)
    {
        zoomlevel -= e.__y();
        camera.__projection(-aspect_ratio * zoomlevel,aspect_ratio * zoomlevel,
                            -zoomlevel, zoomlevel);
    }

    void CameraController::window_resize(WindowResizeEvent &e)
    {
        aspect_ratio = (float) e.__width() / (float) e.__height();
        camera.__projection(-aspect_ratio * zoomlevel,aspect_ratio * zoomlevel,
                            -zoomlevel, zoomlevel);
    }
}

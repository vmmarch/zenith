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

/*! ===> Creates on 2021/4/9. <=== */

/*!
 * @author 2B键盘
 */
#pragma once

#include "event/event.h"

namespace alkaid
{
    class Layer
    {
    public:
        Layer(const v_cc name = "layer");
        virtual ~Layer() = default;
        virtual void on_render() = 0;
        virtual void on_update() = 0;
        virtual void on_event(Event&) = 0;
        virtual void on_close() = 0;

    protected:
        const v_cc debug_name;
    };
}
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

/*! ===> Creates on 2021/3/30. <=== */

/*!
 * @author orvals
 */
#include "component.h"

namespace zenith
{
    bool component::get_should_be_render()
    {
        return this->should_be_render;
    }

    void component::set_should_be_render(bool render)
    {
        this->should_be_render = render;
    }

    void component::set_comps_name(const char *name)
    {
        this->comps_name = name;
    }

    const char* component::get_comps_name()
    {
        return this->comps_name;
    }

}
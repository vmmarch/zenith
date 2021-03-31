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
#ifndef ZENITH_COMPONENT_H
#define ZENITH_COMPONENT_H

#include "layout.h"

class component
{
public:
    bool get_should_be_render();
    void set_should_be_render(bool render); // 是否渲染该组件，默认为true
    virtual void vrender() = 0;             // 渲染
private:
    bool should_be_render = true;
};


#endif //ZENITH_COMPONENT_H

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

/*! ===> Creates on 2021/4/21. <=== */

/*!
 * @author 2B键盘
 */
#pragma once

#include <zenith/type.h>

namespace zenith
{
    class VertexBuf
    {
    public:
        virtual ~VertexBuf() {};
        virtual void bind() = 0;
        virtual void unbind() = 0;
        virtual void set_data(float* vertex, v_ui32 size) = 0;

        static VertexBuf* __create(v_ui32);
        static VertexBuf* __create(float*, v_ui32);
    };

    class IndexBuf
    {
    public:
        virtual ~IndexBuf() {};
        virtual void bind() = 0;
        virtual void unbind() = 0;
        virtual v_ui32 size() const = 0;

        static IndexBuf* __create(v_ui32* indices, v_ui32 size);
    };

}
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

/*! ===> Creates on 2021/4/10. <=== */

/*!
 * @author 2B键盘
 */
#pragma once

namespace Arrays
{

    template<typename A>
    static int __array_len(A* array)
    {
        return sizeof(array) / sizeof(A);
    }

    template<typename E>
    class list
    {
    public:

        typedef void (*eachfn)(E);

        list()
        { this->elems = new E[16]; }

        list(int size) : v_size(size)
        {
            this->elems = new E[v_size];
        }

        void push(E &value)
        {
            __ensure_capacity_internal(10);

            this->elems[index_ptr] = value;
            index_ptr++;
        }

        E get(int index)
        {
            if(index > index_ptr)
                return 0;

            return this->elems[index];
        }

        int size()
        {
            return index_ptr;
        }

        void each(eachfn f)
        {
            int len = __len();
            for(int i = 0; i < len; i++)
            {
                f(elems[i]);
            }
        }

    private:
        zenith_uint v_size;
        zenith_uint index_ptr = 0;
        E *elems;

        // 确保容器内部有多余的空间
        void Setensure_capacity_internal(zenith_uint min_capacity)
        {
            int len = __len();
            if(min_capacity > len)
            {
                E __new_array[len + 16];
                memcpy(__new_array, elems, len * sizeof(E));
                this->elems = __new_array;
            }
        }

        // 获取数组大小
        zenith_uint __len()
        {
            return sizeof(this->elems) / sizeof(E);
        }
    };

}
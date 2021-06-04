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

/*! ===> Creates on 2021/5/5. <=== */

/*!
 * @author 2B键盘
 */
#pragma once


    /**
     * zenith matrix struct.
     */
    namespace zms
    {

        struct f2
        {
            float x, y;

            f2() {}
            f2(float _x, float _y) : x(_x), y(_y) {}

            float* array()
            {
                float *arr = new float[2];
                arr[0] = x;
                arr[1] = y;
                return arr;
            };
        };

        struct f3
        {
            float x, y, z;

            f3() {}
            f3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

            float* array()
            {
                float *arr = new float[3];
                arr[0] = x;
                arr[1] = y;
                arr[2] = z;
                return arr;
            }
        };

        struct i3
        {
            int r, g, b;
            i3() {}
            i3(int _r, int _g, int _b) : r(_r), g(_g), b(_b) {}
        };

        struct i4
        {
            int r, g, b, a;
            i4() {}
            i4(int _r, int _g, int _b, int _a) : r(_r), g(_g), b(_b), a(_a) {};
        };

        struct arr4i
        {
            i3
            a = { 0, 0, 0},
            b = { 0, 0, 0},
            c = { 0, 0, 0},
            d = { 0, 0, 0};

            arr4i() {}
            arr4i(i3 _a, i3 _b, i3 _c, i3 _d) : a(_a), b(_b), c(_c), d(_d) {}

            void add(int i, i3 p)
            {
                switch (i)
                {
                    case 0: a = p; break;
                    case 1: b = p; break;
                    case 2: c = p; break;
                    case 3: d = p; break;
                }
            }
        };

        struct face
        {
            i3
            x = { 0, 0, 0},
            y = { 0, 0, 0},
            z = { 0, 0, 0},
            a = { 0, 0, 0};

            face() {}
            face(i3 _x, i3 _y, i3 _z) : x(_x), y(_y), z(_z) {}
            face(i3 _x, i3 _y, i3 _z, i3 _a) : x(_x), y(_y), z(_z), a(_a) {}
        };

    }
}
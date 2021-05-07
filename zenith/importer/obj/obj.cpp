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
#include "obj.h"
#include <fstream>
#include <iostream>
#include <zenith_string.h>

namespace zenith
{

    zms::f3 getvec3(zenith_string *vers)
    {
        return zms::f3(vers[0].as_float(), vers[1].as_float(), vers[2].as_float());
    }

    zms::f2 getvec2(zenith_string *vers)
    {
        return zms::f2(vers[0].as_float(), vers[1].as_float());
    }

    RenderObject ObjImporter::read_object()
    {
        std::string line;
        std::fstream fs;
        fs.open(path, std::ios::in);
        if (!fs.is_open())
            ZENITH_ERROR("FILE cannot open! %s", path);

        // 顶点信息
        std::vector<zms::f3> __v;

        // uv坐标信息
        std::vector<zms::f2> __vt;

        // vn法线信息
        std::vector<zms::f3> __vn;

        // 顶点索引
        std::vector<int> __f;

        while (!fs.eof())
        {
            getline(fs, line);
            zenith_string s_line(line);

            // 解析顶点信息
            if (s_line.begin("v "))
            {
                s_line.remove(0, 2);
                zenith_string *vers = s_line.split(" ", 3);
                __v.push_back(getvec3(vers));
                continue;
            }

            if (s_line.begin("vt "))
            {
                s_line.remove(0, 3);
                zenith_string *vers = s_line.split(" ", 2);
                __vt.push_back(getvec2(vers));
                continue;
            }

            if (s_line.begin("vn "))
            {
                s_line.remove(0, 3);
                zenith_string *vers = s_line.split(" ", 3);
                __vn.push_back(getvec3(vers));
                continue;
            }

            if(s_line.begin("f "))
            {
                s_line.remove(0, 2);
                zenith_string *f4 = s_line.split(" ", 4);
                for(int i = 0; i < 4; i++)
                {
                    zenith_string f = f4[i];
                    zenith_string *index = f.split("/", 3);
                    __f.push_back(index[0].as_int());
                    __f.push_back(index[1].as_int());
                    __f.push_back(index[2].as_int());
                }
            }

        }

#ifdef __DEBUG__
        ZENITH_INFO("v size: %d", __v.size());
        ZENITH_INFO("vn size: %d", __vn.size());
        ZENITH_INFO("vt size: %d", __vt.size());
        ZENITH_INFO("f size: %d", __f.size());
#endif

//        VertexArray* array = VertexArray::Create();
//
//        int vsize = __v.size();
//        float vertices[vsize];
//        std::copy(__v.begin(), __v.end(), vertices);
//        array->AddVertexBuffer(vertices, __v.size());
//
//        int fsize = __f.size();
//        zenith_uint32 indices[fsize];
//        std::copy(__f.begin(), __f.end(), indices);
//        array->SetIndexBuffer(indices, fsize);

        RenderObject object(NULL, NULL);
        return object;
    }
}
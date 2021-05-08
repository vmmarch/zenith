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
        return zms::f3(vers[0].to_float(), vers[1].to_float(), vers[2].to_float());
    }

    zms::f2 getvec2(zenith_string *vers)
    {
        return zms::f2(vers[0].to_float(), vers[1].to_float());
    }

    Mesh ObjImporter::read_mesh()
    {
        std::string line;
        std::fstream fs;
        fs.open(path, std::ios::in);
        if (!fs.is_open())
            ZENITH_ERROR("FILE cannot open! %s", path);

        // 顶点信息
        std::vector<zms::f3> vertices;

        // uv坐标信息
        std::vector<zms::f2> vt;

        // vn法线信息
        std::vector<zms::f3> normals;

        // 顶点索引
        std::vector<zms::face> indices;

        while (!fs.eof())
        {
            getline(fs, line);
            zenith_string s_line(line);

            // 解析顶点信息
            if (s_line.begin("v "))
            {
                s_line.remove(0, 2);
                zenith_string *vers = s_line.split(" ", 3);
                vertices.push_back(getvec3(vers));
                continue;
            }

            if (s_line.begin("vt "))
            {
                s_line.remove(0, 3);
                zenith_string *vers = s_line.split(" ", 2);
                vt.push_back(getvec2(vers));
                continue;
            }

            if (s_line.begin("vn "))
            {
                s_line.remove(0, 3);
                zenith_string *vers = s_line.split(" ", 3);
                normals.push_back(getvec3(vers));
                continue;
            }

            if(s_line.begin("f "))
            {
                s_line.remove(0, 2);
                zenith_string *f4 = s_line.split(" ", 4);
                zms::face face;
                for(int i = 0; i < 4; i++)
                {
                    zenith_string f = f4[i];
                    zenith_string *index = f.split("/", 3);
                    zms::i3 i3 = { index[0].to_int(), index[1].to_int(), index[2].to_int() };
                    switch (i)
                    {
                        case 0: face.x = i3; break;
                        case 1: face.y = i3; break;
                        case 2: face.z = i3; break;
                        case 3: face.a = i3; break;
                    }
                }
                indices.push_back(face);
            }

        }

#ifdef __DEBUG__
        ZENITH_INFO("v size: %d", vertices.size());
        ZENITH_INFO("vn size: %d", normals.size());
        ZENITH_INFO("vt size: %d", vt.size());
        ZENITH_INFO("f size: %d", indices.size());
#endif

        VertexArray* array = VertexArray::Create();

        int size = vertices.size() * 3;
        float array_vertices[size];

        int offset = 0;
        int vsize = vertices.size();
        for(int i = 0; i < vsize; i++)
        {
            zms::f3 vertex_coord = vertices.at(i);
            array_vertices[offset]           = vertex_coord.x;
            array_vertices[(offset + 1)]     = vertex_coord.y;
            array_vertices[(offset + 2)]     = vertex_coord.z;
            offset += 3;
        }
        array->AddVertexBuffer(array_vertices, size);

//        int isize = indices.size();
//        zenith_uint32 index[isize];
//        std::copy(indices.begin(), indices.end(), index);
//        array->SetIndexBuffer(index, isize);

        Mesh mesh(array);
        return mesh;
    }
}
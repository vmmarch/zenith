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

/*! ===> Creates on 2021/4/26. <=== */

/*!
 * @author 2B键盘
 */
#include "obj-importer.h"
#include "japi/string.h"
#include "tool/file.h"

#include <fstream>
#include <iostream>

namespace zenith
{
    void ObjImporter::
    ReadFile(v_cc path)
    {
//        std::ifstream in(path, std::ios::in);
//        if(!in.is_open())
//        {
//            ZENITH_ERROR(READ_MODEL_ERROR, path);
//            return;
//        }

        read_line(path);

//        while(!in.eof())
//        {
//           if(line.StartWith("#")) continue;
//
//            // 读取顶点
//            if(line.StartWith("v"))
//            {
//                japi::string vertex_str = line.SubString(2);
//                japi::string* _vertexs = vertex_str.Split(" ", 3);
//                vertexs.push_back({ _vertexs[0].AsFloat(), _vertexs[1].AsFloat(), _vertexs[2].AsFloat() });
//            }
//        }
    }

    void ObjImporter::SetTextureFormFile(v_cc)
    {

    }
}

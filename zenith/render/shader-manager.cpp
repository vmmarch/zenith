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

/*! ===> Creates on 2021/5/9. <=== */

/*!
 * @author 2B键盘
 */
#include "shader-manager.h"

#include <io.h>

namespace zenith
{
    void ShaderManager::load_shaders(std::string folder)
    {
        long h_file             = 0; // 文件句柄
        struct _finddata_t      fileinfo;
        std::string p;

        if((h_file = _findfirst(p.assign(folder).append("/*-vfs").c_str(),&fileinfo)) !=  -1)
        {
            do
            {
                if(fileinfo.attrib & _A_SUBDIR)
                {
                    if(strcmp(fileinfo.name, ".") != 0  &&  strcmp(fileinfo.name, "..") != 0)
                        load_shaders(p.assign(folder).append("/").append(fileinfo.name).c_str());
                } else
                {
                    std::string np(folder);
                    zenith_char path = np.append("/").append(fileinfo.name).c_str();
                    shaders.insert(std::make_pair<std::string, ShaderProgram*>(fileinfo.name, ShaderProgram::Create(path)));
                }
            } while(_findnext(h_file, &fileinfo) == 0);
        }

        _findclose(h_file);
    }
}
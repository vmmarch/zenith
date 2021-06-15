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

#ifdef __ZENITH_PLATFORM_WINDOWS__
#   include <io.h>
#elif __ZENITH_PLATFORM_MACOS__
#   include <iostream>
#   include <dirent.h>
#   include <vector>
#   include <fstream>
#endif


void ShaderManager::load_shaders(const std::string &folder)
{
#ifdef __ZENITH_PLATFORM_WINDOWS__
    long h_file = 0; // 文件句柄
    struct _finddata_t fileinfo{};
    std::string p;

    if ((h_file = _findfirst(p.assign(folder).append("/*.vfs").c_str(), &fileinfo)) != -1)
    {
        do
        {
            if (fileinfo.attrib & _A_SUBDIR)
            {
                if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
                    load_shaders(p.assign(folder).append("/").append(fileinfo.name).c_str());
            } else
            {
                std::string np(folder);
                zenith_char path = np.append("/").append(fileinfo.name).c_str();
                shaders.insert(
                        std::make_pair<std::string, Shader *>(fileinfo.name, Shader::Create(path)));
            }
        } while (_findnext(h_file, &fileinfo) == 0);
    }
#elif __ZENITH_PLATFORM_MACOS__
    struct dirent *ptr;
    DIR *dir = opendir(folder.c_str());

    std::vector<std::string> files;

    while((ptr = readdir(dir)) != nullptr)
    {
        // 跳过"."和".."两个特殊目录
        if(ptr->d_name[0] == '.')
            continue;

        shaders.insert(std::make_pair<std::string, Shader*>(
                ptr->d_name, Shader::Create((folder + "/" + ptr->d_name).c_str())));
    }

    closedir(dir);
#endif
}

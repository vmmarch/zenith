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

/*! ===> Creates on 2021/5/18. <=== */

/*!
 * @author 2B键盘
 */
#pragma once

#include "FK-STRING.h"

namespace fkstd
{
    struct FK_FILE
    {
        FK_STRING path;

        FK_FILE(FK_STRING path)
        {
            this->path = path;
        }

        FK_FILE(const char* path)
        {
            FK_STRING path_t(path);
            this->path = path_t;
        }

        /**
         * @return The folder where the file is located.
         */
        const char* get_base_path()
        {
            std::string direction;
            const size_t last_slash_idx = path.rfind('/');
            if (std::string::npos != last_slash_idx)
            {
                direction = path.substring(0, last_slash_idx).c_str();
            }

            return direction.c_str();
        }

        /**
         * @return file name.
         */
        const char* get_filename()
        {
            std::string direction;
            const size_t last_slash_idx = path.rfind('/');
            if (std::string::npos != last_slash_idx)
            {
                direction = path.substring(last_slash_idx + 1, path.size()).c_str();
            }

            return direction.c_str();
        }

        /**
         * @return file expand.
         */
        const char* get_expand()
        {
            int index = path.find_last_of("/");
            return path.substring(index, path.size()).c_str();
        }
    };
}
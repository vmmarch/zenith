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

/*! ===> Creates on 2021/4/18. <=== */

/*!
 * @author 2B键盘
 */
#pragma once

#include <string>
#include <cstring>
#include <stdarg.h>
#include <vector>

template<typename... Args>
std::string __format(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);

    bool s_bracket = false;

    int charlen = strlen(fmt);
    int append_v_len = 0;
    std::string process;
    for (int i = 0; i < charlen; i++)
    {
        char c = fmt[i];
        process.append(&c);

        if (s_bracket)
        {
            if (c == '}')
            {
                process.replace((append_v_len + i - 1), 2, "");
                // FIXED int转string异常
                const char *append_v = va_arg(args, const char*);
                process.append(append_v);
                append_v_len += strlen(append_v) - 2;
            }

            s_bracket = false;
            continue;
        }

        if (c == '{')
            s_bracket = true;

    }

    va_end(args);

    return process;
}
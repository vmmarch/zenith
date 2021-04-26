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
#include "string.h"
#include <sstream>
#include <vector>

namespace japi
{

    void string::Delete(int begin, int end)
    {
        value = value.erase(begin, end);
    }

    japi::string string::SubString(int begin)
    {
        return value.substr(begin, Size());
    }

    japi::string string::SubString(int begin, int end)
    {
        return value.substr(begin, end);
    }

    japi::string* string::Split(const char* word, int size)
    {
        japi::string *splits = new japi::string[size];
        std::string::size_type pos1, pos2;
        pos1 = 0, pos2 = value.find(word);

        int count = 0;
        while (std::string::npos != pos2)
        {
            splits[count] = value.substr(pos1, pos2 - pos1);
            pos1 = pos2 + 1;
            pos2 = value.find(word, pos1);
            count++;
        }

        splits[count] = value.substr(pos1);

        return splits;
    }

    std::vector<japi::string> string::Split(const char* word)
    {
        std::vector<japi::string> splits;
        std::string::size_type pos1, pos2;
        pos1 = 0, pos2 = value.find(word);

        while (std::string::npos != pos2)
        {
            splits.push_back(value.substr(pos1, pos2 - pos1));
            pos1 = pos2 + 1;
            pos2 = value.find(word, pos1);
        }

        splits.push_back(value.substr(pos1));

        return splits;
    }

    bool string::StartWith(std::string start)
    {
        return value.compare(0, start.size(), start) == 0;
    }

    bool string::EndWith(std::string end)
    {
        int size = value.size();
        return value.compare((size - end.size()), size, end) == 0;
    }

    int string::Size()
    {
        return value.size();
    }

    int string::AsInt()
    {
        return toType<int>();
    }

    bool string::AsBool()
    {
        return toType<bool>();
    }

    float string::AsFloat()
    {
        return toType<float>();
    }

    template<typename Type> Type string::toType()
    {
        std::istringstream iss(value);
        Type number;
        iss >> number;

        return number;
    }

}
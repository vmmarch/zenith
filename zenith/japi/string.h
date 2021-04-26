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
#pragma once

#include <vector>
#include <string>

namespace japi
{
    class string
    {
    public:
        string() {}

        string(std::string str)
        { value = str; }

        /**
         * 删除字符串
         *
         * @param begin 开始下标
         * @return      截取后的字符串
         */
        void Delete(int begin, int end);

        /**
         * 截取字符串，结束下标默认为String的size()
         *
         * @param begin 开始下标
         * @return      截取后的字符串
         */
        japi::string SubString(int begin);

        /**
         * 截取字符串，通过开始下标和结束下标来截取
         *
         * @param begin 开始下标
         * @param end   结束下标
         * @return      截取后的字符串
         */
        japi::string SubString(int begin, int end);

        /**
         * 判断字符串的开始是不是从param[i]开始的
         *
         * @param [i] start 开始字符串
         * @return          如果字符串的开始字符是param[i], 那么返回true，否则反之。
         */
        bool StartWith(std::string);

        /**
         * 判断字符串的结束是不是param[i].
         *
         * @param [i] end 结束字符串
         * @return        如果字符串的结束字符是param[i], 那么返回true，否则反之。
         */
        bool EndWith(std::string);

        /**
         * 截取字符串，从param[i]开始。当然这个返回的vector。
         * 如果你知道字符分割后的具体大小那么你可以使用Split(v_cc, int).
         *
         * @param [i] word 分割字符串
         * @return         分割后的数组
         */
        std::vector<japi::string> Split(const char*);

        /**
         * 截取字符串，从param[i]开始。返回数组
         *
         * @param [i] word 分割字符串
         * @param [i] size 数组大小
         * @return         分割后的数组
         */
        japi::string* Split(const char*, int);

        /**
         * @return const char数组
         */
        const char* GetConstCharArray()
        { return value.c_str(); }

        /**
         * @return char数组
         */
        char* GetCharArray()
        { return const_cast<char*>(value.c_str()); }

        /**
         * @return 返回当前字符串大小
         */
        int Size();

        /**
         * 将当前String对象转为Int
         */
        int AsInt();

        /**
         * 将当前String对象转为Bool
         */
        bool AsBool();

        /**
         * 将当前String对象转为Float
         */
        float AsFloat();

        std::string &GetOriginStdStringRef()
        { return value; }

        void format(...);

    private:
        std::string value;
        template<typename Type> Type toType();
    };
}
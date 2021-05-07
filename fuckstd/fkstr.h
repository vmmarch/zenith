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

/*! ===> Creates on 2021/4/27. <=== */

/*!
 * @author 2B键盘
 */
#ifndef FUCKSTD_STRING_H
#define FUCKSTD_STRING_H

#include <cstring>
#include <sstream>
#include <stdarg.h>
#include <vector>

namespace fuckstd
{

    static int c_size(const char* cv)
    {
        return strlen(cv);
    }

    class fk_string
    {
    public:
        fk_string() { this->value = ""; }

        explicit fk_string(char* _value) { this->value = _value; }

        explicit fk_string(const char* _value) { this->value = _value; }

        explicit fk_string(std::string _value) { this->value = _value; }

        void operator=(char* _value) { this->value = _value; }

        void operator=(const char* _value) { this->value = _value; }

        void operator=(std::string _value) { this->value = _value; }

        /**
         * delete string.
         *
         * @param begin start index
         */
        void remove(int begin, int end)
        {
            value = value.erase(begin, end);
        }

        /**
         * substring, end index default string size.
         *
         * @param begin start index
         * @return      intercepted string
         */
        fk_string substring(int begin)
        {
            return fk_string(value.substr(begin, size()));
        }

        /**
         * substring，by begin index and end index.
         *
         * @param begin start index
         * @param end   end index
         * @return      intercepted string
         */
        fk_string substring(int begin, int end)
        {
            return fk_string(value.substr(begin, end));
        }

        /**
         * string begin is start_cvalue.
         *
         * @param start_cvalue begin string.
         * @return             if begin string is start_value that return true, else false.
         */
        int begin(const char *start_cvalue)
        {
            return value.compare(0, c_size(start_cvalue), start_cvalue) == 0;
        }

        /**
         * string end is end_cvalue.
         *
         * @param end_cvalue end string.
         * @return           if end string is end_value that return true, else false.
         */
        int end(const char *end_cvalue)
        {
            int _size = size();
            return value.compare((_size - c_size(end_cvalue)), _size, end_cvalue) == 0;
        }

        /**
         * Intercepted string, but you need known array size.
         *
         * @param char_value  for this intercepted.
         * @param size        array size
         * @return            char* array
         */
        fk_string* split(const char *char_value, int size)
        {
            fk_string *splits = new fk_string[size];
            std::string::size_type pos1, pos2;
            pos1 = 0, pos2 = value.find(char_value);

            int count = 0;
            while (std::string::npos != pos2)
            {
                splits[count] = value.substr(pos1, pos2 - pos1);
                pos1 = pos2 + 1;
                pos2 = value.find(char_value, pos1);
                count++;
            }

            splits[count] = value.substr(pos1);

            return splits;
        }

        /**
         * Get char*[].
         */
        const char *c_str()
        {
            return value.c_str();
        }

        /**
         * current string size.
         */
        int size() { return value.size(); }

        /**
         * to int.
         */
        int as_int() { return to_type<int>(); }

        /**
         * to bool.
         */
        bool as_bool() { return to_type<bool>(); }

        /**
         * to float.
         */
        float as_float() { return to_type<float>(); }

        /**
         * append string.
         *
         * @param cvalue  append string value.
         */
        void append(const char *cvalue)
        {
            if(*cvalue != 0)
                value.append(cvalue);
        }

        /**
         * format current string.
         *
         * @param ... the variable parameters.
         */
        void format(...)
        {
            va_list args;
            va_start(args, 0);

            char* _value = const_cast<char*>(c_str());
            size_t len = _vscprintf(_value, args) + 1;
            std::vector<char> vbuf(len, '\0');
            int nwrite = _vsnprintf_s(&vbuf[0], vbuf.size(), len, _value, args);
            if(nwrite > 0)
                this->value = &vbuf[0];

            va_end(args);

            free(args);
        }

        /**
         * Clear current string.
         */
        void clear() { value.clear(); }

    private:

        /**
         * type conversion.
         *
         * @tparam Type     like int, float
         * @return          type is param Type value.
         */
        template<typename Type> Type to_type()
        {
            std::istringstream iss(value.c_str());
            Type type;
            iss >> type;

            return type;
        }

    private:
        std::string value;
    };
}

#endif
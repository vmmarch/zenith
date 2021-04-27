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

namespace fuckstd
{

    static int c_size(const char* cv)
    {
        return strlen(cv);
    }

    class String
    {
    public:
        String() { reload_property(""); }

        String(char* _value) { reload_property(_value); }

        String(const char* _value) { reload_property(_value); }

        /**
         * delete string.
         *
         * @param begin start index
         */
        void __delete(int begin, int end)
        {
            if(end < begin)
                throw "end cannot ge begin.";

            if(begin == 0)
            {
                int nv_size = v_size - (end - begin);
                char* nv = (char*) malloc(nv_size);
                strcpy(nv, value + end);
                reload_property(nv);
            } else
            {
                char* a = (char*) malloc(begin);
                strncpy(a, value, begin);

                char *b = (char*) malloc(v_size - end);
                strcpy(b, value+end);

                clear(); append(a); append(b);

                free(a); free(b);
            }
        }

        /**
         * substring, end index default string size.
         *
         * @param begin start index
         * @return      intercepted string
         */
        String substring(int begin)
        {
            return *this;
        }

        /**
         * substring，by begin index and end index.
         *
         * @param begin start index
         * @param end   end index
         * @return      intercepted string
         */
        String substring(int begin, int end)
        {
            return *this;
        }

        /**
         * string begin is start_cvalue.
         *
         * @param start_cvalue begin string.
         * @return             if begin string is start_value that return true, else false.
         */
        int start_with(const char *start_cvalue)
        {
            return 0;
        }

        /**
         * string end is end_cvalue.
         *
         * @param end_cvalue end string.
         * @return           if end string is end_value that return true, else false.
         */
        int end_with(const char *end_cvalue)
        {

        }

        /**
         * Intercepted string, but you need known array size.
         *
         * @param char_value  for this intercepted.
         * @param size        array size
         * @return            char* array
         */
        char **split(const char *char_value, int size)
        {
            return nullptr;
        }

        /**
         * Get char*[].
         */
        char *get_char_array()
        {
            return value;
        }

        /**
         * current string size.
         */
        int size() { return v_size; }

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
            int csize = c_size(cvalue);
            char *nv = (char*) malloc(csize + v_size);

            strcpy(nv, value);
            strcpy(nv + v_size, cvalue);

            // reassign
            reload_property(nv);
        }

        /**
         * format current string.
         *
         * @param ... the variable parameters.
         */
        void format(...)
        {

        }

        /**
         * Clear current string.
         */
        void clear()
        {
            reload_property("");
        }

    private:

        /**
         * type conversion.
         *
         * @tparam Type     like int, float
         * @return          type is param Type value.
         */
        template<typename Type> Type to_type()
        {
            std::istringstream iss(value);
            Type type;
            iss >> type;

            return type;
        }

        void reload_property(const char* _value)
        {
            reload_property(const_cast<char*>(_value));
        }

        void reload_property(char* _value)
        {
            if(value != NULL)
                delete[] &value;

            this->value = _value;
            this->v_size = c_size(value);
        }

    private:
        char   *value = NULL;
        int     v_size = 0;
    };
}

#endif
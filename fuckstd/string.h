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

#ifdef __cplusplus
extern "C" {
#endif

struct STRING
{
    /**
     * delete string.
     *
     * @param begin start index
     */
    void __delete(int begin, int end);

    /**
     * substring, end index default string size.
     *
     * @param begin start index
     * @return      intercepted string
     */
    STRING substring(int begin);

    /**
     * substring，by begin index and end index.
     *
     * @param begin start index
     * @param end   end index
     * @return      intercepted string
     */
    STRING substring(int begin, int end);

    /**
     * string begin is start_cvalue.
     *
     * @param start_cvalue begin string.
     * @return             if begin string is start_value that return true, else false.
     */
    bool start_with(const char* start_cvalue);

    /**
     * string end is end_cvalue.
     *
     * @param end_cvalue end string.
     * @return           if end string is end_value that return true, else false.
     */
    bool end_with(const char* end_cvalue);

    /**
     * Intercepted string, but you need known array size.
     *
     * @param char_value  for this intercepted.
     * @param size        array size
     * @return            char* array
     */
    char** split(const char *char_value, int size);

    /**
     * Get char*[].
     */
    char *get_char_array();

    /**
     * current string size.
     */
    int size();

    /**
     * to int.
     */
    int as_int();

    /**
     * to bool.
     */
    bool as_bool();

    /**
     * to float.
     */
    float as_float();

    /**
     * format current string.
     *
     * @param ... the variable parameters.
     */
    void format(...);

private:
    char* value;
};

#ifdef __cplusplus
};
#endif

#endif
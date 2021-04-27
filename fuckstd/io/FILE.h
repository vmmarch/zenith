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
#ifndef FUCKSTD_FILE_H
#define FUCKSTD_FILE_H

/**
 * file status, invalid&checked
 */
enum status
{
    INVALID, CHECKED
};

/**
 * FILE
 */
typedef struct FILE
{
    const char *path;
    enum status path_status;

    /**
     * check file path is invalid.
     * @return true: path is checked, false else.
     */
    int is_invalid()
    {
        return path_status == status::CHECKED;
    }

    /**
     * Get file name, not absolute path.
     * @return file name
     */
    const char* get_name()
    {
        return "";
    }

    // --------------------------------------------------
    // path operation.

    bool is_absolute()
    {
        return 0;
    }

    const char* get_absolute_path()
    {
        return "";
    }

} FILE;

/**
 * open file
 *
 * @param __fp file point
 * @return is open success.
 */
int fopen(FILE* __fp)
{
    return 0;
}

/**
 * Read the file is to end of file.
 *
 * @param __fp file point.
 * @return true or false
 */
int eof(FILE* __fp)
{
    return 0;
}

#endif
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
#ifndef ZENITH_FILE_H
#define ZENITH_FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <zenith/type.h>

#define MAX_LINE_BUF 1024

#ifdef __cplusplus
extern "C" {
#endif

void read_line(const char *path)
{
    FILE *fp;
    char buf[MAX_LINE_BUF];
    int count = 1;

    if ((fp = fopen(path, "r")) == NULL)
        ZENITH_INFO("File Read Failed: %s", path);

    while (!feof(fp))
    {
        fgets(buf, MAX_LINE_BUF, fp);
        printf("%s", buf);
    }
}

#ifdef __cplusplus
};
#endif

#endif
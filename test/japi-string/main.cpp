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

/*! ===> Creates on 2021/4/22. <=== */

/*!
 * @author 2B键盘
 */
#include "japi/string.h"
#include <stdio.h>

int main()
{
    japi::string str("v 0.005369267 0.623752 0.0064940881");

    // -------------------------------------------------------、
    // 字符串开始字符判断
    bool startWith_V = str.StartWith("v");
    if(startWith_V)
        printf("start with v: %d\n", startWith_V);

    // -------------------------------------------------------、
    // 字符串结束字符判断
    bool endWith_881 = str.StartWith("v");
    if(endWith_881)
        printf("end with 881: %d\n", endWith_881);

    // -------------------------------------------------------、
    //删除字符和分割
    str.Delete(0, 2);
    japi::string* splits = str.Split(" ", 4);

    for(int i = 0; i < 3; i++)
        printf("[%d] - %s\n", i, splits[i].GetCharArray());

    return 0;
}
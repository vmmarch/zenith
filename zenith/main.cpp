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

/*! ===> Creates on 2021/4/1. <=== */

/*!
 * @author 2B键盘
 */
#include "init/starter.h"
#include <iostream>

int main(int argc, char **argv)
{

#ifdef __ZENITH_PLATFORM_WINDOWS__
#   ifdef __ZENITH_IN_CHINA__
    system("chcp 65001");
#   endif
#endif

    auto app = new zenith::Starter("zenith", 1260, 880);
    app->main_cycle();

    return 0;
}




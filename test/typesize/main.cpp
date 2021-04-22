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
#include <iostream>

int main()
{
    std::cout << "char = "              << sizeof(char) << "\n";
    std::cout << "int = "               << sizeof(int) << "\n";
    std::cout << "short = "             << sizeof(short) << "\n";
    std::cout << "short int = "         << sizeof(short int) << "\n";
    std::cout << "unsigned int = "      << sizeof(unsigned int) << "\n";
    std::cout << "long = "              << sizeof(long) << "\n";
    std::cout << "float = "             << sizeof(float) << "\n";
    std::cout << "uint8_t = "           << sizeof(uint8_t) << "\n";
    std::cout << "uint16_t = "          << sizeof(uint8_t) << "\n";
    std::cout << "uint32_t = "          << sizeof(uint8_t) << "\n";
    std::cout << "void* = "             << sizeof(void*) << "\n";

    return 0;
}
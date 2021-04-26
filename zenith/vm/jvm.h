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

#include <jvm.h>
#include <zenith/type.h>
#include <japi/string.h>
#include <Windows.h>

#define SIG_LJAVA_LANG_STRING_V "([Ljava/lang/String;)V"

namespace zenith
{
    class JVM
    {
    private:
        JVM(v_cc jar);
    public:
        static void CreateJVM(v_cc jar);

        static JVM* GetJVM() { return jvm_instance; }

        /**
         * 调用Java函数
         */
        void CallFunction(v_cc classname, v_cc funcname);
        void CallStaticFunction(v_cc classname, v_cc funcname);

        /**
         * 销毁JVM释放内存
         */
        static void Destroy();
    private:
        JavaVM *jvm = nullptr;
        JNIEnv *env = nullptr;
        HMODULE hModule;
        static JVM* jvm_instance;
    };
}

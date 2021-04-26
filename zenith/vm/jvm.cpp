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
#include "jvm.h"

namespace zenith
{
    JVM *JVM::jvm_instance      = nullptr;

    JVM::JVM(v_cc jar)
    {
        /* 设置 JVM 参数 */
        JavaVMInitArgs vmArgs;
        vmArgs.version = JNI_VERSION_1_8;
        const int OPTION_COUNT = 2;
        vmArgs.nOptions = OPTION_COUNT;
        JavaVMOption options[OPTION_COUNT] = { 0 };
        // classpath 指定为我们要调用的 jar 包路径
        options[0].optionString = const_cast<char*>("-Djava.class.path=D:\\project\\alkaid\\jar\\jnitest.jar");
        options[1].optionString = const_cast<char*>("-Xmx1024m");  // 最大堆大小
        vmArgs.options = options;
        vmArgs.ignoreUnrecognized = JNI_TRUE;
        /* 启动 JVM */
        hModule = LoadLibrary(TEXT("D:\\env\\Java\\jdk1.8.0_172\\jre\\bin\\server\\jvm.dll"));
        typedef jint (JNICALL *CreateJavaVMFuncPtr)(JavaVM **pvm, void **penv, void *args);
        CreateJavaVMFuncPtr CreateJavaVM = (CreateJavaVMFuncPtr)GetProcAddress(hModule, "JNI_CreateJavaVM");
        jint ret = (*CreateJavaVM)(&jvm, (void**)&env, &vmArgs);
        /* 调用 class */
        // 找到 class
        jclass class_Test = env->FindClass("com/test/Main");
        jmethodID methodId_main = env->GetStaticMethodID(class_Test, "main", "([Ljava/lang/String;)V");
        env->CallStaticVoidMethod(class_Test, methodId_main, "");

        jvm_instance = this;
    }

    void JVM::CreateJVM(v_cc jar)
    {
        new JVM(jar);
    }

    void JVM::CallFunction(v_cc classname, v_cc funcname)
    {
        /* 调用 class */
        // 找到 class
        jclass class_Test = env->FindClass(classname);
        jmethodID methodId_main = env->GetMethodID(class_Test, funcname, SIG_LJAVA_LANG_STRING_V);
        env->CallStaticVoidMethod(class_Test, methodId_main, "");
    }

    void JVM::CallStaticFunction(v_cc classname, v_cc funcname)
    {
        /* 调用 class */
        // 找到 class
        jclass vmclass = env->FindClass(classname);
        jmethodID methodId = env->
                (env->GetObjectClass(vmclass), funcname, "(II)I");
        if(methodId == NULL)
            ZENITH_INFO("method id is null.");

        jint v = env->CallIntMethod(vmclass, methodId, 1, 1);
        ZENITH_INFO("call v: %d", v);
    }

    void JVM::Destroy()
    {
        // 释放资源
        GetJVM()->jvm->DestroyJavaVM();
        FreeLibrary(GetJVM()->hModule);
    }

}
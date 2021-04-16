﻿/*! ************************************************************************
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

/*! ===> Creates on 2021/4/14. <=== */

/*!
 * 模型读取
 * @author 2B键盘
 */
#pragma once

#include <windows.h>
#include <commdlg.h>
#include <zenith/type.h>

/**
 * 打开文件选择窗口
 */
static void __open_folder(v_cc& code)
{

	OPENFILENAME __ofn; // 对话框结构体
	TCHAR sizef[MAX_PATH]; // 保存获取文件名称的缓冲区

	// 初始化选择文件对话框
	ZeroMemory(&__ofn, sizeof(OPENFILENAME));
	__ofn.lStructSize = sizeof(OPENFILENAME);
	__ofn.hwndOwner = NULL;
	__ofb.lpstrFile = sizef;
	__ofn.lpstrFile[0] = '\0';
	__ofn.nMaxFile = sizeof(sizef);
	__ofn.lpstrFilter = "All(*.*)\0*.*\0Text(*.txt)\0*.TXT\0\0";
	__ofn.nFilterIndex = 1;
	__ofn.lpstrFileTitle = NULL;
	__ofn.nMaxFileTitle = 0;
	__ofn.lpstrInitialDir = NULL;
	__ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

	// 显示打开文件对话窗口
	if(GetOpenFileName(&__ofn))
	{
		// 显示选择的文件
		OutputDebugString(sizef);
		OutputDebugString("\r\n");
	}

}

namespace zenith
{

    class ModelObject
    {
     public:
        ModelObject(v_cc path);
        ~ModelObject() = default;

        /**
         * 渲染模型
         *
         * @param [i] x x坐标
         * @param [i] y y坐标
         * @param [i] z z坐标
         */
        void draw(int, int, int);
    }

}

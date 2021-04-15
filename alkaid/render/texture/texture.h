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

/*! ===> Creates on 2021/4/14. <=== */

/*!
 * @author 2B键盘
 */
#pragma once

#define WRAP_S 0
#define WRAP_T 1

namespace alkaid
{

	enum surrmod
	{
		NONE,
		REPEAT, // 默认环绕方式，重复纹理图像
		MIRRORED_REPEAT, // 和上面那个相同，只是每次纹理是镜像放置的。
		CLMAP_TO_EDGE, // 纹理坐标会被约束在0到1之间，超出的部分会重复纹理坐标的边缘，产生一种边缘被拉伸的效果。
		CLMAP_TO_BORDER // 超出的坐标为用户指定的边缘颜色
	}

    class Texture2D
    {
    public:
		/**
		 * @param [i] mod 纹理环绕方式
		 * @param [i] coor 坐标设置
		 * @param [i] color 颜色
		 */
		void set_mod(surrmod, int, float* = NULL);
		
    };

}
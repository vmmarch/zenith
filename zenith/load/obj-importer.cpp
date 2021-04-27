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
#include "obj-importer.h"

#include <fkstr.h>
#include <fstream>
#include <iostream>

namespace zenith
{
	void ObjImporter::
		ReadFile(v_cc path)
	{
		std::ifstream in(path, std::ios::in);
		if (!in.is_open())
		{
			ZENITH_ERROR(READ_MODEL_ERROR, path);
			return;
		}

		while (!in.eof())
		{
			fuckstd::string line;
			if (line.start_with("#")) continue;

			// 读取顶点
			if (line.start_with("v"))
			{
				fuckstd::string vertex_str = line.substring(2);
                fuckstd::string* _vertexs = vertex_str.split(" ", 3);
				vertexs.push_back({ _vertexs[0].as_float(), _vertexs[1].as_float(), _vertexs[2].as_float() });
			}
		}
	}

	void ObjImporter::SetTextureFormFile(v_cc)
	{

	}
}

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

/*! ===> Creates on 2021/4/16. <=== */

/*!
 * @author 2B键盘
 */
#include "render/2d/texture/texture.h"

namespace zenith
{
	class OpenGLTexture2D : public Texture2D
	{
	public:
		void read_image(zenith_char) override;
		void bind() override;
		void unbind() override;
		void SetMod(zenith_ui16, int, float* = NULL) override;
		void SetFilter(int, zenith_ui16) override;

	private:
	    zenith_uint texture_id;
	    zenith_uchar* image_data; // 纹理图片数据
	    int width, height, nrchannels; // 纹理图片大小
	};
}
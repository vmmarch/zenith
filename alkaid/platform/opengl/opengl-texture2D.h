/**/
#include "render/2d/texture/texture.h"

namespace alkaid
{
	class OpenGLTexture2D : public Texture2D
	{
	public:
		void read_image(v_cc) override;
		void bind() override;
		void unbind() override;
		void set_mod(surrmod, int, float* = NULL) override;
		void set_filter(int, filtermod) override;

	private:
	    v_ui1 texture_id;
	    v_uc* image_data; // 纹理图片数据
	    int width, height, nrchannels; // 纹理图片大小
	};
}
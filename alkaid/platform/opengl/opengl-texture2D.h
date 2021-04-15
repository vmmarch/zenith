/**/
#include "render/texture/texture.h"

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
	};
}
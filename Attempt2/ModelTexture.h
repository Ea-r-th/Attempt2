#include "Renderer.h"
#include <vendors/stb_image.h>

class ModelTexture {

private:

	GLuint ID;
	std::string filePath;
	unsigned char* buffer;
	int width, height;

public:

	ModelTexture(const std::string& filePath);
	~ModelTexture();

	void bind(unsigned int slot = 0);
	void unbind();

	inline int getWidth() const { return width; }
	inline int getHeight() const { return height; }
};
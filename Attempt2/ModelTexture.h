#pragma once

#include <GLFW/glfw3.h>
#include <iostream>
#include <vendors/stb_image.h>

class ModelTexture {

private:

	GLuint ID;

public:

	ModelTexture(GLuint textureID) 
	: ID(textureID) {};
	~ModelTexture()
	{};

	void bind(unsigned int slot = 0);
	void unbind();

	//No idea why these are here, I'm keeping them in case I need them eventually (They were originally unused local variables)
	//inline int getWidth() const { return width; }
	//inline int getHeight() const { return height; }

	GLuint getID() const { return ID; }
};
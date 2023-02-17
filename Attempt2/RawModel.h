#pragma once

#include <glad/glad.h>

class RawModel {

public:

	RawModel(GLuint ID = 0, GLuint vertexCount = 0);

	GLuint getVaoID();
	GLuint getVertexCount();

private:

	GLuint vaoID;
	GLuint vertexCount;

};

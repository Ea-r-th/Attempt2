#pragma once

#include <glad/glad.h>

class RawModel {

private:

	GLuint vaoID;
	GLuint vertexCount;

public:

	RawModel(GLuint ID = 0, GLuint vertexCount = 0)
		: vaoID(ID), vertexCount(vertexCount) {};

	GLuint getVaoID() const { return vaoID; }
	GLuint getVertexCount() const { return vertexCount; }

};

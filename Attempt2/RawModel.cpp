#include "RawModel.h"

RawModel::RawModel(GLuint ID, GLuint vertexCount)
	: vaoID(ID), vertexCount(vertexCount) {

}

GLuint RawModel::getVaoID() {return vaoID;}

GLuint RawModel::getVertexCount() {return vertexCount;}
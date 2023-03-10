#pragma once

#include <glad/glad.h>
#include "RawModel.h"
#include "ModelTexture.h"

class TexturedModel {

private:

	RawModel rawModel;
	ModelTexture modelTexture;

public:

	TexturedModel(RawModel model, ModelTexture modelTexture)
		: rawModel(model), modelTexture(modelTexture) {};

	GLuint getVaoID() const { return rawModel.getVaoID(); }
	GLuint getVertexCount() const { return rawModel.getVertexCount(); }
	RawModel getRawModel() const { return rawModel; }
	ModelTexture getModelTexture() const { return modelTexture; }
	GLuint getTextureID() const { return modelTexture.getID(); }
};
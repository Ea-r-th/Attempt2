#pragma once

#include "ShaderProgram.h"

class StaticShader : public ShaderProgram {

public:
	StaticShader();

	virtual void bindAttributes() override;

	void getAllUniformLocations() override;

	//Uniform loaders, called in the render method
	void loadTransformationMatrix(mat4 transformationMatrix);
	void loadProjectionMatrix(glm::mat4 projectionMatrix);
	void loadViewMatrix(Camera camera);
	void loadTime(double time);
};

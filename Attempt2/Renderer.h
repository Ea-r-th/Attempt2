#pragma once

#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include "StaticShader.h"
#include "RawModel.h"
#include "StaticShader.h"
#include "Matrices.h"
#include "Engine.h"
#include "Entity.h"
#include <iostream>

using vec3 = glm::vec3;

class Renderer {

private:

	mat4 projectionMatrix;
	StaticShader shader;

public:

	Renderer(StaticShader shader, mat4 projectionMatrix);

	void render(Entity entity);

};


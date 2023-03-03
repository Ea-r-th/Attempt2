#pragma once

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "RawModel.h"
#include "ShaderProgram.h"
#include <iostream>
#include <vector>

namespace Engine{

	//Display Functions

	const int DISPLAY_WIDTH = 800;
	const int DISPLAY_HEIGHT = 600;
	const int MAX_FPS = 120;

	void initDisplay();

	GLFWwindow* createWindow(int width, int height);

	void setViewport(GLFWwindow* window);

	//\\Display Functions

	
	//Renderer functions

	//\\Renderer functions

	
	//Loader functions

	RawModel loadToVao(GLfloat* positions, GLsizeiptr posSize, GLuint* indices, GLsizeiptr eboSize);

	void cleanUp();

	//\\Loader functions

	//Math Functions --> I'd like to move this to a math/tools dedicated namespace eventually, but I don't really feeeeel like it right now

	vec3 calcDirection(float x, float y);

	//\\Math functions
}
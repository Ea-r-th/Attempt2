#include "Engine.h"
#include <iostream>
#include <GLFW/glfw3.h>

//Initializes glfw
void Engine::initDisplay() {
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
}

//Creates and window and working openGL context, then makes the context current. Takes in a width and a height.
GLFWwindow* Engine::createWindow(int width, int height) {
	GLFWwindow* window = glfwCreateWindow(width, height, "Attempt 2", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create window, terminating program" << std::endl;
		glfwTerminate();
		return NULL;
	}

	return window;
}

//Called every frame, sets the viewport and clears the color before rendering. Called before draw calls
void Engine::setViewport(GLFWwindow* window) {
	glViewport(0, 0, 800, 600);

	glClearColor(0.4f, 0.5f, 1.0f, 1.0f);		
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
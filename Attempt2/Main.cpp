#define GLFW_INCLUDE_NONE
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include<glm/glm.hpp>
#include<glm/gtc/type_ptr.hpp>
#include<glm/gtc/matrix_transform.hpp>

#include "Engine.h"
#include "ShaderProgram.h"
#include "RawModel.h"
#include "StaticShader.h"
#include "Renderer.h"
#include "Player.h"

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

//Defines hardcoded vertices of a cube
GLfloat vertices[]{

	-0.5f, 0.5f, -0.5f,
	-0.5f, -0.5f, -0.5f,
	0.5f, -0.5f, -0.5f,
	0.5f, 0.5f, -0.5f,

	-0.5f, 0.5f, 0.5f,
	-0.5f, -0.5f, 0.5f,
	0.5f, -0.5f, 0.5f,
	0.5f, 0.5f, 0.5f,

	0.5f, 0.5f, -0.5f,
	0.5f, -0.5f, -0.5f,
	0.5f, -0.5f, 0.5f,
	0.5f, 0.5f, 0.5f,

	-0.5f, 0.5f, -0.5f,
	-0.5f, -0.5f, -0.5f,
	-0.5f, -0.5f, 0.5f,
	-0.5f, 0.5f, 0.5f,

	-0.5f, 0.5f, 0.5f,
	-0.5f, 0.5f, -0.5f,
	0.5f, 0.5f, -0.5f,
	0.5f, 0.5f, 0.5f,

	-0.5f, -0.5f, 0.5f,
	-0.5f, -0.5f, -0.5f,
	0.5f, -0.5f, -0.5f,
	0.5f, -0.5f, 0.5f
};

// Indices for vertices order
GLuint indices[] =
{
	0,1,3,
	3,1,2,
	4,5,7,
	7,5,6,
	8,9,11,
	11,9,10,
	12,13,15,
	15,13,14,
	16,17,19,
	19,17,18,
	20,21,23,
	23,21,22
};

int main() {

	Engine::initDisplay();

	GLFWwindow* window = Engine::createWindow(Engine::DISPLAY_WIDTH, Engine::DISPLAY_HEIGHT);

	glfwMakeContextCurrent(window);

	gladLoadGL();

	glfwSetKeyCallback(window, keyCallback);
	glfwSetInputMode(window, GLFW_STICKY_KEYS, 0);


	double prevTime = glfwGetTime();



	RawModel model = Engine::loadToVao(vertices, sizeof(vertices), indices, sizeof(indices));
	Entity entity(model, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f);

	StaticShader shader;

	mat4 projectionMatrix = createProjectionMatrix(70.0f, Engine::DISPLAY_WIDTH, Engine::DISPLAY_HEIGHT, 0.0f, 500.0f);
	Renderer renderer(shader, projectionMatrix);

	Player player(model, 0.0f, 0.0f, 2.0f, 0.0f, 0.0f); //The model is not rendered, I am disregarding the model part for now

	shader.Start();


	//Main game loop//

	while (!glfwWindowShouldClose(window)) {

		Engine::setViewport(window);

		shader.loadViewMatrix(player.camera);

		double currentTime = glfwGetTime();
		if (currentTime - prevTime >= 1 / Engine::MAX_FPS)
			//\\Time based calculations go here

			shader.loadTime(currentTime);
			
			prevTime = currentTime;
			
			//\\Time based calculations go here

			player.move(window);

		renderer.render(entity);

		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	shader.cleanUp();

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	//camera.move(window, action, key);
}
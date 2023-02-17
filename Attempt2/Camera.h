#pragma once
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>

using vec3 = glm::vec3;
using mat4 = glm::mat4x4;

class Camera{

private:

	vec3 position = vec3(0.0f, 0.0f, 0.0f);
	vec3 rotation = vec3(0.0f, 0.0f, 0.0f);

public:

	Camera(float x, float y, float z, float pitch, float yaw);

	void move(GLFWwindow* window, int action, int key);
	void rotate();
	void getInput(GLFWwindow* window);

	vec3 getPosition();
	vec3 getRotation();
};


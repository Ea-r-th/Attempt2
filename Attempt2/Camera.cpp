#include "Camera.h"
#include <iostream>


float zSpeed = 0.05f;
float xSpeed = 0.04f;
float rotationSpeed = 2.0f;
float ySpeed = 0.04f;

Camera::Camera(float x, float y, float z, float pitch, float yaw) {

	this->position = vec3(x, y, z);
	this->rotation = vec3(pitch, yaw, 0.0f);

}

void Camera::move(GLFWwindow* window, int action, int key) {

	if (key == GLFW_KEY_W)
		position.z -= zSpeed;
	if (key == GLFW_KEY_A)
		position.x -= xSpeed;
	if (key == GLFW_KEY_S)
		position.z += zSpeed;
	if (key == GLFW_KEY_D)
		position.x += xSpeed;
	if (key == GLFW_KEY_LEFT)
		rotation.x -= rotationSpeed;
	if (key == GLFW_KEY_RIGHT)
		rotation.x += rotationSpeed;
	if (key == GLFW_KEY_UP)
		rotation.y -= rotationSpeed;
	if (key == GLFW_KEY_DOWN)
		rotation.y += rotationSpeed;
	if (key == GLFW_KEY_SPACE)
		position.y += ySpeed;
	if (key == GLFW_KEY_LEFT_CONTROL)
		position.y -= ySpeed;
}

void Camera::getInput(GLFWwindow* window) {

	if (glfwGetKey(window, GLFW_KEY_W))
		position.z -= zSpeed;
	if (glfwGetKey(window, GLFW_KEY_A))
		position.x -= xSpeed;
	if (glfwGetKey(window, GLFW_KEY_S))
		position.z += zSpeed;
	if (glfwGetKey(window, GLFW_KEY_D))
		position.x += xSpeed;
	if (glfwGetKey(window, GLFW_KEY_LEFT))
		rotation.x -= rotationSpeed;
	if (glfwGetKey(window, GLFW_KEY_RIGHT))
		rotation.x += rotationSpeed;
	if (glfwGetKey(window, GLFW_KEY_UP))
		rotation.y -= rotationSpeed;
	if (glfwGetKey(window, GLFW_KEY_DOWN))
		rotation.y += rotationSpeed;
	if (glfwGetKey(window, GLFW_KEY_SPACE))
		position.y += ySpeed;
	if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL))
		position.y -= ySpeed;

}

void Camera::rotate() {

}

vec3 Camera::getPosition() {

	return position;
}

vec3 Camera::getRotation() {

	return rotation;

}
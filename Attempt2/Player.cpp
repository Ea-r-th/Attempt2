#include "Player.h"
#include "Engine.h"

float speed = 0.05f;
float strafeSpeed = 0.04f;
float rotationSpeed = 0.5f;
float ySpeed = 0.04f;

//For child reference: Child class can take in more params, but must all be defined in header. Pass these params into parent constructor
Player::Player(RawModel model, float posX, float posY, float posZ, float pitch, float yaw)
	: Entity(model, posX, posY, posZ, pitch, yaw),
	camera(posX, posY, posZ, pitch, yaw)
{
}

void Player::move(GLFWwindow* window) {

	float x = direction.x;
	float z = direction.z;
	glm::vec2 planeDirection = glm::normalize(glm::vec2(x, z));
	float xFactor = planeDirection.x;
	float zFactor = planeDirection.y;

	if (glfwGetKey(window, GLFW_KEY_W)) {
		position.z += speed * zFactor;
		position.x += speed * xFactor;
	}
	if (glfwGetKey(window, GLFW_KEY_A)) {
		position.z -= speed * xFactor;
		position.x += speed * zFactor;
	}
	if (glfwGetKey(window, GLFW_KEY_S)) {
		position.z -= speed * zFactor;
		position.x -= speed * xFactor;
	}
	if (glfwGetKey(window, GLFW_KEY_D)) {
		position.z += speed * xFactor;
		position.x -= speed * zFactor;
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT)) {
		rotation.x += rotationSpeed;
	}
	if (glfwGetKey(window, GLFW_KEY_RIGHT)) {
		rotation.x -= rotationSpeed;
	}
	if (glfwGetKey(window, GLFW_KEY_UP) && rotation.y < 89.5) {
		rotation.y += rotationSpeed;
	}
	if (glfwGetKey(window, GLFW_KEY_DOWN) && rotation.y > -89.5) {
		rotation.y -= rotationSpeed;
	}
	if (glfwGetKey(window, GLFW_KEY_SPACE)) {
		position.y += ySpeed;
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL)) {
		position.y -= ySpeed;
	}



	direction = Engine::calcDirection(glm::radians(rotation.x), glm::radians(rotation.y));
	camera.direction = direction; //Is this the most efficient way to do this? I'd like to have both cameras be the same but can't use inheritence.
	camera.setPosition(position);

}

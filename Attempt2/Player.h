#pragma once
#include "Entity.h"
#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GLFW/glfw3.h>
#include "TexturedModel.h"
#include "Camera.h"

using vec3 = glm::vec3;

class Player : public Entity {

public:

	Player(TexturedModel model, float posX, float posY, float posZ, float pitch, float yaw);
	void move(GLFWwindow* window);

	Camera camera;

};
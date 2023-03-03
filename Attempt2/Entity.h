#pragma once

#include "RawModel.h"
#include <glm/glm.hpp>
#include <glm/vec3.hpp>

using vec3 = glm::vec3;

class Entity {

protected:

	RawModel model;
	vec3 position;
	vec3 rotation;
	vec3 direction = vec3(0.0f,0.0f,-1.0f);
	
public: 

	Entity(RawModel model, float posX, float posY, float posZ, float pitch, float yaw);

	void move(float amtX, float amtY, float amtZ);

	void rotate(float pitch, float yaw);

	float getX();
	float getY();
	float getZ();
	float getRotX();
	float getRotY();
	RawModel getRawModel();

};

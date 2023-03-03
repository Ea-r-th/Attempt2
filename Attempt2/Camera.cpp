#include "Camera.h"
#include <iostream>

vec3 calcDirection(float x, float y);

Camera::Camera(float x, float y, float z, float pitch, float yaw) {

	this->position = vec3(x, y, z);
	this->rotation = vec3(pitch, yaw, 0.0f);
	this->direction = vec3(0.0f, 0.0f, -1.0f);

}

//Creates a direction vector to be used in the glm::lookat function, determines where the camera is looking

void Camera::rotate() {

}

vec3 Camera::getPosition() {

	return position;
}

vec3 Camera::getRotation() {

	return rotation;

}

vec3 Camera::getDirection() {

	return direction;

}

void Camera::setPosition(vec3 newPosition) {
	position = newPosition;
}
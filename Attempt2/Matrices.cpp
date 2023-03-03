#include "Matrices.h"
#include <iostream>

vec3 upVec = vec3(0.0f, 1.0f, 0.0f);
vec3 direction(0.0f, 0.0f, -1.0f); //Direction of the camera when starting the game

mat4 createProjectionMatrix(GLfloat FOV, float displayWidth, float displayHeight, float nearPlane, float farPlane) {

	mat4 projectionMatrix = mat4(1.0f);

	//All of this will be added to the options class later
	projectionMatrix = glm::perspective(glm::radians(45.0f), (float)800 / 600, 0.1f, 100.0f);
	return projectionMatrix;
}

//Matrix for the camera position and view direction
mat4 createViewMatrix(Camera camera)
{

	mat4 viewMatrix(1.0f); //Empty 4x4 matrix

	direction = camera.getDirection(); //Gets direction the camera is facing for lookat

	viewMatrix = glm::translate(viewMatrix, -camera.getPosition());  

	//First argument is camera position, second argument is a 3D vector specifying the target, and the third argument is the up vector
	viewMatrix = glm::lookAt(camera.getPosition(), camera.getPosition() + camera.getDirection(), vec3(0, 1, 0));

	return viewMatrix;
}

//Creates a transformationMatrix for a VAO, literally don't worry about how it works
mat4 createTransformationMatrix(vec3 position, vec3 rotation) {

	mat4 transformationMatrix = mat4(1.0f);
	transformationMatrix = glm::translate(transformationMatrix, position);
	transformationMatrix = glm::rotate(transformationMatrix, glm::radians(rotation.x), vec3(1.0f, 0.0f, 0.0f));
	transformationMatrix = glm::rotate(transformationMatrix, glm::radians(rotation.y), vec3(0.0f, 1.0f, 0.0f));

	return transformationMatrix;
}

#include "Matrices.h"

vec3 upVec = vec3(0.0f, 1.0f, 0.0f);

mat4 createProjectionMatrix(GLfloat FOV, float displayWidth, float displayHeight, float nearPlane, float farPlane) {
	
	mat4 projectionMatrix = mat4(1.0f);
	projectionMatrix = glm::perspective(glm::radians(45.0f), (float)800 / 600, 0.1f, 100.0f);
	return projectionMatrix;
}


//Matrix for the camera position
mat4 createViewMatrix(Camera camera)
{
	mat4 viewMatrix = mat4(1.0f);
	viewMatrix = glm::translate(viewMatrix, -camera.getPosition());
	viewMatrix = glm::rotate(viewMatrix, glm::radians(camera.getRotation().x), vec3(0.0f, 1.0f, 0.0f));
	viewMatrix = glm::rotate(viewMatrix, glm::radians(camera.getRotation().y), vec3(1.0f, 0.0f, 0.0f));
	//viewMatrix = glm::lookAt(position, target, upVec); <- To be done when camera is done

	return viewMatrix;
}

mat4 createTransformationMatrix(vec3 position, vec3 rotation) {

	mat4 transformationMatrix = mat4(1.0f);
	transformationMatrix = glm::translate(transformationMatrix, position);
	transformationMatrix = glm::rotate(transformationMatrix, glm::radians(rotation.x), vec3(1.0f, 0.0f, 0.0f));
	transformationMatrix = glm::rotate(transformationMatrix, glm::radians(rotation.y), vec3(0.0f, 1.0f, 0.0f));

	return transformationMatrix;
}
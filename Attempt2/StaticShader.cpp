#include "StaticShader.h"
#include <iostream>


const char* VERTEX_FILE = "vertex.glsl";
const char* FRAGMENT_FILE = "fragment.glsl";

GLint location_transformationMatrix;
GLint location_projectionMatrix;
GLint location_viewMatrix;
GLint location_time;

StaticShader::StaticShader() : ShaderProgram(VERTEX_FILE, FRAGMENT_FILE) {

	//In Java, these functions would be called in the parent constructor. However, C++ does not encourage calling overwritten virtual functions from parent constructors.
	getAllUniformLocations();
	bindAttributes();

}

//Binds VAO attribute to the location specified with the name recognized by the shader
void StaticShader::bindAttributes() {

	bindAttribute(0, "position");
}

//Assigns uniform names to the uniform locations. The uniform names in the shaders must match these.
void StaticShader::getAllUniformLocations() {
	location_transformationMatrix = glGetUniformLocation(ID, "transformationMatrix");
	location_projectionMatrix = getUniformLocation("projectionMatrix");
	location_viewMatrix = getUniformLocation("viewMatrix");
	location_time = getUniformLocation("time");
}

//Calls the glUniform method passing the location gotten from glGetUniformLocation. Technically only needs 2 lines of code, this makes it easier to create and upload uniforms from the renderer.
void StaticShader::loadTransformationMatrix(mat4 transformationMatrix) {
	loadMatrix(location_transformationMatrix, transformationMatrix);
}

void StaticShader::loadProjectionMatrix(mat4 projectionMatrix) {
	loadMatrix(location_projectionMatrix, projectionMatrix);
}

//Loads a viewmatrix based on the camera's position
void StaticShader::loadViewMatrix(Camera camera) {
	mat4 viewMatrix = createViewMatrix(camera);
	loadMatrix(location_viewMatrix, viewMatrix);
}

void StaticShader::loadTime(double time) {
	float ftime = (float)time;
	loadFloat(location_time, ftime);
}
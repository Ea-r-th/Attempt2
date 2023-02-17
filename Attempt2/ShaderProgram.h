#pragma once

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <glm/glm.hpp>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Matrices.h"

using String = std::string;

String get_file_contents(const char* filename);

class ShaderProgram {

private:
	GLuint vertexShader;
	GLuint fragmentShader;

public:

	GLuint ID;

	ShaderProgram(const char* vertexFile, const char* fragmentFile);

	void Start();
	void Stop();

	void compileErrors(GLuint shader, const char* type);

	void cleanUp();

protected:

	virtual void getAllUniformLocations();

	virtual void bindAttributes();
	virtual void bindAttribute(GLuint attribLocation, const GLchar* attribName);

	int getUniformLocation(const GLchar* uniformName);

	void loadFloat(GLint location, float f);
	void loadInt(GLuint location, int i);
	void loadBool(GLuint location, bool b);

	void loadVector2(GLuint location, glm::vec2 vec);
	void loadVector3(GLuint location, glm::vec3 vec);
	void loadMatrix(GLuint location, const glm::mat4 mat);
};
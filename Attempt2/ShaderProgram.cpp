#include "ShaderProgram.h"
#include <iostream>

GLuint ID;// Reads a text file and outputs a string with everything in the text file
std::string get_file_contents(const char* filename)
{
	std::ifstream in(filename, std::ios::binary);
	if (in)
	{
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return(contents);
	}
	throw(errno);
}

// Constructor that build the Shader Program from 2 different shaders
ShaderProgram::ShaderProgram(const char* vertexFile, const char* fragmentFile)
{
	// Read vertexFile and fragmentFile and store the strings
	std::string vertexCode = get_file_contents(vertexFile);
	std::string fragmentCode = get_file_contents(fragmentFile);

	// Convert the shader source strings into character arrays
	const char* vertexSource = vertexCode.c_str();
	const char* fragmentSource = fragmentCode.c_str();

	// Create Vertex Shader Object and get its reference
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	// Attach Vertex Shader source to the Vertex Shader Object
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	// Compile the Vertex Shader into machine code
	glCompileShader(vertexShader);
	// Checks if Shader compiled succesfully
	compileErrors(vertexShader, "VERTEX");

	// Create Fragment Shader Object and get its reference
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	// Attach Fragment Shader source to the Fragment Shader Object
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	// Compile the Vertex Shader into machine code
	glCompileShader(fragmentShader);
	// Checks if Shader compiled succesfully
	compileErrors(fragmentShader, "FRAGMENT");

	// Create Shader Program Object and get its reference
	ID = glCreateProgram();
	// Attach the Vertex and Fragment Shaders to the Shader Program
	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);
	// Wrap-up/Link all the shaders together into the Shader Program
	glLinkProgram(ID);
	// Checks if Shaders linked succesfully
	compileErrors(ID, "PROGRAM");

	//Calls bindAttributes method, binding the attributes to be passed into the vertex shader

	// Delete the now useless Vertex and Fragment Shader objects
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

}

//Binds VAO attributes to the shader program in the specified layout position
void ShaderProgram::bindAttributes() {}

void ShaderProgram::bindAttribute(GLuint attribLocation, const GLchar* attribName) {

	glBindAttribLocation(ID, attribLocation , attribName);

}

void ShaderProgram::getAllUniformLocations() {}

int ShaderProgram::getUniformLocation(const GLchar* uniformName) {
	return  glGetUniformLocation(ID, uniformName);
}

void ShaderProgram::loadFloat(GLint location, GLfloat f) {
	glUniform1f(location, f);
}

void ShaderProgram::loadBool(GLuint location, bool b) {
	if (true)
		glUniform1i(location, 1);
	else
		glUniform1i(location, 0);
}

void ShaderProgram::loadInt(GLuint location, GLint i) {
	glUniform1i(location, i);
}

void ShaderProgram::loadVector2(GLuint location, glm::vec2 vec){
	glUniform2f(location, vec.x, vec.y);
}

void ShaderProgram::loadVector3(GLuint location, glm::vec3 vec) {
	glUniform3f(location, vec.x, vec.y, vec.z);
}

void ShaderProgram::loadMatrix(GLuint location, const glm::mat4 mat) {

	glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(mat));
}

// Activates the Shader Program
void ShaderProgram::Start()
{
	glUseProgram(ID);
}

// Deletes the Shader Program
void ShaderProgram::Stop()
{
	glUseProgram(NULL);
}

// Checks if the different Shaders have compiled properly
void ShaderProgram::compileErrors(GLuint shader, const char* type)
{
	// Stores status of compilation
	GLint hasCompiled;
	// Character array to store error message in
	char infoLog[1024];
	if (type != "PROGRAM")
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &hasCompiled);
		if (hasCompiled == GL_FALSE)
		{
			glGetShaderInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "SHADER_COMPILATION_ERROR for:" << type << "\n" << infoLog << std::endl;
		}
	}
	else
	{
		glGetProgramiv(shader, GL_LINK_STATUS, &hasCompiled);
		if (hasCompiled == GL_FALSE)
		{
			glGetProgramInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "SHADER_LINKING_ERROR for:" << type << "\n" << infoLog << std::endl;
		}
	}
}

void ShaderProgram::cleanUp() {

	Stop();
	glDetachShader(ID, vertexShader);
	glDetachShader(ID, fragmentShader);
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	glDeleteProgram(ID);

}
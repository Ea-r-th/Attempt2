#include "Engine.h"

//Function definitions, since these are only used by this class they are not defined in engine.h
GLuint createVao();
void unbindVao();
void storeDataInAttribList(int attribNumber, GLfloat* data, GLsizeiptr vboSize);
void bindEBO(GLuint* indices, GLsizeiptr eboSize);
void bindEBO(GLuint* indices, GLsizeiptr eboSize);


//Creates lists of vaos and vbos to be deleted
std::vector<GLuint> vaoList;
std::vector<GLuint> vboList;
std::vector<GLuint> texList;

//Creates a texture
ModelTexture Engine::createModelTexture(const char* filePath) {

	int width, height, colorChannelCount;
	GLuint ID;

	unsigned char* bytes = stbi_load(filePath, &width, &height, &colorChannelCount, 0);

	glGenTextures(1, &ID);

	texList.emplace_back(ID);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, ID); //Bind texture to apply parameters

	//These are just parameters for the texture, not important
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	//This is all hardcoded, may need to change later
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, colorChannelCount, GL_UNSIGNED_INT, bytes);
	glGenerateMipmap(GL_TEXTURE_2D);

	//Unbinds image and frees data
	stbi_image_free(bytes);
	glBindTexture(GL_TEXTURE_2D, 0);

	return ModelTexture(ID);  
}

//Creates a vao, then binds vbos and an ebo to that vao, then returns a rawmodel.

RawModel Engine::loadToVao(GLfloat* positions, GLsizeiptr posSize, GLfloat* textureCoords, GLsizeiptr texCoordsSize, GLuint* indices, GLsizeiptr eboSize) {

	GLuint ID = createVao();

	bindEBO(indices, eboSize);
	storeDataInAttribList(0, positions, posSize);
	storeDataInAttribList(1, textureCoords, texCoordsSize);

	unbindVao();
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	return RawModel(ID, (int)eboSize);
}


//Creates a vao, adds it to the list of vaos, then binds and returns its ID
GLuint createVao() {

	GLuint ID;
	vaoList.emplace_back(ID);

	glGenVertexArrays(1, &ID);
	glBindVertexArray(ID);

	return ID;
}

//Binds 0 (This isn't needed and can just be hardcoded)
void unbindVao() {

	glBindVertexArray(0);

}

//Creates a VBO, adds it to the vbo list, binds the VBO, then puts the data in the vbo. It then calls the vertexattribpointer function to declare which attrib location the vbo is at.
void storeDataInAttribList(int attribNumber, GLfloat* data, GLsizeiptr vboSize) {

	GLuint ID;

	vboList.emplace_back(ID);

	glGenBuffers(1, &ID);
	glBindBuffer(GL_ARRAY_BUFFER, ID);

	glBufferData(GL_ARRAY_BUFFER, vboSize, data, GL_STATIC_DRAW);
	glVertexAttribPointer(attribNumber, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*) 0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

}

//Creates and binds an index buffer based on the passed data
void bindEBO(GLuint* indices, GLsizeiptr eboSize) {

	GLuint ID;

	vboList.emplace_back(ID);

	glGenBuffers(1, &ID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, eboSize, indices, GL_STATIC_DRAW);
}

//Deletes all vaos and vbos in the lists.
void Engine::cleanUp() {

	for (int i = 0; i < vaoList.size(); i++)
		glDeleteVertexArrays(1, &vaoList[i]);
	for (int i = 0; i < vaoList.size(); i++)
		glDeleteBuffers(1, &vboList[i]);
	for (int i = 0; i < texList.size(); i++)
		glDeleteTextures(1, &texList[i]);

}
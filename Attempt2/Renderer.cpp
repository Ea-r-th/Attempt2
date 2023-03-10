#include "Renderer.h"

Renderer::Renderer(StaticShader shader, mat4 projectionMatrix) 
	: shader(shader), projectionMatrix(projectionMatrix) {
}

void Renderer::render(Entity entity) {

	RawModel model = entity.getRawModel();

	glBindVertexArray(model.getVaoID());
	glEnableVertexAttribArray(0);
	glActiveTexture(GL_TEXTURE0); //Because all of the GL_TEXTURE values are sequential, we can simply add an extra integer to increment it
	glBindTexture(GL_TEXTURE_2D, entity.getTextureID());

	shader.loadProjectionMatrix(projectionMatrix);

	mat4 transformationMatrix = createTransformationMatrix(vec3(entity.getX(), entity.getY(), entity.getZ()), vec3(entity.getRotX(), entity.getRotY(), 0.0f));
	shader.loadTransformationMatrix(transformationMatrix);

	glDrawElements(GL_TRIANGLES, model.getVertexCount(), GL_UNSIGNED_INT, NULL);

	glBindTexture(GL_TEXTURE_2D, 0);
	glDisableVertexAttribArray(0);
	glBindVertexArray(0);
}

#include "Renderer.h"

Renderer::Renderer(StaticShader shader, mat4 projectionMatrix) 
	: shader(shader), projectionMatrix(projectionMatrix) {
}

void Renderer::render(Entity entity) {

	RawModel model = entity.getRawModel();

	glBindVertexArray(model.getVaoID());
	glEnableVertexAttribArray(0);

	shader.loadProjectionMatrix(projectionMatrix);

	mat4 transformationMatrix = createTransformationMatrix(vec3(entity.getX(), entity.getY(), entity.getZ()), vec3(entity.getRotX(), entity.getRotY(), 0.0f));
	shader.loadTransformationMatrix(transformationMatrix);

	glDrawElements(GL_TRIANGLES, model.getVertexCount(), GL_UNSIGNED_INT, NULL);

	glDisableVertexAttribArray(0);
	glBindVertexArray(0);
}

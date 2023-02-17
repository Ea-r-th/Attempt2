#pragma once

#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GLFW/glfw3.h>
#include "Camera.h"

using mat4 = glm::mat4x4;
using vec3 = glm::vec3;

mat4 createProjectionMatrix(GLfloat FOV, float displayWidth, float displayHeight, float nearPlane, float farPlane);

mat4 createViewMatrix(Camera camera);

mat4 createTransformationMatrix(vec3 position, vec3 rotation);
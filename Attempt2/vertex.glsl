#version 330 core

in vec3 position;

uniform mat4 projectionMatrix;
uniform mat4 transformationMatrix;
uniform mat4 viewMatrix;
uniform float time;

out vec3 vColor;

void main(){
	
	vec4 transformPosition = transformationMatrix * vec4(position, 1.0);

	gl_Position =  transformationMatrix * projectionMatrix * viewMatrix * vec4(position, 1.0);
	vColor = vec3(transformPosition.x + sin((time + 0.552075f)+ 0.f), transformPosition.y, max(cos(transformPosition.z+1.23545f),1.0f));
}
#include "Entity.h"

Entity::Entity(RawModel model, float posX, float posY, float posZ, float pitch, float yaw)
	: position(vec3(posX, posY, posZ)), rotation(vec3(pitch, yaw, 0)), model(model), direction(vec3(position.x,position.y,position.z -1.0)) {

}

void Entity::move(float amtX, float amtY, float amtZ){

	position.x += amtX;
	position.y += amtY;
	position.z += amtZ;
}

void Entity::rotate(float pitch, float yaw){
}

float Entity::getX(){
	return position.x;
}

float Entity::getY(){
	return position.y;
}

float Entity::getZ(){
	return position.z;
}

float Entity::getRotX(){
	return rotation.x;
}

float Entity::getRotY(){
	return rotation.y;
}

RawModel Entity::getRawModel() {
	return model;
}
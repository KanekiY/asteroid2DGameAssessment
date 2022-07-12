#include "GameObject.h"
#include "ObjectManager.h"
#include "InputComponent.h"
#include "MovementComponent.h"
#include "RenderingComponent.h"
#include "CollisionComponent.h"
#include "EntityLifeComponent.h"
#include "Component.h"


void GameObject::componListInitialise()
{
	if (_inputComponent != nullptr) pComponList.push_back(_inputComponent);
	if (_movementComponent != nullptr) pComponList.push_back(_movementComponent);
	if (_collisionComponent != nullptr) pComponList.push_back(_collisionComponent);
	if (_renderingComponent != nullptr) pComponList.push_back(_renderingComponent);
	if (_entityLifeComponent != nullptr) pComponList.push_back(_entityLifeComponent);
}

GameObject::GameObject() {
	this->isActive = false;
	this->image = -1.0f;
}

void GameObject::initialise(Vector2D pos, Vector2D velocity, ObjectManager* objMan) {

}
void GameObject::update(float gtTime) {
	for (Component* com : pComponList) {
		if (com->isActive) com->update(gtTime);
	}

}

//void GameObject::render() {
//
//}
GameObject::~GameObject() {}
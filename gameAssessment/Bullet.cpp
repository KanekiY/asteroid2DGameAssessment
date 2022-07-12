#include "Bullet.h"
#include "vector2D.h"
#include "gametimer.h"
#include "ObjectManager.h"
#include "InputComponent.h"
#include "MovementComponent.h"
#include "RenderingComponent.h"
#include "CollisionComponent.h"
#include "EntityLifeComponent.h"

Bullet:: Bullet() {
	
	_movementComponent = new MovementComponent();
	_renderingComponent = new RenderingComponent();
	_collisionComponent = new CollisionComponent();
	_entityLifeComponent = new EntityLifeComponent();
}

void Bullet::initialise(Vector2D pos, Vector2D vel, float ang, ObjectManager* objMan, GameObject* gOb) {
	this->objectManger = objMan;
	owner = gOb;
	Vector2D accer(0,0);
	accer.setBearing(ang,500.0);
	

	if (vel.XValue<=0) {
		vel.XValue = -vel.XValue;
	}

	if (vel.YValue <= 0) {
		vel.YValue = -vel.YValue;
	}
	_movementComponent->initialise(this, pos, accer+vel,ang);
	_renderingComponent->initialise(this, L"bullet.bmp");
	_collisionComponent->initialise(this, L"Circle", pos, 3, MyType::FRIENDLY);
	_entityLifeComponent->initialise(this, 1, objectManger, 0.5);
	componListInitialise();// add all initialised components into list
	this->isActive = true;

}

void Bullet::update(float frameTime) {
	for (Component* com : pComponList) {
		if (com->isActive) com->update(frameTime);
	}

	if (existingTime >= 0) {
		existingTime -= frameTime;
	}
	else {
		isActive = false;
	}


}


Bullet::~Bullet(){
	for (Component* com : pComponList) {
		delete com;
	}
}

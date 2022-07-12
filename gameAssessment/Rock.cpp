#include "Rock.h"
#include "vector2D.h"

#include "myinputs.h"
#include "gametimer.h"
#include "ObjectManager.h"
#include "InputComponent.h"
#include "MovementComponent.h"
#include "RenderingComponent.h"
#include "CollisionComponent.h"
#include "EntityLifeComponent.h"
#include "GameObject.h"
Rock::Rock() {

	
	_movementComponent = new MovementComponent();
	_renderingComponent = new RenderingComponent();
	_collisionComponent = new CollisionComponent();
	_entityLifeComponent = new EntityLifeComponent();

}

Rock::~Rock() {
	for (Component* com : pComponList) {
		delete com;
	}

}

void Rock::initialise(Vector2D pos, Vector2D vel, ObjectManager* objMan) {



	this->objectManger = objMan;
	
	
	_movementComponent->initialise(this, pos, vel);
	_renderingComponent->initialise(this, L"rock1.bmp");
	_collisionComponent->initialise(this, L"Circle", pos, 70, MyType::NEUTRAL);
	_entityLifeComponent->initialise(this, 10, objectManger,0.5);
	componListInitialise();// add all initialised components into list
	this->isActive = true;

}



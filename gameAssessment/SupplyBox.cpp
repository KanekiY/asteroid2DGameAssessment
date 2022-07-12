#include "SupplyBox.h"
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
SupplyBox::SupplyBox() {


	_movementComponent = new MovementComponent();
	_renderingComponent = new RenderingComponent();
	_collisionComponent = new CollisionComponent();
	_entityLifeComponent = new EntityLifeComponent();

}

SupplyBox::~SupplyBox() {
	for (Component* com : pComponList) {
		delete com;
	}

}

void SupplyBox::initialise(Vector2D pos, Vector2D vel, ObjectManager* objMan) {



	this->objectManger = objMan;


	_movementComponent->initialise(this, pos, vel,0);
	_renderingComponent->initialise(this, L"crate1.bmp");
	_collisionComponent->initialise(this, L"Circle", pos, 30, MyType::COMPATIABLE);
	_entityLifeComponent->initialise(this, 1, objectManger, 0.5);
	componListInitialise();// add all initialised components into list
	this->isActive = true;

}



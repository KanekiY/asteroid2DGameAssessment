#include "Spaceship.h"
#include "vector2D.h"
#include "mydrawengine.h"
#include "myinputs.h"
#include "gametimer.h"
#include "gamecode.h"
#include "InputComponent.h"
#include "MovementComponent.h"
#include "RenderingComponent.h"
#include "CollisionComponent.h"
#include "EntityLifeComponent.h"
#include "Bullet.h"

Spaceship::Spaceship() {
	_inputComponent = new InputComponent();
	_movementComponent = new MovementComponent();
	_renderingComponent = new RenderingComponent();
	_collisionComponent = new CollisionComponent();
	_entityLifeComponent = new EntityLifeComponent();
}

Spaceship::~Spaceship() {
	for (Component* com : pComponList) {
		delete com;
	}

}

void Spaceship::initialise(Vector2D pos, Vector2D vel, ObjectManager* objMan) {

	this->objectManger = objMan;
	
	_inputComponent->initialise(this);
	_movementComponent->initialise(this, pos,5.0,0.05,5);
	_renderingComponent->initialise(this, L"spaceship.bmp");
	_collisionComponent->initialise(this, L"Circle",pos,35,MyType::FRIENDLY);
	_entityLifeComponent->initialise(this,3,objectManger);
	componListInitialise();// add all initialised components into list
	this->isActive = true;

}

void Spaceship::spawnBullet()
{
	if (true) {
		GameObject* bullet = new Bullet();
		//bullet = objectManger->create(bullet, L"Bullet");
		//dynamic_cast<Bullet*>(bullet)->initialise(_movementComponent->position, _movementComponent->velocity, _movementComponent->angle, objectManger, this);
		//objectManger->addObject(bullet);
	}

}



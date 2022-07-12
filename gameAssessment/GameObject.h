#pragma once
#include "vector2D.h"
#include "mydrawengine.h"
#include "gametimer.h"
#include <list>
class InputComponent ;
class MovementComponent;
class RenderingComponent;
class CollisionComponent;
class EntityLifeComponent;
class Component;
class ObjectManager;

class GameObject
{
private:
	
	GameTimer theTimer;
protected:
	PictureIndex image;


	

	void componListInitialise();
public:
	std::list<Component*>pComponList;
	ObjectManager* objectManger = nullptr;
	InputComponent* _inputComponent = nullptr;
	MovementComponent* _movementComponent = nullptr;
	RenderingComponent* _renderingComponent = nullptr;
	CollisionComponent* _collisionComponent = nullptr;
	EntityLifeComponent* _entityLifeComponent = nullptr;



	bool isActive=false ;
	GameObject();
	virtual void initialise(Vector2D pos, Vector2D velocity,ObjectManager* objMan);
	//virtual void render();
	virtual void update(float gtTime);
	virtual ~GameObject();

};
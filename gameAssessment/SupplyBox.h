#pragma once
#include "vector2D.h"
#include "mydrawengine.h"
#include "gametimer.h"

#include "GameObject.h"
class SupplyBox :public GameObject
{
private:
	GameTimer theTimer;
	
public:

	GameObject* owner = nullptr;
	SupplyBox();
	~SupplyBox();
	void initialise(Vector2D pos, Vector2D vel, ObjectManager* objMan) override;


};

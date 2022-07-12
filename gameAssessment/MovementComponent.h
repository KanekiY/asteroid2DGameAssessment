#pragma once
#include "Component.h"

#include"RenderingComponent.h"

//class GameObject;

struct MovementStruc {

	

};

class MovementComponent :public Component {
private:
	

	float t_acc = 0.f;
	float t_ang = 0.f;
	float fractionRate=0.f;
	float frameTime = 0.f;
	
	//motion variable

	
	Vector2D acceleration;
	Vector2D friction;
	

public:
	Vector2D velocity;
	Vector2D position;
	float angle;

	int movingDirection = 1;
	int rotatingDirection = 1;


	MovementComponent();
	~MovementComponent();
	void initialise(GameObject* gObj,Vector2D pos, float acc, float ang, float fracRate);
	void initialise(GameObject* gameObj, Vector2D pos, Vector2D vel);
	void initialise(GameObject* gameObj, Vector2D pos, Vector2D vel, float ang);
	void update(float frameTime);
	void move();
	void rotate();
	void positionUpdate(float fracRate);
	void communicate() override;
	void HandleMessage(Message& msg) override;
	void NewMseeage() override;
};
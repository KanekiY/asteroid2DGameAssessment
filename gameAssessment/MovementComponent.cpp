#include "MovementComponent.h"
#include "Message.h"
#include"ObjectManager.h"

MovementComponent::MovementComponent() {
	this->isActive = false;
}
MovementComponent::~MovementComponent() {
}

//initialise for character
void MovementComponent::initialise(GameObject* gameObj,Vector2D pos, float acc, float ang,float fracRate) {
	gObj = gameObj;

	this->t_acc = acc;
	this->t_ang = ang;
	this->fractionRate = fracRate;
	this->position = pos;
	Vector2D accInitial(300,0);
	this->acceleration= accInitial;
	this->angle = 0;
	this->isActive = true;
	this->objectManger = gObj->objectManger;

}

void MovementComponent::initialise(GameObject* gameObj, Vector2D pos, Vector2D vel) {
	gObj = gameObj;

	this->position = pos;
	Vector2D accInitial(300, 0);
	this->acceleration = accInitial;
	this->angle = 1.57;
	this->velocity = vel;
	this->isActive = true;
	this->objectManger = gObj->objectManger;

}

void MovementComponent::initialise(GameObject* gameObj, Vector2D pos, Vector2D vel,float ang) {
	gObj = gameObj;

	this->position = pos;
	Vector2D accInitial(300, 0);
	this->acceleration = accInitial;
	this->angle = ang;
	this->velocity = vel;
	this->isActive = true;
	this->objectManger = gObj->objectManger;

}

void MovementComponent::update(float fTime) {
	frameTime = fTime;

	positionUpdate(fractionRate);
	communicate();

}

void MovementComponent::move() {


		acceleration.setBearing(angle, t_acc);
		velocity = velocity + acceleration * frameTime*movingDirection;
			
}

void MovementComponent::rotate() {

	angle += t_ang * rotatingDirection;
	

}

void MovementComponent::positionUpdate(float fracRate) {
	position = position + velocity * frameTime;
	friction = -fractionRate * velocity * frameTime;
	velocity = velocity + friction;
}

void MovementComponent::communicate() {
	//pRenderCom->renderPos = position;
	//pRenderCom->renderAngle = angle;
	NewMseeage();
}

void MovementComponent::HandleMessage(Message& msg) {



	if (msg.isMoving)
	{
		movingDirection = msg.forwardDirection;
		move();
	}
	if (msg.isRotating)
	{
		rotatingDirection = msg.rotateDirection;
		rotate();
	}
}


void MovementComponent::NewMseeage() {

	Message newMsg;
	newMsg.pSource = this->gObj;
	newMsg.type = EventType::MOVEMENT_EXECUTION;

	newMsg.pos = position;
	newMsg.ang = angle;

	ObjectManager* objMan = this->objectManger;
	objMan->sentMsg(newMsg);

}
#include "CollisionComponent.h"
#include "EntityLifeComponent.h"
#include "ObjectManager.h"
#include "Message.h"

CollisionComponent::CollisionComponent() {
	this->isActive = false;

}

CollisionComponent::~CollisionComponent(){

}

void CollisionComponent::initialise(GameObject* gameObj, std::wstring name,Vector2D pos,int rad, MyType MyTyp) {
	if (name==L"Circle")
	{
		gObj = gameObj;
		this->isActive = true;
		this->objectManger = gObj->objectManger;
		isEnabled = true;
		shape = new Circle2D();
		downCastCircle =static_cast<Circle2D*>(shape);
		downCastCircle->PlaceAt(pos,rad);
		position = pos;
		radius = rad;
		myType = MyTyp;
	}

}

IShape2D& CollisionComponent::GetShape()
{
	
	if (shape == downCastCircle) {
		 static_cast<Circle2D*>(shape)->PlaceAt(position, radius);
	}

	return *shape;
}

void CollisionComponent::update(float frameTime) {

	
//	MyDrawEngine::GetInstance()->FillCircle(downCastCircle->GetCentre(), downCastCircle->GetRadius(), MyDrawEngine::LIGHTGREEN);

}

void CollisionComponent::DisableCollision()
{
	isEnabled = false;
}

void CollisionComponent::EnableCollision()
{
	isEnabled = true;
}




void CollisionComponent::HandleCollision(CollisionComponent* collidedCom)
{
	if (isEnabled) {

		if (myType == MyType::COMPATIABLE) {
			if (collidedCom->myType == MyType::FRIENDLY) {
				NewMseeage(collidedCom);

			}
		}

		if (myType == MyType::NEUTRAL) {
			if (collidedCom->myType == MyType::FRIENDLY) { 
				NewMseeage(collidedCom);
				ScoringMsg();

			}

		}
		
		if (myType == MyType::FRIENDLY) {
			if (collidedCom->myType == MyType::NEUTRAL) {
				
				if(collidedCom->isActive)  NewMseeage(collidedCom);
			}

			if (collidedCom->myType == MyType::COMPATIABLE) {
				if (collidedCom->isActive) SupplyMsg(collidedCom);
			
			}
	
			
		}



	}
}

void CollisionComponent::NewMseeage(CollisionComponent* collidedCom)
{
	Message newMsg;
	newMsg.pSource = gObj;
	newMsg.type = EventType::OBJECT_HIT;
	objectManger->sentMsg(newMsg);


}


void CollisionComponent::HandleMessage(Message& msg)
{
	if (msg.type == EventType::MOVEMENT_EXECUTION) {
		position = msg.pos;
		GetShape();
	}

	
	if (msg.type == EventType::COLLISION_STATE) {
		if (msg.isEnableCollision) EnableCollision();
		else DisableCollision();
		
		}

	
}

void CollisionComponent::ScoringMsg() {
	Message newMsg;
	newMsg.pSource = gObj;
	newMsg.type = EventType::SCORING;
	objectManger->sentMsg(newMsg);
}

void CollisionComponent::SupplyMsg(CollisionComponent* collidedCom) {
	Message newMsg;
	newMsg.pSource = gObj;
	newMsg.type = EventType::SUPPLY;
	objectManger->sentMsg(newMsg);
}
void CollisionComponent::communicate()
{
}

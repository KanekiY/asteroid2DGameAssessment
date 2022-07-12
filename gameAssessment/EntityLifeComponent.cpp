#include "EntityLifeComponent.h"
#include "CollisionComponent.h"
#include "Message.h"
#include "ObjectManager.h"
EntityLifeComponent::EntityLifeComponent()
{
}

void EntityLifeComponent::initialise(GameObject* gOb, int l, ObjectManager* om)
{
	gObj = gOb;
	objectManger = om;
	isActive = true;
	life = l;
}

void EntityLifeComponent::initialise(GameObject* gOb, int l, ObjectManager* om, float reTrigger)
{
	gObj = gOb;
	objectManger = om;
	isActive = true;
	life = l;
	reTriggerPeriod= reTrigger;
}

EntityLifeComponent::~EntityLifeComponent()
{
}

void EntityLifeComponent::update(float gtTime)
{
	CoolingDown();


	
	
}

void EntityLifeComponent::HandleMessage(Message& msg)
{
	if (msg.type == EventType::DESTORY_TARGET) {// if destory target, destory the target
		if (msg.pSource ==gObj) {
			
			gObj->isActive = false;//if destory,  set game object false
			
			if (gObj->_collisionComponent!=nullptr) {
				gObj->_collisionComponent->isActive = false;
			}
			isActive = false;


		}
	}

	else if (msg.type == EventType::OBJECT_HIT) {//if hit, reduce the life
		if (msg.pSource == gObj) {

			life -= 1;


			if (life <= 0) { //report destory event
				NewMseeage();



			}
			else { //if hit and not die
				NewMsgDisableCollisions();
				ResetCoolingDown();

			}
		}
	}

}

void EntityLifeComponent::CoolingDown()
{
	if (isCoolingDown == false) {

	}

	else {
		reTriggerTime -= 0.016f;
		if (reTriggerTime <= 0) {// re-enable collision after cooldown
			isCoolingDown = false;
			NewMsgEnableCollisions();
		}

	}
}

bool EntityLifeComponent::IsCoolingDown()
{
	return isCoolingDown;
}

void EntityLifeComponent::NewMseeage()
{
	Message newMsg;
	newMsg.pSource = gObj;
	newMsg.type = EventType::DESTORY_TARGET;
	objectManger->sentMsg(newMsg);
}

void EntityLifeComponent::communicate()
{
}

void EntityLifeComponent::ResetCoolingDown()
{
	isCoolingDown = true;
	reTriggerTime = reTriggerPeriod;
}

void EntityLifeComponent::NewMsgDisableCollisions()
{
	Message newMsg;
	newMsg.pSource = gObj;
	newMsg.type = EventType::COLLISION_STATE;
	newMsg.isEnableCollision = false;
	objectManger->sentMsg(newMsg);
}

void EntityLifeComponent::NewMsgEnableCollisions()
{
	Message newMsg;
	newMsg.pSource = gObj;
	newMsg.type = EventType::COLLISION_STATE;
	newMsg.isEnableCollision = true;
	objectManger->sentMsg(newMsg);
}

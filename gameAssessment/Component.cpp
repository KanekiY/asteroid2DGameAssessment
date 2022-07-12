#include"Component.h"
#include "GameObject.h"
#include "ObjectManager.h"
#include "Message.h"

Component::Component() {

}
Component::~Component(){

}
void Component::initialise(GameObject* gOb) {
	gObj = gOb;
	this->isActive = true;
	this->objectManger = gObj->objectManger;
}
void Component::NewMseeage() {
	Message newMsg;
	newMsg.pSource = this->gObj;
	newMsg.type = EventType::COMPONENT_BASE;

}
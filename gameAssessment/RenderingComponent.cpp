#include "RenderingComponent.h"
#include"ObjectManager.h"
#include "Message.h"
RenderingComponent::RenderingComponent() {
	this->isActive = false;
}
RenderingComponent::~RenderingComponent() {
}

void RenderingComponent::initialise(GameObject* gameObj,std::wstring name) {
	gObj = gameObj;
	MyDrawEngine* pDE = MyDrawEngine::GetInstance();
	image = pDE->LoadPicture(name.c_str());
	this->isActive = true;
	this->objectManger = gObj->objectManger;
}
void RenderingComponent::update(float frameTime) {

	render();

}

void RenderingComponent::render() {
	MyDrawEngine* pDE = MyDrawEngine::GetInstance();
	pDE->DrawAt(renderPos, image, 1.0f, renderAngle);
}


void RenderingComponent::communicate() {

}

void RenderingComponent::HandleMessage(Message& msg) {
	renderAngle = msg.ang;
	renderPos = msg.pos;
}

void RenderingComponent::NewMseeage() {

}
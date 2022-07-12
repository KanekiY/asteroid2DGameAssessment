#include "InputComponent.h"
#include "Message.h"
#include"ObjectManager.h"
#include "Spaceship.h"
#include "mysoundengine.h"

InputComponent::InputComponent() {
	this->isActive = false;
}
InputComponent::~InputComponent() {
}

void InputComponent::initialise(GameObject* gameObj){
	gObj = gameObj;

	this->isActive = true;
	this->objectManger = gObj->objectManger;



}
void InputComponent::update(float frameTime) {

	WS_Input();
	AD_Input();
	Shoot();
	//communicate();
	coolingDown(frameTime);
	
}

void InputComponent::WS_Input() {
	MyInputs* pInputs = MyInputs::GetInstance();
	pInputs->SampleKeyboard();

	if (pInputs->KeyPressed(DIK_W))
	{
		forwardDirection = 500;
		this->NewMseeage(L"Movement", forwardDirection);
		//pMoveCompo->movingDirection = forwardDirection;
		//pMoveCompo->move();
	}

	if (pInputs->KeyPressed(DIK_S))
	{

		 forwardDirection = -500;
	
		this->NewMseeage(L"Movement", forwardDirection);
		//pMoveCompo->movingDirection = forwardDirection;
		//pMoveCompo->move();

	}
	
}

void InputComponent::AD_Input() {
	MyInputs* pInputs = MyInputs::GetInstance();
	pInputs->SampleKeyboard();

	if (pInputs->KeyPressed(DIK_D))
	{
		rotateDirection = 1;
		this->NewMseeage(L"Rotation", rotateDirection);
	}
	if (pInputs->KeyPressed(DIK_A))
	{
		rotateDirection = -1;
		this->NewMseeage(L"Rotation", rotateDirection);

	}
}

void InputComponent::Shoot()
{
	MyInputs* pInputs = MyInputs::GetInstance();
	pInputs->SampleKeyboard();
	if (pInputs->KeyPressed(DIK_K))
	{
		if (!isCooling) {
			NewMessageSpawnBullet();
			isCooling = true;

			MySoundEngine* pShootingSound = MySoundEngine::GetInstance();
			
			pShootingSound->Play(pShootingSound->LoadWav(L"shot3.wav"));
		}
		


	}
}

void InputComponent::NewMseeage(std::wstring name, int direction) {
	Message newMsg;
	newMsg.pSource = this->gObj;
	newMsg.type = EventType::INPUT_EXECUTION;
	if (name == L"Rotation") {
		newMsg.isRotating = true;
		newMsg.rotateDirection = direction;
	
	}
	if (name == L"Movement") {
		newMsg.isMoving = true;
		newMsg.forwardDirection = direction;
	}

	ObjectManager* objMan = this->objectManger;
	objMan->sentMsg(newMsg);
}

void InputComponent::NewMessageSpawnBullet()
{
	Message newMsg;
	newMsg.pSource = this->gObj;
	newMsg.type = EventType::SPAWN_BULLET;
	objectManger->sentMsg(newMsg);
}



void InputComponent::communicate() {

}
void InputComponent::HandleMessage(Message& msg) {

}

void InputComponent::coolingDown(float frameTime) {
	if (isCooling) {
		CoolingDownTime -= frameTime;
		if (CoolingDownTime<=0) {
			isCooling = false;
			CoolingDownTime = coolingDownPeriod;
		
		}
	}

}
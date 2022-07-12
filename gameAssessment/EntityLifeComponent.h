#pragma once
#include "Component.h"


class ObjectManager;


class EntityLifeComponent :public Component {
public:


	EntityLifeComponent();
	void initialise(GameObject* gOb, int l, ObjectManager* om) ;
	void initialise(GameObject* gOb, int l, ObjectManager* om, float reTrigger);
	// for re-use purpose
	~EntityLifeComponent();
	void update(float gtTime) override;
	void HandleMessage(Message& msg) override;
	void CoolingDown();
	bool IsCoolingDown();
	void NewMseeage() override;
	void communicate()  override;
	int life = 1;

private:
	void ResetCoolingDown();

	void NewMsgDisableCollisions();
	void NewMsgEnableCollisions();

	void NewMsgScroing();

	
	
	bool isCoolingDown = false;

	float reTriggerPeriod = 1.0f;// CD time of retrigger
	float reTriggerTime = reTriggerPeriod;
};
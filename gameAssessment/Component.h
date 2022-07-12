#pragma once

struct Message;
#include "GameObject.h"
class ObjectManager;

class Component:public GameObject {
public:
	Component();
	  ~Component() ;
	virtual void initialise(GameObject* gObj);
	virtual void update(float gtTime) = 0;
	virtual void communicate()=0;// old appraoch of the component communication
	virtual	void HandleMessage(Message& msg)=0; //new message system
	virtual void NewMseeage();
protected:
	GameObject* gObj = nullptr;

	
};
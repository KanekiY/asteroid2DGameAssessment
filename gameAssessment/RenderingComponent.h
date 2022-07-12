#pragma once
#include "Component.h"

//class GameObject;

class RenderingComponent :public Component {

private:
	Vector2D renderPos;
	float renderAngle;

public:
	RenderingComponent();
	~RenderingComponent();
	void initialise(GameObject* gObj, std::wstring name)  ;
	void update(float frameTime) ;
	void render();
	void communicate()  override;
	void HandleMessage(Message& msg) override;
	void NewMseeage() override;
};
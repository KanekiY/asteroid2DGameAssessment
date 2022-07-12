#pragma once
#include "Component.h"


//class GameObject;
enum class MyType { FRIENDLY, ENEMY, NEUTRAL, COMPATIABLE,BULLET};
class CollisionComponent :public Component {
private:
	


	bool isEnabled = false;

public:
	IShape2D* shape=nullptr;

	Circle2D* downCastCircle = nullptr;
	int radius;
	Vector2D position;
	CollisionComponent();
	~CollisionComponent();
	void initialise(GameObject* gameObj, std::wstring name, Vector2D pos, int radius, MyType MyTyp);
	IShape2D& GetShape();
	
	MyType myType = MyType::NEUTRAL;
	
	void update(float frameTime);
	void DisableCollision();
	void EnableCollision();
	void HandleCollision(CollisionComponent* collidedCom);
	void NewMseeage(CollisionComponent* collidedCom);
	void HandleMessage(Message& msg);
	void ScoringMsg();
	void SupplyMsg(CollisionComponent* collidedCom);
	void communicate() override;
};
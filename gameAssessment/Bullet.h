#include "vector2D.h"
#include "mydrawengine.h"
#include "gametimer.h"

#include "GameObject.h"
class Bullet :public GameObject
{
private:
	GameTimer theTimer;
	float existingTime = 3.f;
public:

	GameObject* owner=nullptr;
	Bullet();
	~Bullet();
	void initialise(Vector2D pos, Vector2D vel,float ang, ObjectManager* objMan, GameObject* gOb);
	void update(float frameTime);

};
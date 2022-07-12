
#include "vector2D.h"
#include "mydrawengine.h"
#include "gametimer.h"
#include "GameObject.h"

class Rock :public GameObject
{
private:
	GameTimer theTimer;
public:


	
	Rock();
	void initialise(Vector2D pos, Vector2D vel, ObjectManager* objMan) override;

	~Rock() override;
};
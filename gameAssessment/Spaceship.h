
#include "vector2D.h"
#include "mydrawengine.h"
#include "gametimer.h"
#include "GameObject.h"


class Spaceship:public GameObject
{	private:
	
	GameTimer theTimer;
	public:
		Spaceship();
		void initialise(Vector2D pos, Vector2D vel,ObjectManager* objMan);
		void spawnBullet();
		~Spaceship();
};

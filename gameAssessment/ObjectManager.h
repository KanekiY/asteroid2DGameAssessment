#include "vector2D.h"
#include "mydrawengine.h"
#include "gametimer.h"
#include "GameObject.h"
#include <list>
#include<string>
#include "LevelManager.h"
struct Message;

//template<typename GameObject>
class ObjectManager {
private:
	std::list<GameObject*> pObjectList;
	std::list<CollisionComponent*> pCollisionList;
	
public:
	LevelManager* lvlM = nullptr;
	    ObjectManager();
	    void addObject(GameObject* gameObject);
		void updateAll(float frametime);
		void CollisionDection();
		void deleteInactive();
		void deleteAll();
		void sentMsg(Message& msg);
		
		GameObject* create(GameObject* pNewpoiner, std::wstring name);

};

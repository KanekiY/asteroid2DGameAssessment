#pragma once

class ObjectManager;
class GameObject;

class LevelManager {

public:
	LevelManager();
	~LevelManager();
	void initialise(ObjectManager* gmObjMan);
	void update(float frameTime);
	void startOfGame();

	void Failed(float frameTime);
	void NextLevel(float frameTime);
	void Clear(float frameTime);
	void LevelInfo();
	int score = 0;
private:
	int level = -1;
	
	float reloadingPeriod = 3.f;
	float loadingTime = reloadingPeriod;
	bool isLoading = false;
	ObjectManager* objectManager;
	GameObject* spaceship=nullptr;
	GameObject* rock[3];
	GameObject* enemy=nullptr;
	//Bullet* bullet ;
};
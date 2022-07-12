#include "LevelManager.h"
#include "ObjectManager.h"
#include "GameObject.h"
#include "EntityLifeComponent.h"

#include "MovementComponent.h"
LevelManager::LevelManager()
{
}

LevelManager::~LevelManager()
{
}

void LevelManager::initialise(ObjectManager* gmObjMan)
{
	objectManager = gmObjMan;
	srand(time(0));
}

void LevelManager::update(float frameTime)
{

	LevelInfo();

	if (spaceship->isActive==false) {

		Failed(frameTime);
		objectManager->deleteAll();
		//if (!isLoading) isLoading = true;

		//if (isLoading) {
		//	Failed(frameTime);
		//	
		//	if (isLoading<=0) {
		//		isLoading = reloadingPeriod;
		//		startOfGame();
		//		isLoading = false;
		//	}

		//}
		
		
		
	}

	if (!rock[0]->isActive&& !rock[1]->isActive && !rock[2]->isActive&& spaceship->isActive) {
		
		if (level<3) {
			level += 1;
			NextLevel(frameTime);
		}
		else {
			Clear(frameTime);
		}
	}
	
}

void LevelManager::startOfGame()
{
	
	level = 1;
	score = 0;
	objectManager->deleteAll();
	//objectManager->deleteInactive();

	//create spaceship
	spaceship = objectManager->create(spaceship, L"Spaceship");//factory
	spaceship->initialise(Vector2D(0, 0), Vector2D(0, 0), objectManager);
	objectManager->addObject(spaceship);

	//create supplyBox
	GameObject* supply = nullptr;
	supply= objectManager->create(spaceship, L"SupplyBox");
	supply->initialise(Vector2D((rand() % 800 + 300), (rand() % 800 + 200)), Vector2D(rand() % 50, -100), objectManager);
	objectManager->addObject(supply);

	//create rock
	for (int i = 0; i <= 0;i++) {
		rock[i]= objectManager->create(rock[i], L"Rock");
		rock[i]->initialise(Vector2D((rand() % 800+300), (rand() % 800+200) ), Vector2D(rand() % 5, rand() % 5), objectManager);
		objectManager->addObject(rock[i]);
	}
	for (int i = 1; i <= 2; i++) {
		rock[i] = objectManager->create(rock[i], L"Rock");
		
		objectManager->addObject(rock[i]);
	}




	
}

void LevelManager::Failed(float frameTime)
{
	wchar_t text[5] = { 'Y','o','u',' ' };
	wchar_t text1[5] = { 'D','i','e','d' };
	text[4] = '\0';
	text1[4] = '\0';
	MyDrawEngine::GetInstance()->WriteText(800, 800, text, MyDrawEngine::RED);
	MyDrawEngine::GetInstance()->WriteText(840, 800, text1, MyDrawEngine::RED);
	loadingTime -= frameTime;
	
}

void LevelManager::NextLevel(float frameTime)
{
	if (level==2) {
		objectManager->deleteAll();
		spaceship = objectManager->create(spaceship, L"Spaceship");//factory
		spaceship->initialise(Vector2D(0, 0), Vector2D(0, 0), objectManager);
		objectManager->addObject(spaceship);

		for (int i = 0; i <= 1; i++) {
			rock[i] = objectManager->create(rock[i], L"Rock");
			rock[i]->initialise(Vector2D((rand() % 800 + 300), (rand() % 800 + 200)), Vector2D(rand() % 5, rand() % 5), objectManager);
			objectManager->addObject(rock[i]);
		}
		for (int i = 2; i <= 2; i++) {
			rock[i] = objectManager->create(rock[i], L"Rock");

			objectManager->addObject(rock[i]);
		}

		//create supplyBox
		GameObject* supply = nullptr;
		supply = objectManager->create(spaceship, L"SupplyBox");
		supply->initialise(Vector2D((rand() % 800 + 300), (rand() % 800 + 200)), Vector2D(rand() % 50, -100), objectManager);
		objectManager->addObject(supply);
	}

	if (level == 3) {
		objectManager->deleteAll();
		spaceship = objectManager->create(spaceship, L"Spaceship");//factory
		spaceship->initialise(Vector2D(0, 0), Vector2D(0, 0), objectManager);
		objectManager->addObject(spaceship);

		for (int i = 0; i <= 2; i++) {
			rock[i] = objectManager->create(rock[i], L"Rock");
			rock[i]->initialise(Vector2D((rand() % 800 + 300), (rand() % 800 + 200)), Vector2D(rand() % 5, rand() % 5), objectManager);
			objectManager->addObject(rock[i]);
		}
	}
}

void LevelManager::Clear(float frameTime)
{
	wchar_t text[5] = { 'Y','o','u',' ' };
	wchar_t text1[5] = { 'W','i','n','!' };
	text[4] = '\0';
	text1[4] = '\0';
	MyDrawEngine::GetInstance()->WriteText(800, 800, text, MyDrawEngine::GREEN);
	MyDrawEngine::GetInstance()->WriteText(840, 800, text1, MyDrawEngine::GREEN);
	loadingTime -= frameTime;
}

void LevelManager::LevelInfo()
{
	/* Current Level*/
	wchar_t text[5] = { 'L','v','l',':' };
	text[4] = '\0';
	MyDrawEngine::GetInstance()->WriteText(1000, 100, text, MyDrawEngine::YELLOW);
	MyDrawEngine::GetInstance()->WriteInt(1050, 100, level, MyDrawEngine::YELLOW);

	/* Player Life */
	wchar_t text1[5] = { 'L','i','f','e' };
	text1[4] = '\0';
	MyDrawEngine::GetInstance()->WriteText(30, 100, text1, MyDrawEngine::WHITE);
	MyDrawEngine::GetInstance()->WriteInt(80, 100, spaceship->_entityLifeComponent->life, MyDrawEngine::RED);

	/* Score */
	wchar_t text2[5] = { 'S','c','o','r' };
	text2[4] = '\0';
	MyDrawEngine::GetInstance()->WriteText(30, 130, text2, MyDrawEngine::WHITE);
	MyDrawEngine::GetInstance()->WriteInt(80, 130, score, MyDrawEngine::RED);





}

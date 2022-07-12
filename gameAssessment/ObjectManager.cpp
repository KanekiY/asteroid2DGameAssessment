#include "vector2D.h"
#include "mydrawengine.h"
#include "gametimer.h"
#include "ObjectManager.h"
#include "GameObject.h"
#include "myinputs.h"
#include <list>
#include "Spaceship.h"
#include "Rock.h"
#include "Bullet.h"
#include "SupplyBox.h"
#include "RenderingComponent.h"
#include "MovementComponent.h"
#include "InputComponent.h"
#include "CollisionComponent.h"
#include "EntityLifeComponent.h"
#include<cstring>
#include"Message.h"

ObjectManager::ObjectManager() {

}
void ObjectManager::addObject(GameObject* gameObject) {
	pObjectList.push_back(gameObject);

	//set up collisionComponentList
	if (gameObject->_collisionComponent != nullptr) {
		if (gameObject->_collisionComponent->isActive)
			pCollisionList.push_back(gameObject->_collisionComponent);
	}

}



void ObjectManager::updateAll(float frameTime) {

	for (GameObject* n : pObjectList)

	{
		if (n->isActive) {
			
			n->update(frameTime);
			
		}
	}

	

}

void ObjectManager::CollisionDection()
{
	


	std::list<CollisionComponent*>::iterator it1;
	std::list<CollisionComponent*>::iterator it2;

	for (it1 = pCollisionList.begin(); it1 != pCollisionList.end(); it1++) {
		for (it2 = std::next(it1); it2 != pCollisionList.end(); it2++) {
			if ((*it1)->GetShape().Intersects((*it2)->GetShape())) {
				if ((*it1)->isActive) {
					(*it1)->HandleCollision((*it2));
				}
				if ((*it2)->isActive) {
					(*it2)->HandleCollision((*it1));
				}
				
				

				
			}
		}
	}
}

void ObjectManager::deleteInactive() {

	for (GameObject* n : pObjectList)
	{
		if (!n->isActive) {
			for (Component* com : n->pComponList) {
				if (com->isActive) com->isActive=false;
			}
			
			delete n;
			pObjectList.remove(n);
			
		}
		
	}



}
void ObjectManager::deleteAll() {

	//MyInputs* pInputs = MyInputs::GetInstance();
	//pInputs->SampleKeyboard();

	//if (pInputs->KeyPressed(DIK_J))
	//{
	//}
		for (GameObject* n : pObjectList)
		{
			n->isActive = false;

			for (Component* com : n->pComponList) {
				if (com->isActive) com->isActive = false;
			}


		}


	




}

//obj Factory 
GameObject* ObjectManager::create(GameObject* pNewObject, std::wstring name) {
	//objectType* pNewObject = nullptr;
	
	if (name == L"Rock")
	{
		pNewObject = new Rock();

	}
	else if (name == L"Spaceship")
	{
		pNewObject = new Spaceship();
	
	}
	else if (name == L"Bullet")
	{
		pNewObject = new Bullet();

	}
	else if (name == L"SupplyBox")
	{
		pNewObject = new SupplyBox();

	}
	
	else
	{
		ErrorLogger::Write(L"Could not create item: ");
		ErrorLogger::Writeln(name.c_str());
	}
	
	return pNewObject;

}

void ObjectManager::sentMsg(Message& msg) {

	//handle input msg og movementComponent
	if (msg.type == EventType::INPUT_EXECUTION) {
		if (msg.pSource->_movementComponent != nullptr) {
			if (msg.pSource->_movementComponent->isActive) {
				msg.pSource->_movementComponent->HandleMessage(msg);
			}

		}
	}



	if (msg.type == EventType::MOVEMENT_EXECUTION) {
		//handle position msg of rendering Component
		if ((msg.pSource->_renderingComponent) != nullptr) {
			if (msg.pSource->_renderingComponent->isActive) {
				msg.pSource->_renderingComponent->HandleMessage(msg);
			}
		}
		//handle position msg of collision Component
		if ((msg.pSource->_collisionComponent) != nullptr) {
			
			if (msg.pSource->_collisionComponent->isActive == true) {
				msg.pSource->_collisionComponent->HandleMessage(msg);
			}
		}
	}

	//handle Destory event msg of entityLifeComponent
	if (msg.type == EventType::DESTORY_TARGET) {
		if (msg.pSource->_entityLifeComponent != nullptr) {
			if (msg.pSource->_entityLifeComponent->isActive) {
				msg.pSource->_entityLifeComponent->HandleMessage(msg);
			}

		}
	}

	//handle hit event msg of entityLifeComponent
	if (msg.type == EventType::OBJECT_HIT) {
		if (msg.pSource->_entityLifeComponent != nullptr) {
			if (msg.pSource->_entityLifeComponent->isActive) {
				msg.pSource->_entityLifeComponent->HandleMessage(msg);
			}

		}
	}

	//handle collision statechange event msg of entityLifeComponent
	if (msg.type == EventType::COLLISION_STATE) {
		if (msg.pSource->_collisionComponent != nullptr) {
			if (msg.pSource->_collisionComponent->isActive) {
				msg.pSource->_collisionComponent->HandleMessage(msg);
			}

		}
	}

	//spawn bullet
	if (msg.type == EventType::SPAWN_BULLET) {
		if (msg.pSource!= nullptr) {
			if (msg.pSource->isActive) {
	
				GameObject* bullet=nullptr;
				bullet = this->create(bullet, L"Bullet");
				
				MovementComponent* movementCom = msg.pSource->_movementComponent;

				static_cast<Bullet*>(bullet)->initialise(movementCom->position, movementCom->velocity,movementCom->angle,this, msg.pSource);
				
				
				
				this->addObject(bullet);

				
			}

		}
	}

	//scoring
	if (msg.type == EventType::SCORING) {
		if (lvlM!=nullptr) {
			if (msg.pSource->isActive) {
				lvlM->score += 1;
			}


			
			

		}
	}
	//supply
	if (msg.type == EventType::SUPPLY) {
		if (msg.pSource != nullptr) {
			if (msg.pSource->isActive) {

				if (msg.pSource->_entityLifeComponent->life<=4) {
					msg.pSource->_entityLifeComponent->life +=1;// if life is lower than 5, supply to 5
				}


			}

		}
	}

}

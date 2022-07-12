#pragma once

enum class EventType { OBJECT_HIT, EXPLOSION, BULLET_FIRED, LEVEL_START, NOTHING, DESTORY_TARGET,COMPONENT_BASE,INPUT_EXECUTION,MOVEMENT_EXECUTION,COLLISION_STATE,SPAWN_BULLET,SCORING,SUPPLY};

class GameObject;
class Game;
struct Message
{
	EventType type;
	GameObject* pSource;
	int rotateDirection = 0;
	int forwardDirection = 0;

	bool isRotating = false;
	bool isMoving = false;
	bool isEnableCollision = false;
	Vector2D pos;
	float ang;

};

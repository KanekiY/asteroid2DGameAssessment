#include "Component.h"

#include "myinputs.h"
//class GameObject;

class InputComponent :public Component {
private:
	

	int rotateDirection=1;
	int forwardDirection=1;
	float coolingDownPeriod = 0.5f;
	bool isCooling = false;
	float CoolingDownTime = coolingDownPeriod;


public:
	InputComponent();
	~InputComponent() ;
	void initialise(GameObject* gObj)   ;
	void update(float frameTime) ;
	void WS_Input() ;
	void AD_Input() ;
	void Shoot();
	void NewMseeage(std::wstring name,int direction);
	void NewMessageSpawnBullet();
	void HandleMessage(Message& msg);
	void coolingDown(float frameTime);
	void communicate() override;
};
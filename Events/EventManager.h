#ifndef __EVENT_MANAGER_H__
#define __EVENT_MANAGER_H__

#include "../Utils/Singleton.h"

class EventManager : public Singleton
{
private:
	EventManager();

public:
	EventManager* GetInstance();
};

#endif

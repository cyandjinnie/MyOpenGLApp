#ifndef __BASE_STATE_H__
#define __BASE_STATE_H__

#include "Events/EventKeyboard.h"

class BaseState
{
public:
	BaseState();
	virtual ~BaseState() = default;

	virtual void input(const EventKeyboard& event);
	virtual void init();

};


#endif
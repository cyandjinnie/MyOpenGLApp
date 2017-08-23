#ifndef __INPUT_CONTROL_H__
#define __INPUT_CONTROL_H__

#include "../Events/EventKeyboard.h"
#include "../Utils/Singleton.h"

class InputControl : public Singleton
{
public:
	static InputControl* GetInstance();

	void DispatchOnKeyPressed(const EventKeyboard&);
	void DispatchOnKeyReleased(const EventKeyboard&);
private:
	InputControl();
};



#endif
#include "InputControl.h"
#include "../Application.h"

InputControl::InputControl()
{
}

InputControl* InputControl::GetInstance()
{
	static InputControl instance;

	return &instance;
}

void InputControl::DispatchOnKeyPressed(const EventKeyboard& eventKeyboard)
{

}

void InputControl::DispatchOnKeyReleased(const EventKeyboard& eventKeyboard)
{
	PostQuitMessage(0);
}
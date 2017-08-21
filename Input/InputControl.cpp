#include "InputControl.h"

InputControl::InputControl()
{
}

InputControl* InputControl::GetInstance()
{
	static InputControl instance;

	return &instance;
}

int InputControl::foo(int _in)
{
	return _in;
}

#ifndef __INPUT_CONTROL_H__
#define __INPUT_CONTROL_H__

class InputControl
{
public:
	static InputControl* GetInstance();

	int foo(int _in);

	InputControl(InputControl const&)		= delete;
	void operator=(InputControl const&)		= delete;
private:
	InputControl();
};



#endif
#include "Exceptions.h"

MyException::MyException() : Info("")
{
}

MyException::MyException(const char* _str) : Info(_str)
{
}

const char* MyException::what()
{
	return this->Info.c_str();
}
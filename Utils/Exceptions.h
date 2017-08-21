#ifndef __EXCEPTIONS_H__
#define __EXCEPTIONS_H__

#include	<exception>
#include	<string>

class MyException : public std::exception
{
public:
	MyException();
	MyException(const char*);
	const char* what();
private:
	std::string Info;
};

#endif

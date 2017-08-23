#ifndef __SINGLETON_H__
#define __SINGLETON_H__

class Singleton
{
public:
	Singleton(Singleton& other) = delete;
	Singleton(Singleton&& other) = delete;

	Singleton& operator =(Singleton&  other) = delete;
	Singleton& operator =(Singleton&& other) = delete;

protected:

	Singleton() = default;
	virtual ~Singleton() = default;
};

#endif
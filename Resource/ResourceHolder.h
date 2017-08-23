#ifndef __RESOURCE_HOLDER_H__
#define __RESOURCE_HOLDER_H__

#include "../Utils/Singleton.h"
#include "ResourceManager.h"

class ResourceHolder : public Singleton
{
public:
	static ResourceHolder* GetInstance();

private:
};

#endif
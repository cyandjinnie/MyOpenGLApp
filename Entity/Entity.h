#ifndef __ENTITY_H__
#define __ENTITY_H__

#include "glm\glm.hpp"

class Entity
{
public:
	Entity() = default;
	virtual ~Entity() = default;

protected:
	glm::vec3 position;
	glm::vec3 direction;
};

#endif
#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "../Entity/Entity.h"

class Player : public Entity
{
public:
	Player();
	~Player();

private:
	glm::vec3 SpeedVector = glm::vec3(0.0f, 0.0f, 0.0f);
};

#endif
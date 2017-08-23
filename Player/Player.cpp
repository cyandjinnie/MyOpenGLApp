#include "Player.h"

#include <glm/glm.hpp>

Player::Player() : Entity()
{
	direction = glm::vec3(0.0f, 0.0f, 0.0f);
	position = glm::vec3(4.0f, 3.0f, -3.0f);
}

Player::~Player()
{

}
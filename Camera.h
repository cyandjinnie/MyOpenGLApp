#ifndef __CAMERA_H__
#define __CAMERA_H__

#include "Entity\Entity.h"
#include <glm/glm.hpp>

class Entity;

class Camera : public Entity
{
public:
	Camera();
	
	void SetFOV(float FOV);
	float GetFOV() const;

	void Update();
	void HookEntity(const Entity& entity);
	void UnhookEntity();

	const glm::mat4& GetProjViewMatrix() const;
	const glm::mat4& GetProjMatrix() const;
	const glm::mat4& GetViewMatrix() const;

private:
	float FOV = 100;

	const Entity* pEntity = nullptr;

	glm::mat4 ViewMatrix;
	glm::mat4 ProjMatrix;
	glm::mat4 ProjViewMatrix;
};

#endif
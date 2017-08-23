#include "Camera.h"
#include "Application.h"

#include <glm/gtc/matrix_transform.hpp> 
#include <glm/gtx/transform.hpp>

Camera::Camera()
{
	auto App = Application::GetInstance();

	this->direction = glm::vec3(0.0f, 0.0f, 0.0f);
	this->position = glm::vec3(4.0f, 3.0f, -3.0f);

	this->Update();
}

void Camera::Update()
{
	auto App = Application::GetInstance();

	if (this->pEntity)
	{
		this->direction = pEntity->direction;
		this->position = pEntity->position;
	}

	ViewMatrix = glm::lookAt(
		this->position,
		this->direction,
		glm::vec3(0.0f, 1.0f, 0.0f)
	);

	this->ProjMatrix = glm::perspective(
		glm::radians(this->FOV),
		App->GetWindowAspectRatio(),
		0.1f,
		100.0f
	);

	ProjViewMatrix = ProjMatrix * ViewMatrix;
}

void Camera::HookEntity(const Entity& entity)
{
	pEntity = &entity;
	this->Update();
}

void Camera::UnhookEntity()
{
	pEntity = nullptr;
}

const glm::mat4& Camera::GetProjMatrix() const
{
	return this->ProjMatrix;
}

const glm::mat4& Camera::GetViewMatrix() const
{
	return this->ViewMatrix;
}

const glm::mat4& Camera::GetProjViewMatrix() const
{
	return this->ProjViewMatrix;
}
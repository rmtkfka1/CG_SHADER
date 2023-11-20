#include "pch.h"
#include "Camera2.h"

void Camera2::KeyUpdate()
{

	float dt = TimeManager::GetInstance()->GetDeltaTime();

	float cameraSpeed = 20.0f;

	if(KeyManager::GetInstance()->Getbutton(KeyType::W))
	{
		m_cameraPos += cameraSpeed * m_cameraFront *dt;
	}
	if (KeyManager::GetInstance()->Getbutton(KeyType::S))
	{
		m_cameraPos -= cameraSpeed * m_cameraFront * dt;
	}


	auto cameraRight = glm::normalize(glm::cross(m_cameraUp, -m_cameraFront));

	if (KeyManager::GetInstance()->Getbutton(KeyType::D))
	{
		m_cameraPos += cameraSpeed * cameraRight *dt;
	}
	if (KeyManager::GetInstance()->Getbutton(KeyType::S))
	{
		m_cameraPos -= cameraSpeed * cameraRight * dt;
	}

	auto cameraUp = glm::normalize(glm::cross(-m_cameraFront, cameraRight));


	if (KeyManager::GetInstance()->Getbutton(KeyType::Q))
	{
		m_cameraPos += cameraSpeed * cameraUp * dt;
	}
	if (KeyManager::GetInstance()->Getbutton(KeyType::E))
	{
		m_cameraPos -= cameraSpeed * cameraUp * dt;
	}

}



glm::mat4 Camera2::GetMatrix()
{
	auto view = glm::lookAt(
		m_cameraPos,
		m_cameraPos + m_cameraFront,
		m_cameraUp);

	return view;
}

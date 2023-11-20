#include "pch.h"
#include "Camera2.h"

void Camera2::KeyUpdate()
{
	if (!m_cameraControl)
	{
		return;
	}

	float dt = TimeManager::GetInstance()->GetDeltaTime();

	float cameraSpeed = 100.0f;

	if(KeyManager::GetInstance()->Getbutton(KeyType::W))
	{
		m_cameraPos += cameraSpeed * m_cameraFront *dt;

		if (m_cameraPos.y > 20.0f)
		{
			m_cameraPos.y = 20.0f;
		}
	}
	if (KeyManager::GetInstance()->Getbutton(KeyType::S))
	{
		m_cameraPos -= cameraSpeed * m_cameraFront * dt;


		if (m_cameraPos.y > 20.0f)
		{
			m_cameraPos.y = 20.0f;
		}
	}


	auto cameraRight = glm::normalize(glm::cross(m_cameraUp, -m_cameraFront));

	if (KeyManager::GetInstance()->Getbutton(KeyType::D))
	{
		m_cameraPos += cameraSpeed * cameraRight *dt;
	}
	if (KeyManager::GetInstance()->Getbutton(KeyType::A))
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

void Camera2::MouseUpdate(float x, float y)
{
	if (!m_cameraControl)
	{
		return;
	}



	float dt = TimeManager::GetInstance()->GetDeltaTime();

	//static glm::vec2 prevPos = glm::vec2(x, y);

	//auto deltaPos = pos - prevPos;

	auto pos = glm::vec2(x, y);
	auto deltaPos = pos - m_prevMousePos;

	const float cameraSpeed = 10.0f;

	m_cameraYaw -= deltaPos.x * cameraSpeed * dt;
	m_cameraPitch -= deltaPos.y * cameraSpeed * dt;


	if (m_cameraYaw < 0.0f) m_cameraYaw += 360.0f;
	if (m_cameraYaw > 360.0f) m_cameraYaw -= 360.0f;

	if (m_cameraPitch > 89.0f) m_cameraPitch = 89.0f;
	if (m_cameraPitch < -89.0f) m_cameraPitch = -89.0f;

	m_prevMousePos = pos;

}


glm::mat4 Camera2::GetMatrix()
{

	m_cameraFront =
		glm::rotate(glm::mat4(1.0f), glm::radians(m_cameraYaw), glm::vec3(0.0f, 1.0f, 0.0f)) *
		glm::rotate(glm::mat4(1.0f), glm::radians(m_cameraPitch), glm::vec3(1.0f, 0, 0.0f)) *
		glm::vec4(0.0f, 0.0f, -1.0f, 0.0f);

	auto view = glm::lookAt(
		m_cameraPos,
		m_cameraPos + m_cameraFront,
		m_cameraUp);

	return view;
}

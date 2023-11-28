#include "pch.h"
#include "Camera2.h"

void CameraManager::KeyUpdate()
{


	float dt = TimeManager::GetInstance()->GetDeltaTime();


	if (KeyManager::GetInstance()->Getbutton(KeyType::W))
	{
		m_cameraPos += m_cameraSpeed * m_cameraFront * dt;

	}
	if (KeyManager::GetInstance()->Getbutton(KeyType::S))
	{
		m_cameraPos -= m_cameraSpeed * m_cameraFront * dt;


	}

	auto cameraRight = glm::normalize(glm::cross(m_cameraUp, -m_cameraFront));

	if (KeyManager::GetInstance()->Getbutton(KeyType::D))
	{
		m_cameraPos += m_cameraSpeed * cameraRight * dt;



	}
	if (KeyManager::GetInstance()->Getbutton(KeyType::A))
	{
		m_cameraPos -= m_cameraSpeed * cameraRight * dt;




	}

	auto cameraUp = glm::normalize(glm::cross(-m_cameraFront, cameraRight));


	if (KeyManager::GetInstance()->Getbutton(KeyType::Q))
	{
		m_cameraPos += m_cameraSpeed * cameraUp * dt;
	}
	if (KeyManager::GetInstance()->Getbutton(KeyType::E))
	{
		m_cameraPos -= m_cameraSpeed * cameraUp * dt;
	}

}

void CameraManager::MouseUpdate(float x, float y)
{

	float dt = TimeManager::GetInstance()->GetDeltaTime();


	auto pos = glm::vec2(x, y);
	auto deltaPos = pos - m_prevMousePos;

	const float cameraSpeed = 10.0f;

	///������ ũ�⸦ �����ͼ� ����ȸ�� �����ϰ� ��Ŵ//

	float windowWidth = glutGet(GLUT_WINDOW_WIDTH);
	float windowHeight = glutGet(GLUT_WINDOW_HEIGHT);

	if (x > windowWidth - 300)
	{
		glutWarpPointer(windowWidth / 2, windowHeight / 2);
		m_prevMousePos = glm::vec2(windowWidth / 2, windowHeight / 2);
		deltaPos = glm::vec2(0, 0);
		return;
	}

	if (x < 300)
	{
		glutWarpPointer(windowWidth / 2, windowHeight / 2);
		m_prevMousePos = glm::vec2(windowWidth / 2, windowHeight / 2);
		deltaPos = glm::vec2(0, 0);
		return;
	}

	if (y < 100)
	{
		glutWarpPointer(windowWidth / 2, windowHeight / 2);
		m_prevMousePos = glm::vec2(windowWidth / 2, windowHeight / 2);
		deltaPos = glm::vec2(0, 0);
		return;
	}

	if (y > windowHeight - 100)
	{
		glutWarpPointer(windowWidth / 2, windowHeight / 2);
		m_prevMousePos = glm::vec2(windowWidth / 2, windowHeight / 2);
		deltaPos = glm::vec2(0, 0);
		return;
	}


	/////////////////////////////////////////////////////


	m_cameraYaw -= deltaPos.x * cameraSpeed * dt;
	m_cameraPitch -= deltaPos.y * cameraSpeed * dt;


	if (m_cameraYaw < 0.0f) m_cameraYaw += 360.0f;
	if (m_cameraYaw > 360.0f) m_cameraYaw -= 360.0f;

	if (m_cameraPitch > 89.0f) m_cameraPitch = 89.0f;
	if (m_cameraPitch < -89.0f) m_cameraPitch = -89.0f;

	m_prevMousePos = pos;

}


glm::mat4 CameraManager::GetMatrix()
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

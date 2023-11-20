#include "pch.h"
#include "Camera.h"


Camera::Camera()
{
}

Camera::Camera(glm::vec3 initEye, glm::vec3 initUp, float initYaw, float initPitch, float initMoveSpeed, float initTurnSpeed)
	: m_Eye{ initEye }, m_Front{ glm::vec3{0.0f,0.0f,-1.0f} }, m_WorldUp{ initUp },
	m_Pitch{ initPitch }, m_Yaw{ initYaw },
	m_MoveSpeed{ initMoveSpeed }, m_TurnSpeed{ initTurnSpeed }
{
	Update();
}

Camera::~Camera()
{

}

void Camera::KeyControl()
//keys���� Window.m_Keys �����Ͱ� ���޵�
{
	//movespeed�� WASD Ű�� ������ �� ī�޶��� �̵� �ӵ�.
	//deltiTime�� ���� �����Ӱ� ���� ������ ������ �ҿ� �ð�
	float velocity = m_MoveSpeed * TimeManager::GetInstance()->GetDeltaTime();

	//WASD�� ������ ���� ī�޶��� EYE ��ġ�� �̵���Ű�� ��
	//�̶�, front�� (at-eye).normalize() ������, ���콺 �����ӿ� ���� eye ��ǥ�� �����ϴ� �� ���ٴ�
	//at-eye ���͸� front�� �����ϴ� ���� ���ϹǷ� �̷��� ����
	//front�� up�� ���ǵǾ� ������, right ������ �������� �ս��� ���� �� ����

	if (KeyManager::GetInstance()->Getbutton(KeyType::W))
	{
		m_Eye += m_Front * velocity;
	}

	if (KeyManager::GetInstance()->Getbutton(KeyType::S))
	{
		m_Eye -= m_Front * velocity;
	}

	if (KeyManager::GetInstance()->Getbutton(KeyType::D))
	{
		m_Eye += m_Right * velocity;
	}

	if (KeyManager::GetInstance()->Getbutton(KeyType::A))
	{
		m_Eye -= m_Right * velocity;
	}

}

void Camera::MouseControl(float xChange, float yChange)
//xChange,yChange���� Window.m_XChange, Window.m_YChange�� ���޵�
{
	//���콺�� 1�ȼ���ŭ �������� �� �󸶳� ������ ������ ���ΰ��� m_TurnSpeed �Ķ����
	xChange *= m_TurnSpeed;
	yChange *= m_TurnSpeed;

	m_Yaw += xChange;
	m_Pitch += yChange;

	//y�������� ���� �������� �� ���� �ѱ��� ���ϵ��� ���� ������ ��
	if (m_Pitch > 89.0f)
		m_Pitch = 89.0f;

	if (m_Pitch < -89.0f)
		m_Pitch = -89.0f;

	Update();
}

glm::mat4 Camera::calculateViewMatrix()
{
	glm::mat4 view = glm::lookAt(m_Eye, m_Eye + m_Front, m_Up);
	//std::cout << glm::to_string(view) << std::endl;
	return glm::lookAt(m_Eye, m_Eye + m_Front, m_Up); //At = Eye + Front
}

void Camera::Update()
{
	//���콺 �Է¿� ���� Front ������ ��ȭ ��� (���� ��ǥ -> ī���׽þ� ��ǥ)
	m_Front.x = cos(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
	m_Front.y = sin(glm::radians(m_Pitch)); 
	m_Front.z = sin(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
	m_Front = glm::normalize(m_Front);

	m_Right = glm::normalize(glm::cross(m_Front, m_WorldUp));
	m_Up = glm::normalize(glm::cross(m_Right, m_Front));
}


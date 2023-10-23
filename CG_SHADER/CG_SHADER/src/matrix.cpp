#include "pch.h"
#include "matrix.h"



glm::mat4 matrix::GetSimple()
{
	return glm::mat4(1.0f);
}

glm::mat4 matrix::GetTranslation(float dx , float dy ,float dz)
{
	return  glm::translate(glm::mat4(1.0f), glm::vec3(dx, dy, dz));
}


glm::mat4 matrix::GetScale(float dx, float dy, float dz)
{
	return glm::scale(glm::mat4(1.0f), glm::vec3(dx, dy, dz));
}

glm::mat4 matrix::GetRotate(float degree, float x, float y, float z)
{
	return glm::rotate(glm::mat4(1.0f), glm::radians(degree), glm::vec3(x, y, z));

}


glm::mat4 matrix::GetCamera(glm::vec3 eye, glm::vec3 at, glm::vec3 up)
{
	glm::mat4 view(1.0f);
	view = glm::lookAt(eye, at, up);

	return view;
}

glm::mat4 matrix::GetRotateCamera()
{
	float dt = TimeManager::GetInstance()->GetDeltaTime();
	float angle = camera_speed;

	auto x = sinf(angle) * 30.0f;
	auto z = cosf(angle) * 30.0f;

	glm::mat4 view = glm::mat4(1.0f);
	glm::vec3 cameraPos = glm::vec3(x, 20.0f, z); //--- ī�޶� ��ġ
	glm::vec3 cameraDirection = glm::vec3(0.0f, 0.0f, 0.0f); //--- ī�޶� �ٶ󺸴� ����
	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f); //--- ī�޶� ���� ����
	view = glm::lookAt(cameraPos, cameraDirection, cameraUp);

	camera_speed += 0.1f * dt; //����� ���ǵ尡 �ƴ϶� ���Ȱ���
	return view;
}

glm::mat4 matrix::GetRotateCamera(float dy)
{
	float dt = TimeManager::GetInstance()->GetDeltaTime();
	float angle = camera_speed;

	auto x = sinf(angle) * 30.0f;
	auto z = cosf(angle) * 30.0f;

	glm::mat4 view = glm::mat4(1.0f);
	glm::vec3 cameraPos = glm::vec3(x, dy, z); //--- ī�޶� ��ġ
	glm::vec3 cameraDirection = glm::vec3(0.0f, 0.0f, 0.0f); //--- ī�޶� �ٶ󺸴� ����
	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f); //--- ī�޶� ���� ����
	view = glm::lookAt(cameraPos, cameraDirection, cameraUp);

	camera_speed += 0.1f * dt; //����� ���ǵ尡 �ƴ϶� ���Ȱ���
	return view;
}

glm::mat4 matrix::GetProjection()
{
	glm::mat4 projection = glm::mat4(1.0f);
	projection = glm::perspective(glm::radians(45.0f), 1.0f, 0.1f, 300.0f); //--- ���� ���� ����: fovy, aspect, near, far

	return projection;
}

glm::mat4 matrix::GetProjection(float _fovy, float _aspect, float _near, float _far)
{
	glm::mat4 projection = glm::mat4(1.0f);
	projection = glm::perspective(glm::radians(_fovy), _aspect, _near, _far); //--- ���� ���� ����: fovy, aspect, near, far

	return projection;
}

glm::mat4 matrix::Getortho()
{
	glm::mat4 projection = glm::mat4(1.0f);
	projection = glm::ortho(-100.0f, 100.0f, -100.0f, 100.0f, -30.0f, 50.0f);

	return projection;
}



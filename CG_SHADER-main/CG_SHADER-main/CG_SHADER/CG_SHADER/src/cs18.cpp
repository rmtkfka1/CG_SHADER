#include "pch.h"
#include "cs18.h"

void cs18::Init()
{
	
	for (int i = 0; i < 6; ++i)
	{
		rect[i].Init();
	}

	line.Init();





}

void cs18::Update()
{
	
	 dt =TimeManager::GetInstance()->GetDeltaTime();

	if(KeyManager::GetInstance()->Getbutton(KeyType::Right))
	{
	
	}

	if (KeyManager::GetInstance()->Getbutton(KeyType::Left))
	{

	}
	
	camera_speed += 0.1f * dt;



}

void cs18::Render()
{

	auto& v = ObjectManager::GetInstance()->Get_Shader();
	////////////////////////////////////////////////////////
	auto simple = glm::mat4(1.0f);
	v[0]->SetUniformMat4f("u_model", simple);
	line.Render();
	////////////////////////////////////////////////////////

	{
		auto rotate = glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(0, 1.0f, 0));
		auto trans = glm::translate(glm::mat4(1.0f), glm::vec3(-5.0f, 0, 0));
		auto result = trans * rotate;
		v[0]->SetUniformMat4f("u_model", result);
		rect[rect_dir::left].Render();
	}
	//////////////////////////////////////////////////////////
	{
		auto rotate = glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(0, 1.0f, 0));
		auto trans = glm::translate(glm::mat4(1.0f), glm::vec3(5.0f, 0, 0));
		auto result = trans * rotate;
		v[0]->SetUniformMat4f("u_model", result);
		rect[rect_dir::right].Render();
	}






	float angle = camera_speed;
	auto x =  sinf(angle) * 30.0f;
	auto z =  cosf(angle) * 30.0f;
	glm::mat4 view = glm::mat4(1.0f);
	glm::vec3 cameraPos = glm::vec3(x, 10.0f,z); //--- ī�޶� ��ġ
	glm::vec3 cameraDirection = glm::vec3(0.0f, 0.0f, 0.0f); //--- ī�޶� �ٶ󺸴� ����
	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f); //--- ī�޶� ���� ����
	view = glm::lookAt(cameraPos, cameraDirection, cameraUp);
	v[0]->SetUniformMat4f("u_view", view);


	//��������
	glm::mat4 projection = glm::mat4(1.0f);
	projection = glm::perspective(glm::radians(45.0f), 1.0f, 0.1f, 100.0f); //--- ���� ���� ����: fovy, aspect, near, far
	v[0]->SetUniformMat4f("u_proj", projection);




}

#include "pch.h"
#include "ex20.h"
#include "Arm.h"
#include "Body.h"
#include "Small_arm.h"
#include "Small_body.h"
#include "Line.h"
#include "Bottom.h"

void ex20::Init()
{
	line = new Line;
	line->Init();

	body = new Body;
	body->Init();

	bottom = new Bottom;
	bottom->Init();

	arm = new Arm;
	arm->Init();
}

void ex20::Update()
{
	if(KeyManager::GetInstance()->Getbutton(KeyType::A))
	{
		dx -= 1.0f;
	}

	if (KeyManager::GetInstance()->Getbutton(KeyType::D))
	{
		dx += 1.0f;
	}

	if (KeyManager::GetInstance()->Getbutton(KeyType::W))
	{
		dy += 1.0f;
	}

	if (KeyManager::GetInstance()->Getbutton(KeyType::S))
	{
		dy -= 1.0f;
	}

	if (KeyManager::GetInstance()->Getbutton(KeyType::F))
	{
		dz -= 1.0f;
	}

	if (KeyManager::GetInstance()->Getbutton(KeyType::G))
	{
		dz += 1.0f;
	}
}

void ex20::Render()
{
	auto v =ObjectManager::GetInstance()->Get_Shader();

	v[0]->SetUniformMat4f("u_model", matrix::GetInstance()->GetSimple());
	line->Render();



	////////////////////////////////////////////
	bottom->Render();

	//몸체그리기
	v[0]->SetUniformMat4f("u_model", matrix::GetInstance()->GetTranslation(0.0f, 2.0f, 0));
	body->Render();
	

	//위에 작은 몸체그리기
	{
		auto trans = matrix::GetInstance()->GetTranslation(0.0f, 5.0f, 0);
		auto scale = matrix::GetInstance()->GetScale(0.5f,0.5f,0.5f);
		auto result = trans * scale;
		v[0]->SetUniformMat4f("u_model", result);
		body->Render();

	}

	//왼쪽 포신 만들기 
	{
		auto trans = matrix::GetInstance()->GetTranslation(-3.5f, 0.0f, 5.0f);
		auto scale = matrix::GetInstance()->GetScale(0.2f, 1.0f, 1.0f); // 즉 포신의 크기는 x:2 , y:3, z:10
		auto result = trans * scale;
		v[0]->SetUniformMat4f("u_model", result);
		body->Render();
	}
	//오른쪽 포신 만들기 
	{
		auto trans = matrix::GetInstance()->GetTranslation(3.5f, 0.0f, 5.0f);
		auto scale = matrix::GetInstance()->GetScale(0.2f, 1.0f, 1.0f); // 즉 포신의 크기는 x:2 , y:3, z:10
		auto result = trans * scale;
		v[0]->SetUniformMat4f("u_model", result);
		body->Render();
	}

	//왼쪽 눈깔 만들기
	{
	
		auto trans = matrix::GetInstance()->GetTranslation(-1.0f, 6.0f, 0);
		auto rotate = matrix::GetInstance()->GetRotate(90.0f, 1.0f, 0, 0);
		auto sclae = matrix::GetInstance()->GetScale(0.1f, 1.0f, 0.1f);
		v[0]->SetUniformMat4f("u_model", trans* sclae * rotate);
		body->Render();
	}

	//오른쪽 눈깔 만들기
	{

		auto trans = matrix::GetInstance()->GetTranslation(1.0f, 6.0f, 0);
		auto rotate = matrix::GetInstance()->GetRotate(90.0f, 1.0f, 0, 0);
		auto sclae = matrix::GetInstance()->GetScale(0.1f, 1.0f, 0.1f);
		v[0]->SetUniformMat4f("u_model", trans * sclae * rotate);
		body->Render();
	}
	



	//////////////////////////////////////////////
	/*카메라, 투영 설정*/

	v[0]->SetUniformMat4f("u_view",
		matrix::GetInstance()->GetCamera(glm::vec3(dx,dy+10.0f,dz+60.0f),glm::vec3(0,0,0)));


	v[0]->SetUniformMat4f("u_proj",
	matrix::GetInstance()->GetProjection());

	glEnable(GL_DEPTH);

}

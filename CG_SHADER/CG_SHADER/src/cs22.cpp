#include "pch.h"
#include "cs22.h"

void cs22::Init()
{


	st.Init();


	//문설정
	left.left = true;
	left.Init();
	right.left = false;
	right.Init();

	//로봇설정
	head.shape = Shape::head;
	head.Init();


	body.shape = Shape::body;
	body.Init();

	//
	left_leg.shape = Shape::leg;
	left_leg.Init();
	right_leg.shape = Shape::leg;
	right_leg.Init();

	left_arm.shape = Shape::arm;
	left_arm.Init();
	right_arm.shape = Shape::arm;
	right_arm.Init();

	nose.shape = Shape::nose;
	nose.Init();
	

}

void cs22::Update()
{
	dt =TimeManager::GetInstance()->GetDeltaTime();

	if(KeyManager::GetInstance()->GetbuttonDown(KeyType::O))
	{
		doyouwantopen = true;
	}

	if (KeyManager::GetInstance()->Getbutton(KeyType::D))
	{
		degree = 90.0f;

		
		swing += 1.0f;
		

	



		if (move_dx <= 1.8f)
		{
			move_dx += 1.0f * dt;		
		}

	
	
	}

	if (KeyManager::GetInstance()->Getbutton(KeyType::A))
	{
		degree = -90.0f;

		if (move_dx > -1.8f)
		{
			move_dx -= 1.0f * dt;
		}
	}

	if (KeyManager::GetInstance()->Getbutton(KeyType::W))
	{
		degree = 180.0f;

		move_dz -= 1.0f * dt;
	}

	if (KeyManager::GetInstance()->Getbutton(KeyType::S))
	{
		degree = 0;

		move_dz += 1.0f * dt;
	}

	
	OpenTheDoor();
	
}

void cs22::Render()
{

	auto v = ObjectManager::GetInstance()->Get_Shader();
	v[0]->SetUniformMat4f("u_model", matrix::GetInstance()->GetSimple());
	st.Render();


	{
		auto trans = matrix::GetInstance()->GetTranslation(-2.0f, 0, 2.0f);
		auto rotate = matrix::GetInstance()->GetRotate(180.0f + open_dx, 0, 1.0f, 0);
		v[0]->SetUniformMat4f("u_model", trans * rotate);
		left.Render();

	}

	{
		auto trans = matrix::GetInstance()->GetTranslation(2.0f, 0, 2.0f);
		auto rotate = matrix::GetInstance()->GetRotate(180.0f - open_dx, 0, 1.0f, 0);
		v[0]->SetUniformMat4f("u_model", trans * rotate);
		right.Render();
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////

	auto rotate2 = matrix::GetInstance()->GetRotate(swing, 1.0f, 0, 0);

	{
		auto rotate = matrix::GetInstance()->GetRotate(degree, 0, 1.0f, 0);
		auto trans = matrix::GetInstance()->GetTranslation(0, -1.2f, 0);
		auto move = matrix::GetInstance()->GetTranslation(move_dx,0,move_dz);
	
		auto result = move * rotate * trans ;
		v[0]->SetUniformMat4f("u_model", result);
		head.Render();
	}


	{
		auto rotate = matrix::GetInstance()->GetRotate(degree, 0, 1.0f, 0);
		auto trans = matrix::GetInstance()->GetTranslation(0, -1.2f, 0.05f);
		auto move = matrix::GetInstance()->GetTranslation(move_dx, 0, move_dz);
		auto result = move * rotate * trans ;
		v[0]->SetUniformMat4f("u_model", result);
		nose.Render();
	}


	{
		auto rotate = matrix::GetInstance()->GetRotate(degree, 0, 1.0f, 0);
		auto trans = matrix::GetInstance()->GetTranslation(0, -1.5f, 0);
		auto move = matrix::GetInstance()->GetTranslation(move_dx, 0, move_dz);
		auto result = move * rotate * trans ;
		v[0]->SetUniformMat4f("u_model", result);
		body.Render();
	}

	{
		auto rotate = matrix::GetInstance()->GetRotate(degree, 0, 1.0f, 0);
		auto trans = matrix::GetInstance()->GetTranslation(-0.04, -1.5f -0.3f,0);
		auto move = matrix::GetInstance()->GetTranslation(move_dx, 0, move_dz);
		auto result = move * rotate * trans * rotate2;
		v[0]->SetUniformMat4f("u_model", result);
		left_leg.Render();
	}

	{
		auto rotate = matrix::GetInstance()->GetRotate(degree, 0, 1.0f, 0);
		auto trans = matrix::GetInstance()->GetTranslation(0.04, -1.5f - 0.3f, 0);
		auto move = matrix::GetInstance()->GetTranslation(move_dx, 0, move_dz);
		auto result = move * rotate * trans * rotate2;
		v[0]->SetUniformMat4f("u_model", result);
		right_leg.Render();
	}

	{
		auto rotate = matrix::GetInstance()->GetRotate(degree, 0, 1.0f, 0);
		auto trans = matrix::GetInstance()->GetTranslation(-0.15f, -1.5f ,0);
		auto move = matrix::GetInstance()->GetTranslation(move_dx, 0, move_dz);
		auto result = move * rotate * trans * rotate2;
		v[0]->SetUniformMat4f("u_model", result);
		left_arm.Render();
	}

	{
		auto rotate = matrix::GetInstance()->GetRotate(degree, 0, 1.0f, 0);
		auto trans = matrix::GetInstance()->GetTranslation(0.15f, -1.5f, 0);
		auto move = matrix::GetInstance()->GetTranslation(move_dx, 0, move_dz);
		auto result = move * rotate * trans * rotate2;
		v[0]->SetUniformMat4f("u_model", result);
		right_arm.Render();
	}


	v[0]->SetUniformMat4f("u_view", matrix::GetInstance()->GetCamera(glm::vec3(0, 0.0f, 10.0f+dx), glm::vec3(0, 0, 0)));
	

	v[0]->SetUniformMat4f("u_proj", matrix::GetInstance()->GetProjection(45.0f, 1.0f, 0.1f, 30.0f));

}

void cs22::OpenTheDoor()
{
	if (!doyouwantopen)
	{
		return;
	}

	open_dx -= 1.0f;
	dx -= 0.02f;

	if (open_dx < -180.0f)
	{
		doyouwantopen = false;
		return;
	}

}

#include "pch.h"
#include "cs23.h"
#include "SimpleModel.h"
cs23::cs23()
{

}

cs23::~cs23()
{

}

void cs23::Init()
{

	shader = new Shader("res/shader/mvp.vs", "res/shader/mvp.fs");

	plane = new SimpleModel("res/models/test2.obj");
	box = new SimpleModel("res/models/box.obj");

	plane_texture = new Texture("res/textures/1.jpg");
	box_texture = new Texture("res/textures/box.jpg");

	plane_texture->Bind(0);
	box_texture->Bind(1);


	shader->Bind();
	shader->SetUniformMat4f("u_proj", matrix::GetInstance()->GetProjection());

	plane->PrintInfo();

	
}

void cs23::Update()
{



	if (KeyManager::GetInstance()->Getbutton(KeyType::SpaceBar))
	{
		dy += 1.0f;

	}

	if (KeyManager::GetInstance()->Getbutton(KeyType::Q))
	{
		dy -= 1.0f;

	}

	if (KeyManager::GetInstance()->Getbutton(KeyType::W))
	{
		dz += 1.0f;

	}

	if (KeyManager::GetInstance()->Getbutton(KeyType::S))
	{
		dz -= 1.0f;

	}


	if (KeyManager::GetInstance()->Getbutton(KeyType::A))
	{
		dx -= 1.0f;

	}

	if (KeyManager::GetInstance()->Getbutton(KeyType::D))
	{
		dx += 1.0f;

	}

	if (KeyManager::GetInstance()->Getbutton(KeyType::Left))
	{
		testing += 1.0f;

	}


	shader->SetUniformMat4f("u_view", matrix::GetInstance()->GetCamera(glm::vec3(-165, 30,-84), glm::vec3(0, 0, 0)));

}

void cs23::Render()
{
	

	shader->SetUniform1i("u_texture", plane_texture->GetSlot());
	plane->SetRotate(*shader, testing, 0, 1, 0);
	plane->Render(*shader);


}

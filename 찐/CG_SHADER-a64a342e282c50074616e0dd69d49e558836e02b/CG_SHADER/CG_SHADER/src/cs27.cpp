#include "pch.h"
#include "cs27.h"
#include "Model.h"
#include "Light2.h"
#include "Camera2.h"
#include "Texture.h"
void cs27::init()
{


	shader = new Shader("res/shader/simple.vs", "res/shader/simple.fs");
	shader->Bind();

	shader->SetUniformMat4f("u_model", glm::mat4(1.0f));
	shader->SetUniformMat4f("u_proj", matrix::GetInstance()->GetProjection());





	model = new Model("res/models/tank.obj");
	model2 = new Model("res/models/box.obj");



	




	light = new Light2();
	light->Spot_light.position = CameraManager::GetInstance()->m_cameraPos;
	light->Spot_light.direction = CameraManager::GetInstance()->m_cameraFront;



	texture = new Texture("res/textures/box.jpg");
	texture2 = new Texture("res/textures/1.jpg");
	texture->Bind(0);
	texture2->Bind(1);

	shader->SetUniform1i("u_texture", 0);
	



}

void cs27::update()
{
	keyupdate();


	shader->SetUniform3f("u_viewpos", CameraManager::GetInstance()->m_cameraPos.x, CameraManager::GetInstance()->m_cameraPos.y, CameraManager::GetInstance()->m_cameraPos.z);
	shader->SetUniformMat4f("u_view", CameraManager::GetInstance()->GetMatrix());

	light->Spot_light.position = CameraManager::GetInstance()->m_cameraPos;
	light->Spot_light.direction = CameraManager::GetInstance()->m_cameraFront;

	CameraManager::GetInstance()->KeyUpdate();
	CameraManager::GetInstance()->MouseUpdate(MouseManager::GetInstance()->GetMousePos().x, MouseManager::GetInstance()->GetMousePos().y);
	shader->SetUniformMat4f("u_view", CameraManager::GetInstance()->GetMatrix());



}



void cs27::render()
{

	light->UseSpotLight(*shader);

	shader->SetUniform1i("u_texture", 0);

	model->RenderModel(*shader);

	shader->SetUniform1i("u_texture", 1);

	model2->RenderModel(*shader);

}

void cs27::keyupdate()
{


	if (KeyManager::GetInstance()->GetbuttonDown(KeyType::C))
	{

	
		static int count = 0;

		if (count % 4 == 0)
		{
			light->Spot_light.diffuse = glm::vec3(1.0f, 0, 0);
			count++;
			return;


		}


		if (count % 3 == 0)
		{


			light->Spot_light.diffuse = glm::vec3(0, 1.0f, 0);
			count++;
			return;
		}



		if (count % 2 == 0)
		{



			light->Spot_light.diffuse = glm::vec3(0, 0, 1.0f);
			count++;
			return;
		}



		if (count % 1 == 0)
		{
			light->Spot_light.diffuse = glm::vec3(1.0f, 1.0f, 1.0f);
			count++;
			return;

			
	
		}


	}

	if (KeyManager::GetInstance()->GetbuttonDown(KeyType::M))
	{
		static int count = 0;


		if (count % 2 == 0)
		{

			light->point_light.distance = 0.1f;
		}
		else
		{

			light->point_light.distance = 500.0f;
		}

		count++;


	}
}
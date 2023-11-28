#include "pch.h"
#include "cs26.h"
#include "Texture.h"
#include "SimpleModel.h"
#include "Light.h"
#include "Camera.h"
#include "Camera2.h"
void cs26::Init()
{
	{
		shader = new Shader("res/shader/mvp_new.vs", "res/shader/mvp_new.fs");
		shader->Bind();
	}


		circle1 = new SimpleModel("res/models/circle.obj");

	{
		texture = new Texture("res/textures/zz.jpg");
		texture->Bind(0);
		shader->SetUniform1i("u_texture", 0);
	}



	{
		shader->SetUniformMat4f("u_view",
			matrix::GetInstance()->GetCamera(glm::vec3(0, 0, 30.0f), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)));
		shader->SetUniformMat4f("u_proj", matrix::GetInstance()->GetProjection());

	}


	shader->SetUniform3f("u_eyePosition", 0, 0, 30.0f);


	{
		light = new Light;
		light->SetLvector(glm::vec3(0 , -1.0f, 0));
		light->SetAmbientIntensity(0.1f);
		light->SetDiffuseIntensity(3.0f);
		light->SetSpecularIntensity(10.0f);
		light->SetShinIness(20.0f);

	}

	//camera = new Camera2();

}

void cs26::Update()
{
	circle1->Update();

	//camera->KeyUpdate();
	//camera->MouseUpdate(MouseManager::GetInstance()->GetMousePos().x, MouseManager::GetInstance()->GetMousePos().y);
	//shader->SetUniformMat4f("u_view",camera->GetMatrix());

	Camera2::GetInstance()->KeyUpdate();
	Camera2::GetInstance()->MouseUpdate(MouseManager::GetInstance()->GetMousePos().x, MouseManager::GetInstance()->GetMousePos().y);
	shader->SetUniformMat4f("u_view", Camera2::GetInstance()->GetMatrix());
	//KeyUpdate();
	Rotate();


}

void cs26::Render()
{
	light->UseLight(*shader);


	{
		auto result = glm::mat4(1.0f);
		shader->SetUniformMat4f("u_model", glm::mat4(1.0f));
		circle1->Render(*shader, result);
	}

	{
		auto result = matrix::GetInstance()->GetTranslation(5.0f,0,0);
		circle1->Render(*shader, result);
	}

	{
		auto result = matrix::GetInstance()->GetTranslation(-5.0f, 0, 0);
		circle1->Render(*shader, result);
	}
}

void cs26::Rotate()
{
	if (rotate == false)
	{
		return;
	}

	float dt = TimeManager::GetInstance()->GetDeltaTime();
	float angle = camera_speed;

	auto x = sinf(angle) * 20.0f;
	auto z = cosf(angle) * 20.0f;

	glm::mat4 view = glm::mat4(1.0f);
	glm::vec3 cameraPos = glm::vec3(x, 0, z); //--- 카메라 위치
	glm::vec3 cameraDirection = glm::vec3(0.0f, 0.0f, 0.0f); //--- 카메라 바라보는 방향
	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f); //--- 카메라 위쪽 방향
	view = glm::lookAt(cameraPos, cameraDirection, cameraUp);

	camera_speed += 0.5f * dt; //사실은 스피드가 아니라 라디안개념

	shader->SetUniformMat4f("u_view", view);

	shader->SetUniform3f("u_eyePosition", cameraPos.x,cameraPos.y,cameraPos.z);


}

void cs26::KeyUpdate()
{
	if (KeyManager::GetInstance()->GetbuttonDown(KeyType::C))
	{

		static int num = 0;

		num = num % 3;


		if (num == 0)
		{
			light->SetLightColor(glm::vec3(1.0f, 0, 0));
			num++;
			return;
		}

		if (num == 1)
		{
			light->SetLightColor(glm::vec3(0, 1.0f, 0));
			num++;
			return;
		}

		if (num == 2)
		{
			light->SetLightColor(glm::vec3(1.0f, 1.0f, 1.0f));
			num++;
			return;
		}


	}

	if (KeyManager::GetInstance()->GetbuttonDown(KeyType::R))
	{

		rotate = !rotate;


	}

}

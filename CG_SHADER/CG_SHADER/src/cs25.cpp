#include "pch.h"
#include "cs25.h"
#include "SimpleModel.h"
#include "Light.h"
#include "Texture.h"

cs25::cs25()
{
}

cs25::~cs25()
{
	delete rect;
	delete circle;

}

void cs25::Init()
{

	shader = new Shader("res/shader/mvp_new.vs", "res/shader/mvp_new.fs");
	shader->Bind();


	rect = new SimpleModel("res/models/cs25_rect.obj");
	camera = new SimpleModel("res/models/camera.obj");


	texture = new Texture("res/textures/box.jpg");
	texture2 = new Texture("res/textures/camera_pic.jpg");

	texture->Bind(0);
	texture2->Bind(1);


	shader->SetUniform1i("u_texture", 0);
	shader->SetUniformMat4f("u_proj", matrix::GetInstance()->GetProjection());




	light = new Light;


	shader->SetUniformMat4f("u_view",
		matrix::GetInstance()->GetCamera(glm::vec3(0, 30.0f, 30.0f), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)));

	light->SetAmbientIntensity(0.2f);
	light->SetDiffuseIntensity(1.0f);

	light->SetLvector(glm::vec3(0, 30.0f, 30.0f));

	camera->PrintInfo();
}

void cs25::Update()
{

	KeyUpdate();
	ChangeLight();


}

void cs25::Render()
{
	



	{
		
		light->UseLight(*shader);
		auto result = rect->GetRotate(rect_degree, 0, 1, 0);
		shader->SetUniform1i("u_texture", 0);
		rect->Render(*shader, result);
	}

	{
		light->SetDiffuseIntensity(1.0f);
		light->UseLight(*shader);
		auto trans = matrix::GetInstance()->GetTranslation(0,5,20);
		auto rotate = matrix::GetInstance()->GetRotate(degree,0,1,0);
		shader->SetUniform1i("u_texture", 1);
		camera->Render(*shader, rotate*trans);
	}

	



}

void cs25::ChangeLight()
{


	if (light_on)
	{
	
		light->SetDiffuseIntensity(1.0f);


	}

	else
	{
		light->SetDiffuseIntensity(0);
	}



}

void cs25::KeyUpdate()
{
	if (KeyManager::GetInstance()->GetbuttonDown(KeyType::Q))
	{
		exit(0);
	}

	if (KeyManager::GetInstance()->GetbuttonDown(KeyType::M))
	{
		light_on = !light_on;
	}

	if (KeyManager::GetInstance()->Getbutton(KeyType::R))
	{
		float dt = TimeManager::GetInstance()->GetDeltaTime();
		float angle = camera_speed;

		 x = sinf(angle) * camera_radius;
		 z = cosf(angle) * camera_radius;

		 cout << x << z << endl;
		glm::mat4 view = glm::mat4(1.0f);
		glm::vec3 cameraPos = glm::vec3(x, 30, z); //--- 카메라 위치
		glm::vec3 cameraDirection = glm::vec3(0.0f, 0.0f, 0.0f); //--- 카메라 바라보는 방향
		glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f); //--- 카메라 위쪽 방향
		view = glm::lookAt(cameraPos, cameraDirection, cameraUp);

		camera_speed += 0.5f * dt; //사실은 스피드가 아니라 라디안개념


		shader->SetUniformMat4f("u_view", view);

		light->SetAmbientIntensity(0.2f);
		light->SetDiffuseIntensity(1.0f);
		light->SetLvector(glm::vec3(x,30, z));
		
		degree += 28.5f *TimeManager::GetInstance()->GetDeltaTime();

	}

	if (KeyManager::GetInstance()->Getbutton(KeyType::Y))
	{
		rect_degree += 100.0f * TimeManager::GetInstance()->GetDeltaTime();
	}

	if (KeyManager::GetInstance()->Getbutton(KeyType::Up))
	{

		float dt = TimeManager::GetInstance()->GetDeltaTime();
		float angle = camera_speed;

		x = sinf(angle) * camera_radius;
		z = cosf(angle) * camera_radius;

		cout << x << z << endl;
		glm::mat4 view = glm::mat4(1.0f);
		glm::vec3 cameraPos = glm::vec3(x, 30, z); //--- 카메라 위치
		glm::vec3 cameraDirection = glm::vec3(0.0f, 0.0f, 0.0f); //--- 카메라 바라보는 방향
		glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f); //--- 카메라 위쪽 방향
		view = glm::lookAt(cameraPos, cameraDirection, cameraUp);

		shader->SetUniformMat4f("u_view", view);

		light->SetAmbientIntensity(0.2f);
		light->SetDiffuseIntensity(1.0f);
		light->SetLvector(glm::vec3(x, 30, z));

		camera_radius -= 10.0f *TimeManager::GetInstance()->GetDeltaTime();
	}

	if (KeyManager::GetInstance()->Getbutton(KeyType::Down))
	{

		float dt = TimeManager::GetInstance()->GetDeltaTime();
		float angle = camera_speed;

		x = sinf(angle) * camera_radius;
		z = cosf(angle) * camera_radius;

		cout << x << z << endl;
		glm::mat4 view = glm::mat4(1.0f);
		glm::vec3 cameraPos = glm::vec3(x, 30, z); //--- 카메라 위치
		glm::vec3 cameraDirection = glm::vec3(0.0f, 0.0f, 0.0f); //--- 카메라 바라보는 방향
		glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f); //--- 카메라 위쪽 방향
		view = glm::lookAt(cameraPos, cameraDirection, cameraUp);



		shader->SetUniformMat4f("u_view", view);

		light->SetAmbientIntensity(0.2f);
		light->SetDiffuseIntensity(1.0f);
		light->SetLvector(glm::vec3(x, 30, z));

	
		camera_radius += 10.0f * TimeManager::GetInstance()->GetDeltaTime();
	}


}


#include "pch.h"
#include "cs28.h"
#include "Camera2.h"
#include "Light2.h"
void cs28::init()
{

	shader = new Shader("res/shader/simple.vs", "res/shader/simple.fs");
	shader->Bind();

	shader->SetUniformMat4f("u_model", glm::mat4(1.0f));
	shader->SetUniformMat4f("u_proj", matrix::GetInstance()->GetProjection());


	 model = new Model("res/models/box_front.obj");
	model2 = new Model("res/models/box_back.obj");
	 mdoel3 = new Model("res/models/box_right.obj");
	 model4 = new Model("res/models/box_left.obj");
	model5 = new Model("res/models/box_bottom.obj");
	mdoel6 = new Model("res/models/box_top.obj");
	bg = new Model("res/models/bg.obj");


	tri = new Model("res/models/tri_front.obj");
	tri2 = new Model("res/models/tri_back.obj");
	tri3 = new Model("res/models/tri_left.obj");
	tri4 = new Model("res/models/tri_right.obj");
	tri5 = new Model("res/models/tri_bottom.obj");
	

	light = new Light2();

	texture = new Texture("res/textures/1.jpg");
	texture2 = new Texture("res/textures/box.jpg");
	texture3 = new Texture("res/textures/baby.jpg");
	texture4 = new Texture("res/textures/earth.jpg");
	texture5 = new Texture("res/textures/people_color.jpg");
	texture6 = new Texture("res/textures/zz.jpg");
	texture7= new Texture("res/textures/bg.jpg");

	texture->Bind(0);
	texture2->Bind(1);
	texture3->Bind(2);
	texture4->Bind(3);
	texture5->Bind(4);
	texture6->Bind(5);
	texture7->Bind(6);

	texture->Bind(0);
}

void cs28::update()
{
	keyupdate();



	light->Spot_light.position = CameraManager::GetInstance()->m_cameraPos;
	light->Spot_light.direction = CameraManager::GetInstance()->m_cameraFront;


}

void cs28::render()
{
	light->UseSpotLight(*shader);

	glDisable(GL_DEPTH_TEST);

	shader->SetUniform1i("u_texture", 6);
	shader->SetUniformMat4f("u_model", glm::mat4(1.0f));
	glm::mat4 projection = glm::mat4(1.0f);
	shader->SetUniformMat4f("u_view", matrix::GetInstance()->GetCamera(glm::vec3(0, 0, 1.0f), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)));
	projection = glm::ortho(-10.0F, 10.0F, 0.0F, 20.0f, -0.1f, 500.0f);
	shader->SetUniformMat4f("u_proj", projection);
	bg->RenderModel(*shader);


	glEnable(GL_DEPTH_TEST);
	shader->SetUniformMat4f("u_proj", matrix::GetInstance()->GetProjection());
	shader->SetUniform3f("u_viewpos", CameraManager::GetInstance()->m_cameraPos.x, CameraManager::GetInstance()->m_cameraPos.y, CameraManager::GetInstance()->m_cameraPos.z);
	shader->SetUniformMat4f("u_view", CameraManager::GetInstance()->GetMatrix());
	CameraManager::GetInstance()->KeyUpdate();
	CameraManager::GetInstance()->MouseUpdate(MouseManager::GetInstance()->GetMousePos().x, MouseManager::GetInstance()->GetMousePos().y);
	shader->SetUniformMat4f("u_view", CameraManager::GetInstance()->GetMatrix());

	if (a)
	{
		shader->SetUniformMat4f("u_model", matrix::GetInstance()->GetRotate(degree, 1, 0, 0));
	}
	else {
		shader->SetUniformMat4f("u_model", matrix::GetInstance()->GetRotate(degree2, 0, 1, 0));
	}

	if (six)
	{
	

		shader->SetUniform1i("u_texture", 0);
		model->RenderModel(*shader);
		shader->SetUniform1i("u_texture", 1);
		model2->RenderModel(*shader);
		shader->SetUniform1i("u_texture", 2);
		mdoel3->RenderModel(*shader);
		shader->SetUniform1i("u_texture", 3);
		model4->RenderModel(*shader);
		shader->SetUniform1i("u_texture", 4);
		model5->RenderModel(*shader);
		shader->SetUniform1i("u_texture", 5);
		mdoel6->RenderModel(*shader);
	}

	else
	{
		shader->SetUniform1i("u_texture", 0);
		tri->RenderModel(*shader);
		shader->SetUniform1i("u_texture", 1);
		tri2->RenderModel(*shader);
		shader->SetUniform1i("u_texture", 2);
		tri3->RenderModel(*shader);
		shader->SetUniform1i("u_texture", 3);
		tri4->RenderModel(*shader);
		shader->SetUniform1i("u_texture", 4);
		tri5->RenderModel(*shader);




	}


}

void cs28::keyupdate()
{

	if (KeyManager::GetInstance()->Getbutton(KeyType::X))
	{
		a = true;
		degree2 = 0;
		degree += 100.0f * TimeManager::GetInstance()->GetDeltaTime();
	}

	if (KeyManager::GetInstance()->Getbutton(KeyType::Y))
	{
		a = false;
		degree = 0;
		degree2 += 100.0f * TimeManager::GetInstance()->GetDeltaTime();
	}


	if (KeyManager::GetInstance()->GetbuttonDown(KeyType::C))
	{
		six = !six;
	}


}

#include "pch.h"
#include "cs23.h"
#include  "Model.h"
#include "Texture.h"
#include "Camera.h"
#include "Shader.h"

cs23::cs23()
{
	
	

}

cs23::~cs23()
{

}

void cs23::Init()
{
	_shader = make_shared<Shader>("res/shader/mvp.vs", "res/shader/mvp.fs");
	_shader->Bind();
	_plane = make_shared<Model>();
	_rect = make_shared<Model>();
	_texture = make_shared<Texture>("res/textures/1.jpg");
	_texture_box = make_shared<Texture>("res/textures/box.jpg");

	/*_camera = make_shared< Camera>(glm::vec3{ 0.0f,0.0f,15.0f }, glm::vec3{ 0.0f,1.0f,0.0f }, -90.0f, 0.0f, 5.0f, 0.5f);*/
	_plane->LoadModel("res/models/plane.obj");
	_rect->LoadModel("res/models/box.obj");


	_texture->Bind(1); //0번 슬롯에 바인딩
	_texture_box->Bind(2); //0번 슬롯에 바인딩

	_shader->SetUniformMat4f("u_model", matrix::GetInstance()->GetSimple());
	_shader->SetUniformMat4f("u_proj", matrix::GetInstance()->GetProjection());

	
}

void cs23::Update()
{

	//_camera->KeyControl();
	//_camera->MouseControl(MouseManager::GetInstance()->GetXChange(), MouseManager::GetInstance()->GetYChange());
	//_shader->SetUniformMat4f("u_view", _camera->calculateViewMatrix());

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

	_shader->SetUniformMat4f("u_view", matrix::GetInstance()->GetCamera(glm::vec3(0, 30,30), glm::vec3(0, 0, 0)));
}

void cs23::Render()
{


	_shader->SetUniform1i("u_texture", 1); //0번 슬롯의 텍스처를 사용할 것이라는 것을 셰이더에 명시

	_shader->SetUniformMat4f("u_model", matrix::GetInstance()->GetTranslation(0,0,0));
	_plane->RenderModel(*_shader);

	_shader->SetUniform1i("u_texture", 2); //0번 슬롯의 텍스처를 사용할 것이라는 것을 셰이더에 명시

	_shader->SetUniformMat4f("u_model", matrix::GetInstance()->GetRotate(dy,0,1.0f, 0));
	_rect->RenderModel(*_shader);



}

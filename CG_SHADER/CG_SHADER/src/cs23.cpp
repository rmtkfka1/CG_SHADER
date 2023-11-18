#include "pch.h"
#include "cs23.h"
#include "SimpleModel.h"
#include "BoxCollider.h"
#include "CollisionManager.h"
#include "Player.h"
cs23::cs23()
{

}

cs23::~cs23()
{

}

void cs23::Init()
{

	shader = new Shader("res/shader/mvp.vs", "res/shader/mvp.fs");

	plane = new SimpleModel("res/models/cs24_set.obj");

	{
		box = new SimpleModel("res/models/box.obj");
		BoxCollider* ptr = new BoxCollider;
		box->AddComponent(ptr);
		box->SetCenter_x(box->GetCenter_x() + 20);
		GET_SINGLE(CollisionManager)->AddCollider(ptr);
	}


	door_left = new SimpleModel("res/models/door_left.obj");
	door_left->SetCenter(glm::vec3(door_left->GetCenter().x - door_left->GetSize().x/2, door_left->GetCenter().y, door_left->GetCenter().z));


	door_right = new SimpleModel("res/models/door_right.obj");
	door_right->SetCenter(glm::vec3(door_right->GetCenter().x + door_right->GetSize().x / 2, door_right->GetCenter().y, door_right->GetCenter().z));

	hat = new SimpleModel("res/models/hat.obj");

	{
		people_body = new Player("res/models/people.obj");
		BoxCollider* ptr = new BoxCollider;
		people_body->AddComponent(ptr);
		GET_SINGLE(CollisionManager)->AddCollider(ptr);
	}

	plane_texture = new Texture("res/textures/1.jpg");
	box_texture = new Texture("res/textures/box.jpg");
	body_texture = new Texture("res/textures/ÇØ¸®.jpeg");

	plane_texture->Bind(0);
	box_texture->Bind(1);
	body_texture->Bind(2);


	shader->Bind();
	shader->SetUniformMat4f("u_proj", matrix::GetInstance()->GetProjection());

	people_body->PrintInfo();
	people_body->Init();


	
}

void cs23::Update()
{


	keyboard();

	if (door_open)
	{
		door_animation();
	}

	if (is_jump)
	{
		jump_animation();
	}

	plane->Update();
	box->Update();
	door_left->Update();
	door_right->Update();
	hat->Update();
	people_body->Update();


	shader->SetUniformMat4f("u_view", matrix::GetInstance()->GetCamera(glm::vec3(dx,dy,dz), glm::vec3(0, 0, 0)));
	CollisionManager::GetInstance()->Update();
}


void cs23::keyboard()
{


	if (KeyManager::GetInstance()->GetbuttonDown(KeyType::O))
	{
		door_open = true;
	}


	if (KeyManager::GetInstance()->Getbutton(KeyType::Q))
	{
		dy -= 1.0f;

	}

	if (KeyManager::GetInstance()->Getbutton(KeyType::W))
	{
		dz -= 1.0f;

	}

	if (KeyManager::GetInstance()->Getbutton(KeyType::S))
	{
		dz += 1.0f;

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
	
	
		people_x -= 40.0 * TimeManager::GetInstance()->GetDeltaTime();
		people_body->SetCenter_x(people_body->GetCenter_x() - 40.0 * TimeManager::GetInstance()->GetDeltaTime());


	}

	if (KeyManager::GetInstance()->Getbutton(KeyType::Right))
	{
	
		people_x += 40.0 * TimeManager::GetInstance()->GetDeltaTime();
		people_body->SetCenter_x(people_body->GetCenter_x() + 40.0 * TimeManager::GetInstance()->GetDeltaTime());
	}

	if (KeyManager::GetInstance()->Getbutton(KeyType::Down))
	{

		people_z += 40.0 * TimeManager::GetInstance()->GetDeltaTime();
		people_body->SetCenter_z(people_body->GetCenter_z() + 40.0 * TimeManager::GetInstance()->GetDeltaTime());
	}

	if (KeyManager::GetInstance()->Getbutton(KeyType::Up))
	{

		people_z -= 40.0 * TimeManager::GetInstance()->GetDeltaTime();
		people_body->SetCenter_z(people_body->GetCenter_z() - 40.0 * TimeManager::GetInstance()->GetDeltaTime());
	}

	if (KeyManager::GetInstance()->GetbuttonDown(KeyType::SpaceBar))
	{
		is_jump=true;
	}

	
}

void cs23::Render()
{

	// set
	{
		shader->SetUniform1i("u_texture", plane_texture->GetSlot());
		auto reuslt =plane->GetTransPose(0, 0, 0);
		plane->Render(*shader, reuslt);
	}

	//people
	{
		shader->SetUniform1i("u_texture", body_texture->GetSlot());
		auto result =people_body->GetTransPose(people_x, people_y, people_z);
		people_body->Render(*shader, result);
	}

	//box
	{
		shader->SetUniform1i("u_texture", box_texture->GetSlot());
		auto result = box->GetTransPose(20, 0, 0);
		box->Render(*shader,result);
	}

	//door_left
	{
		shader->SetUniform1i("u_texture", box_texture->GetSlot());
		auto rotate =door_left->GetRotate(left_door_degree, 0, 1, 0);
		door_left->Render(*shader, rotate);
	}

	//door_right
	{
		shader->SetUniform1i("u_texture", box_texture->GetSlot());
		auto rotate = door_right->GetRotate(right_door_degree, 0, 1, 0);
		door_right->Render(*shader, rotate);
	}

	//ÁöºØ
	{
		shader->SetUniform1i("u_texture", box_texture->GetSlot());
		auto result =hat->GetTransPose(0,0,0);
		hat->Render(*shader,result);

	}


}

void cs23::door_animation()
{
	if (left_door_degree > -180)
	{
		left_door_degree -= 100.0f * TimeManager::GetInstance()->GetDeltaTime();
	}

	if (right_door_degree < 180)
	{
		right_door_degree += 100.0f * TimeManager::GetInstance()->GetDeltaTime();
	}

	if (dy > 90)
	{
		dy -= 100.0f * TimeManager::GetInstance()->GetDeltaTime();
	}

	if (dz > 220)
	{
		dz -= 100.0f * TimeManager::GetInstance()->GetDeltaTime();
	}

}

void cs23::jump_animation()
{

	if (is_down == false)
	{
		if (people_y < 30)
		{
			people_y += 100.0f * TimeManager::GetInstance()->GetDeltaTime();
			people_body->SetCenter_y(people_body->GetCenter_y() + 100.0f * TimeManager::GetInstance()->GetDeltaTime());

		}

		if (people_y > 30)
		{
			people_y = 30;
			people_body->SetCenter_y(people_body->GetFirstCenter_y() + 30);
			is_down = true;
		}
	}

	else
	{
		people_y -= 100.0f * TimeManager::GetInstance()->GetDeltaTime();
		people_body->SetCenter_y(people_body->GetCenter_y() - 100.0f * TimeManager::GetInstance()->GetDeltaTime());

		if (people_y < 0)
		{
			is_down = false;
			is_jump = false;
			people_y = 0;
			people_body->SetCenter_y(people_body->GetFirstCenter_y() + 0);
			return;
		}

	}

}

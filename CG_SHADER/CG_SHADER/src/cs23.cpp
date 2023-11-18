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

	plane = new SimpleModel("res/models/cs24_set.obj");
	box = new SimpleModel("res/models/box.obj");

	door_left = new SimpleModel("res/models/door_left.obj");
	door_left->SetCenter(glm::vec3(door_left->GetCenter().x - door_left->GetSize().x/2, door_left->GetCenter().y, door_left->GetCenter().z));



	door_right = new SimpleModel("res/models/door_right.obj");
	door_right->SetCenter(glm::vec3(door_right->GetCenter().x + door_right->GetSize().x / 2, door_right->GetCenter().y, door_right->GetCenter().z));

	hat = new SimpleModel("res/models/hat.obj");

	people_body = new SimpleModel("res/models/people.obj");


	plane_texture = new Texture("res/textures/1.jpg");
	box_texture = new Texture("res/textures/box.jpg");
	body_texture = new Texture("res/textures/ÇØ¸®.jpeg");

	plane_texture->Bind(0);
	box_texture->Bind(1);
	body_texture->Bind(2);


	shader->Bind();
	shader->SetUniformMat4f("u_proj", matrix::GetInstance()->GetProjection());

	door_left->PrintInfo();

	
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


	shader->SetUniformMat4f("u_view", matrix::GetInstance()->GetCamera(glm::vec3(dx,dy,dz), glm::vec3(0, 0, 0)));
	//cout << dx << " " << " " << dy << " " << dz << endl;
	//cout << testing << " " << testing2 << endl;
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



	}

	if (KeyManager::GetInstance()->Getbutton(KeyType::Right))
	{
		people_x += 40.0 * TimeManager::GetInstance()->GetDeltaTime();
	}

	if (KeyManager::GetInstance()->Getbutton(KeyType::Down))
	{
		people_z += 40.0 * TimeManager::GetInstance()->GetDeltaTime();
	}

	if (KeyManager::GetInstance()->Getbutton(KeyType::Up))
	{
		people_z -= 40.0 * TimeManager::GetInstance()->GetDeltaTime();
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
		plane->SetSimple(*shader);
		plane->Render(*shader);
	}

	//people
	{
		shader->SetUniform1i("u_texture", body_texture->GetSlot());
		people_body->SetTransPose(*shader,people_x, people_y, people_z);

		people_body->Render(*shader);
	}

	//box
	{
		shader->SetUniform1i("u_texture", box_texture->GetSlot());
		auto result = box->GetScale(1.7f, 1.0f, 1.7f) * plane->GetTransPose(25, 0, 15);
		shader->SetUniformMat4f("u_model", result);
		box->Render(*shader);
	}

	//door_left
	{
		shader->SetUniform1i("u_texture", box_texture->GetSlot());
		auto rotate =door_left->GetRotate(left_door_degree, 0, 1, 0);
		shader->SetUniformMat4f("u_model", rotate);
		door_left->Render(*shader);
	}

	//door_right
	{
		shader->SetUniform1i("u_texture", box_texture->GetSlot());
		auto rotate = door_right->GetRotate(right_door_degree, 0, 1, 0);
		shader->SetUniformMat4f("u_model", rotate);
		door_right->Render(*shader);
	}

	//ÁöºØ
	{
		shader->SetUniform1i("u_texture", box_texture->GetSlot());
		hat->SetSimple(*shader);
		hat->Render(*shader);
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
		if (people_y < 20)
		{
			people_y += 100.0f * TimeManager::GetInstance()->GetDeltaTime();
		}

		if (people_y > 20)
		{
			people_y = 20;
			is_down = true;
		}
	}

	else
	{
		people_y -= 100.0f * TimeManager::GetInstance()->GetDeltaTime();

		if (people_y < 0)
		{
			is_down = false;
			is_jump = false;
			people_y = 0;
			return;
		}

	}

}

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






	for (int i = 0; i < 4; ++i)
	{
		p1[i] = new SimpleModel("res/models/piilar.obj");
		BoxCollider* ptr = new BoxCollider;
		p1[i]->SetCenter_x(p1[i]->GetCenter_x()-i*25);
		p1[i]->AddComponent(ptr);
		GET_SINGLE(CollisionManager)->AddCollider(ptr);
	}


	{
		hey_top = new SimpleModel("res/models/p2.obj");
		BoxCollider* ptr = new BoxCollider;
		hey_top->SetCenter_x(hey_top->GetCenter_x() - 25);
		hey_top->AddComponent(ptr);
		GET_SINGLE(CollisionManager)->AddCollider(ptr);
	}



	{
		hey_left = new SimpleModel("res/models/p1.obj");
		BoxCollider* ptr = new BoxCollider;
		hey_left->SetCenter_x(hey_left->GetCenter_x() - 20);
		hey_left->AddComponent(ptr);
		GET_SINGLE(CollisionManager)->AddCollider(ptr);
	}

	{
		hey_right = new SimpleModel("res/models/p1.obj");
		BoxCollider* ptr = new BoxCollider;
		hey_right->AddComponent(ptr);
		GET_SINGLE(CollisionManager)->AddCollider(ptr);
	}


	{
		box2 = new SimpleModel("res/models/box.obj");
		BoxCollider* ptr = new BoxCollider;
		box2->AddComponent(ptr);
		box2->SetCenter_x(box2->GetCenter_x() - 40);
		box2->SetCenter_z(box2->GetCenter_z() + 20);
		GET_SINGLE(CollisionManager)->AddCollider(ptr);
	}


	{
		box = new SimpleModel("res/models/box.obj");
		BoxCollider* ptr = new BoxCollider;
		box->AddComponent(ptr);
		box->SetCenter_x(box->GetCenter_x() + 20);
		GET_SINGLE(CollisionManager)->AddCollider(ptr);
	}

	{
		box3 = new SimpleModel("res/models/box.obj");
		BoxCollider* ptr = new BoxCollider;
		box3->AddComponent(ptr);
		box3->SetCenter_x(box3->GetCenter_x() + 50);
		box3->SetCenter_z(box3->GetCenter_z() + 50);
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
	baby_texture = new Texture("res/textures/baby.jpg");

	plane_texture->Bind(0);
	box_texture->Bind(1);
	body_texture->Bind(2);
	baby_texture->Bind(3);

	shader->Bind();
	shader->SetUniformMat4f("u_proj", matrix::GetInstance()->GetProjection());

	people_body->PrintInfo();
	people_body->Init();


	
}

void cs23::Update()
{


	keyboard();
	if (!is_jump)
	{
		if (people_body->_collusion == false)
		{
			if (people_y > 0)
			{
				people_y -= 100.0f * TimeManager::GetInstance()->GetDeltaTime();
				people_body->SetCenter_y(people_body->GetFirstCenter_y() + people_y);
			}
		}
	}

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
	box2->Update();
	box3->Update();
	door_left->Update();
	door_right->Update();
	hat->Update();
	people_body->Update();
	hey_left->Update();
	hey_right->Update();
	hey_top->Update();


	for (int i = 0; i < 4; ++i)
	{
		p1[i]->Update();
	}




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

	if (KeyManager::GetInstance()->GetbuttonDown(KeyType::T))
	{
		makebaby();

	}

	if (KeyManager::GetInstance()->Getbutton(KeyType::Left))
	{
		if (people_body->GetCenter().x < plane->GetCenter().x - plane->GetSize().x/2)
		{
			return;
		}

		if (people_body->_collusion && people_body->GetCenter_y() - people_body->GetSize().y / 2+10 <= box->GetCenter_y() + box->GetSize().y / 2)
		{

			people_x += 3.0f;
			people_body->SetCenter_x(people_body->GetCenter_x() + 3.0f);
			return;
		}
	
		people_x -= 40.0 * TimeManager::GetInstance()->GetDeltaTime();
		people_body->SetCenter_x(people_body->GetCenter_x() - 40.0 * TimeManager::GetInstance()->GetDeltaTime());

	

	}

	if (KeyManager::GetInstance()->Getbutton(KeyType::Right))
	{
		if (people_body->GetCenter().x > plane->GetCenter().x + plane->GetSize().x / 2 - 17)
		{
			return;
		}
	
		if (people_body->_collusion && people_body->GetCenter_y() - people_body->GetSize().y / 2 +10 <= box->GetCenter_y() + box->GetSize().y / 2)
		{

			people_x -= 3.0f;
			people_body->SetCenter_x(people_body->GetCenter_x() - 3.0f);
			return;
		}
	
		people_x += 40.0 * TimeManager::GetInstance()->GetDeltaTime();
		people_body->SetCenter_x(people_body->GetCenter_x() + 40.0 * TimeManager::GetInstance()->GetDeltaTime());

	
	
	}

	if (KeyManager::GetInstance()->Getbutton(KeyType::Down))
	{
		


		if (people_body->_collusion && people_body->GetCenter_y() - people_body->GetSize().y / 2 + 10 <= box->GetCenter_y() + box->GetSize().y / 2)
		{

			people_z -= 3.0f;
			people_body->SetCenter_z(people_body->GetCenter_z() - 3.0f);
			return;
		}

		people_z += 40.0 * TimeManager::GetInstance()->GetDeltaTime();
		people_body->SetCenter_z(people_body->GetCenter_z() + 40.0 * TimeManager::GetInstance()->GetDeltaTime());


	
		
	}

	if (KeyManager::GetInstance()->Getbutton(KeyType::Up))
	{
		if (people_body->GetCenter().z < -60)
		{
			return;
		}



		if (people_body->_collusion && people_body->GetCenter_y() - people_body->GetSize().y/2 +10 <= box->GetCenter_y()+box->GetSize().y/2)
		{

			people_z += 3.0f;
			people_body->SetCenter_z(people_body->GetCenter_z() + 3.0f);
			return;
		}

		people_z -= 40.0 * TimeManager::GetInstance()->GetDeltaTime();
		people_body->SetCenter_z(people_body->GetCenter_z() - 40.0 * TimeManager::GetInstance()->GetDeltaTime());

	
	}

	if (KeyManager::GetInstance()->GetbuttonDown(KeyType::Y))
	{
		removebaby();
	}

	if (KeyManager::GetInstance()->GetbuttonDown(KeyType::SpaceBar))
	{
		is_jump=true;
	}

	if (KeyManager::GetInstance()->Getbutton(KeyType::R))
	{
		testing += 1.0f;
	}

	if (KeyManager::GetInstance()->Getbutton(KeyType::F))
	{
		baby_is_jump = true;
	}

	baby_jump_animation();

	following_anim(people_body->GetCenter_x(), people_body->GetCenter_z());
}

void cs23::Render()
{


	for (int i = 0; i < 4; ++i)
	{
		shader->SetUniform1i("u_texture", box_texture->GetSlot());
		auto reuslt = p1[i]->GetTransPose(0-i*25, 0, 0);
		p1[i]->Render(*shader, reuslt);
	}

	{
		shader->SetUniform1i("u_texture", box_texture->GetSlot());
		auto reuslt = hey_top->GetTransPose(-25, 0, 0);
		hey_top->Render(*shader, reuslt);
	}

	{
		shader->SetUniform1i("u_texture", box_texture->GetSlot());
		auto reuslt = hey_right->GetTransPose(0, 0, 0);
		hey_right->Render(*shader, reuslt);
	}

	{
		shader->SetUniform1i("u_texture", box_texture->GetSlot());
		auto reuslt = hey_left->GetTransPose(-20, 0, 0);
		hey_left->Render(*shader, reuslt);
	}

	// set
	{
		shader->SetUniform1i("u_texture", plane_texture->GetSlot());
		auto reuslt =plane->GetTransPose(0, 0, 0);
		plane->Render(*shader, reuslt);
	}



	//box
	{
		shader->SetUniform1i("u_texture", box_texture->GetSlot());
		auto trans = box->GetTransPose(20, 0, 0);
		auto rotate = box->GetRotate(testing, 0, 1, 0);
		auto result = rotate * trans;
		box->Render(*shader, result);
	}
	//box2
	{
		shader->SetUniform1i("u_texture", box_texture->GetSlot());
		auto result = box->GetTransPose(-40, 0, 20);
		box2->Render(*shader, result);
	}
	//box3
	{
		shader->SetUniform1i("u_texture", box_texture->GetSlot());
		auto result = box->GetTransPose(50, 0, 50);
		box3->Render(*shader, result);
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

	//people
	{

		shader->SetUniform1i("u_texture", body_texture->GetSlot());
		auto result = people_body->GetTransPose(people_x, people_y, people_z);
		people_body->Render(*shader, result);
	}



	for (int i = 0; i < v_baby.size(); ++i)
	{
		shader->SetUniform1i("u_texture",baby_texture->GetSlot());
		//auto result = v_baby[i]->GetTransPose(people_body->GetCenter_x()-i*10,baby_y, people_body->GetCenter_z()-i*10);
		auto result = v_baby[i]->GetTransPose(baby_x-i*5, baby_y, baby_z-i*5);
		v_baby[i]->Render(*shader, result);
	}




}

void cs23::following_anim(float tx, float tz)
{

	 
	for (int i = 0; i < v_baby.size(); ++i)
	{
	
		float dir = atan2(tx - baby_x, tz - baby_z);
		baby_x += 3*sinf(dir)*TimeManager::GetInstance()->GetDeltaTime();
		baby_z += 3*cosf(dir)*TimeManager::GetInstance()->GetDeltaTime();

	}



}

void cs23::makebaby()
{
	

	
	{
		SimpleModel *baby = new SimpleModel("res/models/baby.obj");

		if (v_baby.size() == 3)
		{
			return;
		}

		v_baby.push_back(baby);
	}



}

void cs23::removebaby()
{

	if (v_baby.size() == 0)
	{
		return;
	}


	v_baby.pop_back();


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
	if (people_body->_collusion)
	{
		is_down = false;
		is_jump = false;
		return;
	}

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

void cs23::baby_jump_animation()
{
	if (baby_is_jump == false)
	{
		return;
	}

	if (baby_is_down == false)
	{
		if (baby_y < 30)
		{
			baby_y += 100.0f * TimeManager::GetInstance()->GetDeltaTime();

		}

		if (baby_y > 30)
		{
			baby_y = 30;
			baby_is_down = true;
		}
	}

	else
	{
		baby_y -= 100.0f * TimeManager::GetInstance()->GetDeltaTime();
	
		if (baby_y < 0)
		{
			baby_is_down = false;
			baby_is_jump = false;
			baby_y = 0;
			return;
		}

	}



}

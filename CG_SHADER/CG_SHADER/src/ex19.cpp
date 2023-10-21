
#include "pch.h"
#include "ex19.h"

void ex19::Init()
{
	cout << "=========================================" << endl;
	cout << "1 : �ָ��� , 2 ���̾� �� ��ȯ " << endl;
	cout << " W,A,S,D  : X,Y�� �̵� " << endl;
	cout << " F,G : Z�� �̵� " << endl;
	cout << " T,Y : Y�� ���� ���� ȸ�� " << endl;
	cout << " Z,X : Z�� ���� ���� ȸ�� " << endl;
	cout << " O,P : �������� / ���� ����" << endl;

}

void ex19::Update()
{
	dt = TimeManager::GetInstance()->GetDeltaTime();


	speed_0 += 100 * dt;
	speed_1 += 150 * dt;
	speed_2 += 200 * dt;

	moon->Update();
	star->Update();
	earth->Update();

	if (KeyManager::GetInstance()->Getbutton(KeyType::W))
	{
		dy += 10.0f * dt;
	}

	if (KeyManager::GetInstance()->Getbutton(KeyType::S))
	{
		dy -= 10.0f * dt;
	}

	if (KeyManager::GetInstance()->Getbutton(KeyType::A))
	{
		dx -= 10.0f * dt;
	}

	if (KeyManager::GetInstance()->Getbutton(KeyType::D))
	{
		dx += 10.0f * dt;
	}

	if (KeyManager::GetInstance()->Getbutton(KeyType::F))
	{
		dz -= 10.0f * dt;
	}

	if (KeyManager::GetInstance()->Getbutton(KeyType::G))
	{
		dz += 10.0f * dt;
	}

	if (KeyManager::GetInstance()->Getbutton(KeyType::Y))
	{
		rotate_y += 30.0f * dt;
	}

	if (KeyManager::GetInstance()->Getbutton(KeyType::T))
	{
		rotate_y -= 30.0f * dt;
	}

	if (KeyManager::GetInstance()->Getbutton(KeyType::Z))
	{
		rotate_z -= 30.0f * dt;
	}

	if (KeyManager::GetInstance()->Getbutton(KeyType::X))
	{
		rotate_z += 30.0f * dt;
	}

	if (KeyManager::GetInstance()->Getbutton(KeyType::O))
	{
		perspective = false;
	}

	if (KeyManager::GetInstance()->Getbutton(KeyType::P))
	{
		perspective = true;
	}




}

void ex19::Render()
{


	auto v = ObjectManager::GetInstance()->Get_Shader();
	auto z = matrix::GetInstance()->GetRotate(rotate_z, 0, 0, 1.0f);


	//����
	{
		
		auto trans = matrix::GetInstance()->GetTranslation(dx, dy, dz);
		v[0]->SetUniformMat4f("u_model", trans);
		v[0]->SetUniform4f("u_color", 0, 0, 1.0f, 0);
		earth->Render();
	}

	v[0]->SetUniform4f("u_color", 0, 0, 0, 0);
	//���� ��
	{
		auto trans = matrix::GetInstance()->GetTranslation(dx, dy, dz);
		auto r1 = matrix::GetInstance()->GetRotate(90, 1.0f, 1.0f, 0);
		/*auto r3 = matrix::GetInstance()->GetRotate(-90, 1.0f, 1.0f, 0);*/
		auto r2 = matrix::GetInstance()->GetRotate(rotate_y, 0, 1.0f, 0);
	/*	auto r4 = matrix::GetInstance()->GetRotate(90, 1.0f, 1.0f, 0);*/
		v[0]->SetUniformMat4f("u_model", trans*z*r2 *r1);
		earth_circle->Render();

	}

	//���� ��
	{
		auto trans = matrix::GetInstance()->GetTranslation(dx, dy, dz);
		auto r1 = matrix::GetInstance()->GetRotate(90, -1.0f, 1.0f, 0);
		auto r2 = matrix::GetInstance()->GetRotate(rotate_y, 0, 1.0f, 0);
		v[0]->SetUniformMat4f("u_model", trans*z*r2*r1);
		earth_circle->Render();
	}

	//���� ��
	{
		auto trans = matrix::GetInstance()->GetTranslation(dx, dy, dz);
		auto r1 = matrix::GetInstance()->GetRotate(90.0f, 1.0f, 0, 0);
		v[0]->SetUniformMat4f("u_model", trans*r1);
		earth_circle->Render();
	}



	v[0]->SetUniform4f("u_color", 0, 1.0f, 0, 0);

	//��1�� ��ġ
	{

		auto r2 = matrix::GetInstance()->GetRotate(rotate_y, 0, 1.0f, 0);
		auto trans = matrix::GetInstance()->GetTranslation(dx, dy, dz);
		auto trans1 = matrix::GetInstance()->GetTranslation(12.0f, 0, 0);
		auto rotate1 = matrix::GetInstance()->GetRotate(speed_0, 0, 1.0f, 0);
		auto result = trans*r2*rotate1 * trans1;
		v[0]->SetUniformMat4f("u_model", result);
		moon->Render();
	}



	//��2�� ��ġ
	{
		auto r2 = matrix::GetInstance()->GetRotate(rotate_y, 0, 1.0f, 0);
		auto trans = matrix::GetInstance()->GetTranslation(dx, dy, dz);
		auto trans1 = matrix::GetInstance()->GetTranslation(0,0,12.0f);
		auto r1 = matrix::GetInstance()->GetRotate(speed_1, -1.0f, 1.0f, 0);
		v[0]->SetUniformMat4f("u_model", trans*z*r2*r1*trans1);
		moon->Render();
	}
	auto r2 = matrix::GetInstance()->GetRotate(rotate_y, 0, 1.0f, 0);

	//��3�� ��ġ
	{
		auto trans = matrix::GetInstance()->GetTranslation(dx, dy, dz);
		auto trans1 = matrix::GetInstance()->GetTranslation(0, 0, -12.0f);
		auto r1 = matrix::GetInstance()->GetRotate(speed_2, 1.0f, 1.0f, 0);
		v[0]->SetUniformMat4f("u_model", trans*z*r2*r1 * trans1);
		moon->Render();
	}


	//��1�� �����˵�
	{
		auto trans = matrix::GetInstance()->GetTranslation(dx, dy, dz);
		auto rotate1 = matrix::GetInstance()->GetRotate(90.0f, 1.0f,0,0);
		auto trans1 = matrix::GetInstance()->GetTranslation(12.0f, 0, 0);
		auto rotate2 = matrix::GetInstance()->GetRotate(speed_0, 0, 1.0f, 0);
		auto result = trans*r2*rotate2 *trans1*rotate1;
		v[0]->SetUniformMat4f("u_model", result);
		moon_circle->Render();
	}

	auto trans = matrix::GetInstance()->GetTranslation(dx, dy, dz);
	//��2�� �����˵�
	{
		auto rotate1 = matrix::GetInstance()->GetRotate(90.0f, 1.0f, 1.0f, 0);
		auto trans1 = matrix::GetInstance()->GetTranslation(0, 0, 12.0f);
		auto rotate2 = matrix::GetInstance()->GetRotate(speed_1, -1.0f, 1.0f, 0);
		auto result = trans*z*r2 *rotate2*trans1*rotate1;
		v[0]->SetUniformMat4f("u_model", result);
		moon_circle->Render();
	}


	//��3�� �����˵�
	{
		auto rotate1 = matrix::GetInstance()->GetRotate(90.0f, -1.0f, 1.0f, 0);
		auto trans1 = matrix::GetInstance()->GetTranslation(0, 0, -12.0f);
		auto rotate2 = matrix::GetInstance()->GetRotate(speed_2, 1.0f, 1.0f, 0);
		auto result = trans*z*r2 *rotate2 * trans1 * rotate1;
		v[0]->SetUniformMat4f("u_model", result);
		moon_circle->Render();
	}


	v[0]->SetUniform4f("u_color", 1.0f, 0, 0, 0);

	//��1�� ����
	{
		auto rotate1 = matrix::GetInstance()->GetRotate(90.0f, 1.0f, 0, 0);
		auto trans1 = matrix::GetInstance()->GetTranslation(17.0f, 0, 0);
		auto rotate2 = matrix::GetInstance()->GetRotate(speed_0, 0, 1.0f, 0);
		auto result = trans*r2*rotate2 * trans1 * rotate1;
		v[0]->SetUniformMat4f("u_model", result);
		star->Render();
	}


	//��2�� �����˵�
	{
		auto rotate1 = matrix::GetInstance()->GetRotate(90.0f, 1.0f, 1.0f, 0);
		auto trans1 = matrix::GetInstance()->GetTranslation(0, 0, 17.0f);
		auto rotate2 = matrix::GetInstance()->GetRotate(speed_1, - 1.0f, 1.0f, 0);
		auto result = trans*z*r2*rotate2 * trans1 * rotate1;
		v[0]->SetUniformMat4f("u_model", result);
		star->Render();
	}

	//��3 �� �����˵�
	{
		auto rotate1 = matrix::GetInstance()->GetRotate(90.0f, -1.0f, 1.0f, 0);
		auto trans1 = matrix::GetInstance()->GetTranslation(0, 0, -17.0f);
		auto rotate2 = matrix::GetInstance()->GetRotate(speed_2, 1.0f, 1.0f, 0);
		auto result = trans*z*r2*rotate2 * trans1 * rotate1;
		v[0]->SetUniformMat4f("u_model", result);
		star->Render();
	}


	v[0]->SetUniformMat4f("u_view", matrix::GetInstance()->GetCamera(glm::vec3(0, 10.0f, 40.0f), glm::vec3(0, 0, 0)));
	
	if (perspective)
	{
		v[0]->SetUniformMat4f("u_proj", matrix::GetInstance()->GetProjection());
	}
	else
	{
		v[0]->SetUniformMat4f("u_proj", matrix::GetInstance()->Getortho());
	}


}

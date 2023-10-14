#include "pch.h"
#include "cs16.h"

void cs16::Init()
{

	glutKeyboardFunc(call_back_key);

	cube.Init(cube_m_pos, 0.1f, 0);
	line.Init();
	mode = revolve;
	cb.revolve.y = 0.0f;
	cb.rotate.x = 10.0f;
	////////////////////////
	pyramid.Init(pr_m_pos, 0.1f, 0);
	pr.revolve.y = 0.0f;
	pr.rotate.x = 10.0f;

}

void cs16::Update()
{
	
}

void cs16::Render()
{

	
	auto& v = ObjectManager::GetInstance()->Get_Shader();
	//===================================================================================//
	auto simple = glm::mat4(1.0f);
	v[0]->SetUniformMat4f("u_model", simple);
	line.Render();
	//���α߱�
	//===================================================================================//
	

	if (mode == revolve) //�Ѵ� ����
	{
		cb.t1 = glm::rotate(glm::mat4(1.0f), glm::radians(cb.revolve.y), glm::vec3(0, 1.0f, 0));
		cb.t2 = glm::rotate(glm::mat4(1.0f), glm::radians(10.0f), glm::vec3(1.0f, 0, 0));
		cb.result = cb.t2 * cb.t1;

		v[0]->SetUniformMat4f("u_model", cb.result);
		cb.temp = cb.result * glm::vec4(cube_m_pos.x, cube_m_pos.y, cube_m_pos.z, 1);
		cube.Render();


		pr.t1 = glm::rotate(glm::mat4(1.0f), glm::radians(pr.revolve.y), glm::vec3(0, 1.0f, 0));
		pr.t2 = glm::rotate(glm::mat4(1.0f), glm::radians(10.0f), glm::vec3(1.0f, 0, 0));
		pr.result = pr.t2 * pr.t1;

		v[0]->SetUniformMat4f("u_model", pr.result);
		pr.temp = pr.result * glm::vec4(pr_m_pos.x, pr_m_pos.y, pr_m_pos.z, 1);
		pyramid.Render();

	}



	else if (mode == Mode::rotate) // �Ѵ� ����
	{
		cb.goto00 = glm::translate(glm::mat4(1.0f), glm::vec3(-cb.temp.x, -cb.temp.y, -cb.temp.z));
		cb.t3 = glm::rotate(glm::mat4(1.0f), glm::radians(cb.rotate.y), glm::vec3(0, 1.0f, 0));
		cb.t4 = glm::rotate(glm::mat4(1.0f), glm::radians(cb.rotate.x), glm::vec3(1.0f, 0, 0));
		cb.backtopos = glm::translate(glm::mat4(1.0f), glm::vec3(cb.temp.x, cb.temp.y, cb.temp.z));

		cb.result2 = cb.backtopos * cb.t4*cb.t3 * cb.goto00 * cb.result;
		v[0]->SetUniformMat4f("u_model", cb.result2);
		cube.Render();

		pr.goto00 = glm::translate(glm::mat4(1.0f), glm::vec3(-pr.temp.x, -pr.temp.y, -pr.temp.z));
		pr.t3 = glm::rotate(glm::mat4(1.0f), glm::radians(pr.rotate.y), glm::vec3(0, 1.0f, 0));
		pr.t4 = glm::rotate(glm::mat4(1.0f), glm::radians(pr.rotate.x), glm::vec3(1.0f, 0, 0));
		pr.backtopos = glm::translate(glm::mat4(1.0f), glm::vec3(pr.temp.x, pr.temp.y, pr.temp.z));

		pr.result2 = pr.backtopos * pr.t4 * pr.t3 * pr.goto00 * pr.result;
		v[0]->SetUniformMat4f("u_model", pr.result2);
		pyramid.Render();

	}

	
	
	



}

void cs16::call_back_key(unsigned char key, int x, int y)
{
	cs16::GetInstance()->Update_key(key, x, y);
}

void cs16::Update_key(unsigned char key, int x, int y)
{
	
	auto& v = ObjectManager::GetInstance()->Get_Shader();
	if (key == 'r') //�Ѵ� ���� �������� ������
	{
		mode = revolve;
		cb.revolve.y += 10.0f;
		pr.revolve.y += 10.0f;
	}

	if (key == 'R') //�Ѵ� ���� �������� ������
	{
		mode = revolve;
		cb.revolve.y -= 10.0f;
		pr.revolve.y -= 10.0f;
	}

	if (key == 'x')
	{
		mode2 = rotate_x_plus;
	}

	if (key == 'X')
	{
		mode2 = rotate_x_minus;
	}

	if (key == 'y')
	{
		mode2 = rotate_y_plus;
	}

	if (key == 'Y')
	{
		mode2 = rotate_y_minus;
	}


	if (key == '1') //������ ��ü�� mode2 �� ���� ���� ������
	{
	
		if (mode2 == rotate_x_plus)
		{
			mode = Mode::rotate;
			cb.rotate.x += 10.0f;
		}
		if (mode2 == rotate_x_minus)
		{
			mode = Mode::rotate;
			cb.rotate.x -= 10.0f;
		}
		if (mode2 == rotate_y_plus)
		{
			mode = Mode::rotate;
			cb.rotate.y += 10.0f;
		}
		if (mode2 == rotate_y_minus)
		{
			mode = Mode::rotate;
			cb.rotate.y -= 10.0f;
		}

	}
	if (key == '2') //������ ��ü�� ���� �������� ����
	{
		if (mode2 == rotate_x_plus)
		{
			mode = Mode::rotate;
			pr.rotate.x += 10.0f;
		}
		if (mode2 == rotate_x_minus)
		{
			mode = Mode::rotate;
			pr.rotate.x -= 10.0f;
		}
		if (mode2 == rotate_y_plus)
		{
			mode = Mode::rotate;
			pr.rotate.y += 10.0f;
		}
		if (mode2 == rotate_y_minus)
		{
			mode = Mode::rotate;
			pr.rotate.y -= 10.0f;
		}
	}

	if (key == '3') //���� ��ü��� ����
	{

		if (mode2 == rotate_x_plus)
		{
			mode = Mode::rotate;
			cb.rotate.x += 10.0f;
		}
		if (mode2 == rotate_x_minus)
		{
			mode = Mode::rotate;
			cb.rotate.x -= 10.0f;
		}
		if (mode2 == rotate_y_plus)
		{
			mode = Mode::rotate;
			cb.rotate.y += 10.0f;
		}
		if (mode2 == rotate_y_minus)
		{
			mode = Mode::rotate;
			cb.rotate.y -= 10.0f;
		}

		if (mode2 == rotate_x_plus)
		{
			mode = Mode::rotate;
			pr.rotate.x += 10.0f;
		}
		if (mode2 == rotate_x_minus)
		{
			mode = Mode::rotate;
			pr.rotate.x -= 10.0f;
		}
		if (mode2 == rotate_y_plus)
		{
			mode = Mode::rotate;
			pr.rotate.y += 10.0f;
		}
		if (mode2 == rotate_y_minus)
		{
			mode = Mode::rotate;
			pr.rotate.y -= 10.0f;
		}
	}

	if (key == 's')
	{
		mode = revolve;
		cb.revolve.y = 0.0f;
		cb.rotate.x = 10.0f;
		pr.revolve.y = 0.0f;
		pr.rotate.x = 10.0f;

		cb.revolve.y = 0.0f;
		cb.rotate.x = 10.0f;
		cb.rotate.y = 0;
		pr.revolve.y = 0.0f;
		pr.rotate.x = 10.0f;
		pr.rotate.y = 0;

		cube_m_pos={ -0.9f ,0.3f, 0 }; 
		pr_m_pos = { 0.9f,0.3f,0 };
	}


	glutPostRedisplay();
}

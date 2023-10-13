#include "pch.h"
#include "cs16.h"

void cs16::Init()
{

	glutKeyboardFunc(call_back_key);

	cube.Init(cube_m_pos, 0.1f, 0);
	line.Init();
	mode = e_revolve;
	cube_revolve.y = 0.0f;
	cube_rotate.x = 10.0f;

	////////////////////////
	pr.Init(pr_m_pos, 0.1f, 0);

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
	//라인긋기
	//===================================================================================//
	

	if (mode == e_revolve)
	{
		t1 = glm::rotate(glm::mat4(1.0f), glm::radians(cube_revolve.y), glm::vec3(0, 1.0f, 0));
		t2 = glm::rotate(glm::mat4(1.0f), glm::radians(10.0f), glm::vec3(1.0f, 0, 0));
		result = t2 * t1;

		v[0]->SetUniformMat4f("u_model", result);
		temp = result * glm::vec4(cube_m_pos.x, cube_m_pos.y, cube_m_pos.z, 1);
	}

	else if (mode == e_rotate)
	{
		auto goto00 = glm::translate(glm::mat4(1.0f), glm::vec3(-temp.x, -temp.y, -temp.z));
		t3 = glm::rotate(glm::mat4(1.0f), glm::radians(cube_rotate.y), glm::vec3(0, 1.0f, 0));
		auto t4 = glm::rotate(glm::mat4(1.0f), glm::radians(cube_rotate.x), glm::vec3(1.0f, 0, 0));
		auto backtopos = glm::translate(glm::mat4(1.0f), glm::vec3(temp.x, temp.y, temp.z));

		auto result_v = backtopos * t4*t3 * goto00 * result;
		v[0]->SetUniformMat4f("u_model", result_v);
	}



	pr.Render();
	cube.Render();


}

void cs16::call_back_key(unsigned char key, int x, int y)
{
	cs16::GetInstance()->Update_key(key, x, y);
}

void cs16::Update_key(unsigned char key, int x, int y)
{
	
	auto& v = ObjectManager::GetInstance()->Get_Shader();
	if (key == 'r') //공전함
	{
		mode = e_revolve;
		cube_revolve.y += 10.0f;
	}

	if (key == 'R') //공전함
	{
		mode = e_revolve;
		cube_revolve.y -= 10.0f;
	}

	if (key == '1') //자기자리에서 자전함
	{
		mode = e_rotate;
		cube_rotate.y += 10.0f;
	}
	if (key == '2') //자기자리에서 자전함
	{
		mode = e_rotate;
		cube_rotate.y -= 10.0f;
	}

	glutPostRedisplay();
}

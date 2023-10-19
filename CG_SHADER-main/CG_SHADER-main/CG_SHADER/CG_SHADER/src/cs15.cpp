#include "pch.h"
#include "cs15.h"

void cs15::Init()
{

	solid_cube.Init(vec3(0, 0, 0), 0.3f, 0);
	wire_cube.Init(vec3(0, 0, 0), 0.3f, 1);
	solid_pramid.Init(vec3(0, 0, 0), 0.3f, 0);
	wire_pramid.Init(vec3(0, 0, 0), 0.3f, 1);
}

void cs15::Update()
{

	

	if (KeyManager::GetInstance()->GetbuttonDown('w'))
	{
		mode = Mode::Wire;
	}

	else if (KeyManager::GetInstance()->GetbuttonDown('c'))
	{
		what_draw = 0;
	}

	else if (KeyManager::GetInstance()->GetbuttonDown('p'))
	{
		what_draw = 1;
	}

	else if (KeyManager::GetInstance()->GetbuttonDown('W'))
	{
		mode = Mode::Solid;
	}

	else if (KeyManager::GetInstance()->Getbutton('x'))
	{
		degree_x += 1.0f;
	}

	else if (KeyManager::GetInstance()->Getbutton('X'))
	{
		degree_x -= 1.0f;
	}

	else if (KeyManager::GetInstance()->Getbutton('y'))
	{
		degree_y += 1.0f;
	}

	else if (KeyManager::GetInstance()->Getbutton('Y'))
	{
		degree_y -= 1.0f;
	}

	else if (KeyManager::GetInstance()->GetPress('i'))
	{
		auto t =TimeManager::GetInstance()->GetDeltaTime();
		dy += 1.0f* t;
	}
	else if (KeyManager::GetInstance()->GetbuttonDown('k'))
	{
		dy -=0.01f;
	}
	else if (KeyManager::GetInstance()->GetbuttonDown('j'))
	{
		dx -= 0.01f;
	}
	else if (KeyManager::GetInstance()->GetbuttonDown('l'))
	{
		dx += 0.01f;
	}

	else if (KeyManager::GetInstance()->GetbuttonDown('s'))
	{
	
		dx = 0;
		dy = 0;
		degree_x = 20.f;
		degree_y = 20.f;
	}

	else if (KeyManager::GetInstance()->GetbuttonDown('h'))
	{
		cull_face = !cull_face;
		cout << cull_face << endl;
		if (cull_face)
		{
			glEnable(GL_CULL_FACE);
		}
		else
		{
			glDisable(GL_CULL_FACE);
		}
	
	}
}

void cs15::Render()
{

	auto &v =ObjectManager::GetInstance()->Get_Shader();

	auto simple = glm::mat4(1.0f);
	v[0]->SetUniformMat4f("u_model", simple);

	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f, 0, 0); // 첫 번째 점의 좌표
	glVertex3f(1.0f, 0, 0);   // 두 번째 점의 좌표

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0, 1.0f, 0); // 첫 번째 점의 좌표
	glVertex3f(0, -1.0f, 0);   // 두 번째 점의 좌표

	glEnd();


	auto t = glm::rotate(glm::mat4(1.0f), glm::radians(degree_x), glm::vec3(1.0f, 0, 0));
	auto t2 = glm::rotate(glm::mat4(1.0f), glm::radians(degree_y), glm::vec3(0, 1.0f, 0));

	auto transpos = glm::translate(glm::mat4(1.0f), glm::vec3(dx, dy, 0));
	auto t3 = transpos* t * t2;

	v[0]->SetUniformMat4f("u_model", t3);


	if (what_draw == 0)
	{

		if (mode == Mode::Wire)
		{
			wire_cube.Render();
		}

		else if (mode == Mode::Solid)
		{
			solid_cube.Render();
		}
	}

	else if (what_draw == 1)
	{

		if (mode == Mode::Wire)
		{
			wire_pramid.Render();
		}

		else if (mode == Mode::Solid)
		{
			solid_pramid.Render();
		}
	}

}

#include "pch.h"
#include "ex20.h"
#include "viewport21_2.h"
#include "viewport21_3.h"

ex20 p;
viewport21_2 p2;
viewport21_3 p3;

void draw()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glViewport(0, 400, 400, 400);
	p.Render();


	glViewport(0, 0, 400, 400);
	p2.Render();


	glViewport(400, 0, 400, 400);
	p3.Render();

	glEnable(GL_DEPTH_TEST);
	glutSwapBuffers();

};


int main(int argc, char** argv)
{
	Core::GetInstance()->Init(argc, argv, 800, 800);
	Core::GetInstance()->Render(draw);
	KeyManager::GetInstance()->Init();
	TimeManager::GetInstance()->Init();
	MouseManager::GetInstance()->Init();

	Shader shader("res/shader/mvp.vs", "res/shader/mvp.fs");
	shader.Bind();

	auto& v = ObjectManager::GetInstance()->Get_Shader();
	v.push_back(&shader);

	p.Init();
	p2.Init();
	p3.Init();

	while (1)
	{
		KeyManager::GetInstance()->Update();
		TimeManager::GetInstance()->Update();
		p.Update();
		p2.Update();
		p3.Update();
		glutPostRedisplay();
		glutMainLoopEvent();

	}

}
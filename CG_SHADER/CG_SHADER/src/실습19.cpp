#include "pch.h"
#include "ex19.h"

ex19 p;

void draw()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	p.Render();

	glutSwapBuffers();

};


int main(int argc, char** argv)
{
	Core::GetInstance()->Init(argc, argv, 800, 800);
	Core::GetInstance()->Render(draw);
	KeyManager::GetInstance()->Init();
	TimeManager::GetInstance()->Init();
	MouseManager::GetInstance()->Init();

	Shader shader("res/shader/shader_19.vs", "res/shader/shader_19.fs");
	shader.Bind();
	
	auto& v = ObjectManager::GetInstance()->Get_Shader();
	v.push_back(&shader);

	p.Init();

	while (1)
	{
		KeyManager::GetInstance()->Update();
		TimeManager::GetInstance()->Update();

		p.Update();
	
		glutPostRedisplay();
		glutMainLoopEvent();
	}

}




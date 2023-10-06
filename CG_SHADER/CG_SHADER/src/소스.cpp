#include "pch.h"
#include "Object.h"

Object test;

void DrawScene()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	test.Render();
	glutSwapBuffers();
}


int main(int argc ,char ** argv)
{
	Core::GetInstance()->Init(argc, argv, 800, 800);
	Core::GetInstance()->Render(DrawScene);
	Shader* shader = new Shader("res/shader/Shader1.vs", "res/shader/Shader1.fs");
	shader->Bind();
	test.Init();

	while (1)
	{
		KeyManager::GetInstance()->Update();
		test.Update();
		glutPostRedisplay();
		glutMainLoopEvent();
	}
}



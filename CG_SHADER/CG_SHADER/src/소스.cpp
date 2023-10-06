#include "pch.h"
#include "Object.h"
#include "MouseManager.h"
Object rect;

void DrawScene()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	rect.Render();
	glutSwapBuffers();
}


int main(int argc ,char ** argv)
{
	Core::GetInstance()->Init(argc, argv, 800, 600);
	Core::GetInstance()->Render(DrawScene);

	KeyManager::GetInstance()->Update();
	MouseManager::GetInstance()->Update();


	Shader* shader = new Shader("res/shader/Shader1.vs", "res/shader/Shader1.fs");
	shader->Bind();
	rect.Init();

	while (1)
	{
	
		rect.Update();
		glutPostRedisplay();
		glutMainLoopEvent();
	}
}



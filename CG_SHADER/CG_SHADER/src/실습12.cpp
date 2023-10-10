#include "pch.h"
#include "p12.h"

p12 p;

void DrawScene()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	p.Render();
	glutSwapBuffers();
}


int main(int argc, char** argv)
{

	Core::GetInstance()->Init(argc, argv, 800, 600);
	Core::GetInstance()->Render(DrawScene);

	KeyManager::GetInstance()->Update();
	MouseManager::GetInstance()->Update();

	unique_ptr<Shader> shader = make_unique<Shader>("res/shader/Shader1.vs", "res/shader/Shader1.fs");

<<<<<<< HEAD
	{
		p12 p;

	}
=======
>>>>>>> 1c0dca82b24112ca3d9f4281b601d6d242cf4be7

	shader->Bind();
	p.Init();
	srand(time(NULL));

	while (1)
	{
		p.Update();
		glutPostRedisplay();
		glutMainLoopEvent();
	}
}


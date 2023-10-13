#include "pch.h"
#include "cs15.h"
#include "Pyramid.h"
vector<Shader> v;

cs15 p;

float dx = 0;
void DrawScene()
{

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	p.Render();

	glutSwapBuffers();
}



int main(int argc, char** argv)
{
	Core::GetInstance()->Init(argc, argv, 800, 800);
	Core::GetInstance()->Render(DrawScene);

	KeyManager::GetInstance()->Update();

	Shader shader("res/shader/Shader2.vs", "res/shader/Shader2.fs");
	shader.Bind();

	auto &shader_vec =ObjectManager::GetInstance()->Get_Shader();
	shader_vec.push_back(&shader);
	

	p.Init();

	glEnable(GL_DEPTH_TEST);

	while (1)
	{
		p.Update();
		glutPostRedisplay();
		glutMainLoopEvent();
	}
}

#include "pch.h"
#include "p13.h"
p13 p;
vector<Shader> v;
void DrawScene()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	
	v[0].Bind();
	
	glBegin(GL_LINES);
	glVertex2f(-1.0f, 0); // ù ��° ���� ��ǥ
	glVertex2f(1.0f, 0);   // �� ��° ���� ��ǥ
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(0, 1); // ù ��° ���� ��ǥ
	glVertex2f(0, -1);   // �� ��° ���� ��ǥ
	glEnd();


	v[0].Bind();
	
	p.Render();
	glutSwapBuffers();
}


int main(int argc ,char ** argv)
{
	Core::GetInstance()->Init(argc, argv, 800, 600);
	Core::GetInstance()->Render(DrawScene);

	KeyManager::GetInstance()->Update();
	MouseManager::GetInstance()->Update();
	Shader shader("res/shader/Shader1.vs", "res/shader/Shader1.fs");
	shader.Bind();
	v.push_back(shader);
	p.Init();

	while (1)
	{
	
		p.Update();
		glutPostRedisplay();
		glutMainLoopEvent();
	}
}



#include "pch.h"
#include "Cube.h"
Cube cube;

void draw()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	cube.Render();
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

	Shader shader("res/shader/shader1.vs", "res/shader/shader1.fs");
	shader.Bind();
	cube.Init(vec3(0,0,0),0.1f,0);

	shader.SetUniform4f("test", 0.5f, 0.5f, 0, 0);


	auto& v = ObjectManager::GetInstance()->Get_Shader();
	v.push_back(&shader);



	while (1)
	{
		KeyManager::GetInstance()->Update();
		TimeManager::GetInstance()->Update();
		glutPostRedisplay();
		glutMainLoopEvent();

	}

}
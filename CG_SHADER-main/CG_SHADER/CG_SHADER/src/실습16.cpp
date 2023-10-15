#include "pch.h"
#include "cs16.h"

vector<Shader> v;


void DrawScene()
{

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	cs16::GetInstance()->Render();

	glutSwapBuffers();
}

int main(int argc, char** argv)
{
	Core::GetInstance()->Init(argc, argv, 800, 800);
	Core::GetInstance()->Render(DrawScene);

	Shader shader("res/shader/Shader2.vs", "res/shader/Shader2.fs");
	shader.Bind();

	v.push_back(shader);

	auto& shader_vec = ObjectManager::GetInstance()->Get_Shader();
	shader_vec.push_back(&shader);


	cs16::GetInstance()->Init();

	glEnable(GL_DEPTH_TEST);

	while (1)
	{
		glutMainLoopEvent();
	}
}

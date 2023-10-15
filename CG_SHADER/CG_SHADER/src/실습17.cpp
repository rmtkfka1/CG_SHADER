#include "pch.h"
#include "cs17.h"


void draw()
{

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	cs17::GetInstance()->Render();
	
	glutSwapBuffers();
}


int main(int argc, char** argv)
{

	Core::GetInstance()->Init(argc, argv, 700, 700);
	Core::GetInstance()->Render(draw);


	glEnable(GL_DEPTH_TEST);
	cs17::GetInstance()->Init();
	glutKeyboardFunc(cs17::GetInstance()->key_call_back);

	Shader shader("res/shader/Shader2.vs", "res/shader/Shader2.fs");
	shader.Bind();

	auto& shader_vec = ObjectManager::GetInstance()->Get_Shader();
	shader_vec.push_back(&shader);


	while (1)
	{

		cs17::GetInstance()->Update();
		glutMainLoopEvent();
		glutPostRedisplay();
	}

}
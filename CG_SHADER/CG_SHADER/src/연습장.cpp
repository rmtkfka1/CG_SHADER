#include "pch.h"
#include "Cube.h"
#include "p14.h"
#include "p14_4.h"
vector<Shader> v;
//p14 p;
p14_4 p;
float dx = 0;
void DrawScene()
{

	glClearColor(0.1f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	
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

	v.push_back(shader);
	
	p.Init();

	auto t=glm::rotate(glm::mat4(1.0f), glm::radians(20.0f), glm::vec3(1.0f, 0, 0));
	auto t2 = glm::rotate(glm::mat4(1.0f), glm::radians(20.0f), glm::vec3(0, 1.0f, 0));
	auto t3 = t * t2;
	shader.SetUniformMat4f("u_model", t3);
	glEnable(GL_DEPTH_TEST);


	while (1)
	{
		p.Update();
		glutPostRedisplay();
		glutMainLoopEvent();
	}
}

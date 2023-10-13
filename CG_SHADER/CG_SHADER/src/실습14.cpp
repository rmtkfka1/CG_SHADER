#include "pch.h"
#include "Cube.h"
#include "p14.h"
#include "p14_4.h"
#include "p14_world.h"
vector<Shader> v;
p14_world p;

void DrawScene()
{

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	auto simple = glm::mat4(1.0f);
	v[0].SetUniformMat4f("u_model", simple);

	glBegin(GL_LINES);
	glVertex3f(-1.0f, 0, 0); // 첫 번째 점의 좌표
	glVertex3f(1.0f, 0, 0);   // 두 번째 점의 좌표
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(0, 1, 0); // 첫 번째 점의 좌표
	glVertex3f(0, -1, 0);   // 두 번째 점의 좌표
	glEnd();


	glBegin(GL_LINES);
	glVertex3f(0, 0, -1); // 첫 번째 점의 좌표
	glVertex3f(0, 0, 1);   // 두 번째 점의 좌표
	glEnd();


	auto t = glm::rotate(glm::mat4(1.0f), glm::radians(20.0f), glm::vec3(1.0f, 0, 0));
	auto t2 = glm::rotate(glm::mat4(1.0f), glm::radians(20.0f), glm::vec3(0, 1.0f, 0));
	auto t3 = t * t2;

	v[0].SetUniformMat4f("u_model", t3);

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
	
	p.Init(vec3(0, 0, 0), 0.3f);

	auto &temp =ObjectManager::GetInstance()->Get_P14_world();
	temp.push_back(&p);


	glEnable(GL_DEPTH_TEST);

	while (1)
	{
		p.Update();
		glutPostRedisplay();
		glutMainLoopEvent();
	}
}

#include "pch.h"
#include "Spiral.h"
vector<Shader> v;

Spiral s;
void draw()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	s.Render();
	glutSwapBuffers();
};


int main(int argc, char** argv)
{
	Core::GetInstance()->Init(argc, argv, 800, 800);
	Core::GetInstance()->Render(draw);
	KeyManager::GetInstance()->Init();
	TimeManager::GetInstance()->Init();
	MouseManager::GetInstance()->Init();


	Shader shader("res/shader/Shader2.vs", "res/shader/Shader2.fs");
	shader.Bind();
	s.Init();
	v.push_back(shader);

	glm::mat4 result = glm::mat4(1.0f);
	v[0].SetUniformMat4f("u_model", result);  

	while (1)
	{
		KeyManager::GetInstance()->Update();
		TimeManager::GetInstance()->Update();

		glutMainLoopEvent();
	}

}




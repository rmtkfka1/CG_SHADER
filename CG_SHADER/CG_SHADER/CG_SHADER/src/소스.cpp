#include "pch.h"
#include "cs22.h"

Model teapot;
Shader* shader;
void draw()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	teapot.RenderModel(*shader);
	glutSwapBuffers();

};

int main(int argc, char** argv)
{
	Core::GetInstance()->Init(argc, argv, 800, 800);
	Core::GetInstance()->Render(draw);

	KeyManager::GetInstance()->Init();
	TimeManager::GetInstance()->Init();
	MouseManager::GetInstance()->Init();


	shader = new Shader("res/shader/mvp_new.vs", "res/shader/mvp_new.fs");
	shader->Bind();

	teapot.LoadModel("res/models/teapot.obj"); //obj�� ���� 3D �� ������ �Է� ����

	shader->SetUniformMat4f("u_model", matrix::GetInstance()->GetSimple());
	shader->SetUniformMat4f("u_view", matrix::GetInstance()->GetCamera(glm::vec3(0, 0, 100.0f + 10.0f), glm::vec3(0, 0, 0)));
	shader->SetUniformMat4f("u_proj", matrix::GetInstance()->GetProjection());


 	Texture texture{ "res/textures/1.jpg" };
	texture.Bind(1); //0�� ���Կ� ���ε�
	shader->SetUniform1i("test", 1); //0�� ������ �ؽ�ó�� ����� ���̶�� ���� ���̴��� ���


	while (1)
	{
		KeyManager::GetInstance()->Update();
		TimeManager::GetInstance()->Update();
	
		glutPostRedisplay();
		glutMainLoopEvent();
	}

}


#include "pch.h"
#include "cs22.h"
#include "Camera.h"

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

	teapot.LoadModel("res/models/teapot.obj"); 

	shader->SetUniformMat4f("u_model", matrix::GetInstance()->GetSimple());
	shader->SetUniformMat4f("u_view", matrix::GetInstance()->GetCamera(glm::vec3(100.0f, 0, 0), glm::vec3(0, 0, 0)));
	shader->SetUniformMat4f("u_proj", matrix::GetInstance()->GetProjection());

	Camera camera{ glm::vec3{0.0f,0.0f,15.0f}, glm::vec3{0.0f,1.0f,0.0f}, -90.0f, 0.0f, 5.0f, 0.5f };

 	Texture texture{ "res/textures/zz.jpg" };
	texture.Bind(1); //0번 슬롯에 바인딩
	shader->SetUniform1i("test", 1); //0번 슬롯의 텍스처를 사용할 것이라는 것을 셰이더에 명시

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glutSetCursor(GLUT_CURSOR_NONE);


	while (1)
	{
		KeyManager::GetInstance()->Update();
		TimeManager::GetInstance()->Update();
		camera.KeyControl();
		camera.MouseControl(MouseManager::GetInstance()->GetXChange(), MouseManager::GetInstance()->GetYChange());
		shader->SetUniformMat4f("u_view", camera.calculateViewMatrix()); //카메라 변화에 따라 새로 계산된 view 행렬 셰이더에 전달
		glutPostRedisplay();
		glutMainLoopEvent();
	}

}


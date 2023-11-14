#include "pch.h"
#include "cs22.h"
cs22 p;

Model teapot;

void draw()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	auto v = ObjectManager::GetInstance()->Get_Shader();
	teapot.RenderModel(*v[0]);
	p.Render();
	
	glutSwapBuffers();

};



int main(int argc, char** argv)
{
	Core::GetInstance()->Init(argc, argv, 800, 800);
	Core::GetInstance()->Render(draw);


	KeyManager::GetInstance()->Init();
	TimeManager::GetInstance()->Init();
	MouseManager::GetInstance()->Init();

	Shader shader("res/shader/mvp_new.vs", "res/shader/mvp_new.fs");
	shader.Bind();

	auto& v = ObjectManager::GetInstance()->Get_Shader();
	v.push_back(&shader);


	teapot.LoadModel("res/models/teapot.obj"); //obj와 같은 3D 모델 파일을 입력 가능

	Texture texture{ "res/textures/1.jpg" };
	texture.Bind(0); //0번 슬롯에 바인딩
	shader.SetUniform1i("u_Texture", 0); //0번 슬롯의 텍스처를 사용할 것이라는 것을 셰이더에 명시

	p.Init();
	glEnable(GL_DEPTH_TEST);

	while (1)
	{
		KeyManager::GetInstance()->Update();
		TimeManager::GetInstance()->Update();
		p.Update();
		glutPostRedisplay();
		glutMainLoopEvent();
	}

}




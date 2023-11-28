#include "pch.h"
#include "Camera.h"
#include "Light.h"
#include "cs28.h"

cs28 p;

void draw()
{
	glClearColor(0, 0, 0, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	p.render();

	glutSwapBuffers();

};

int main(int argc, char** argv)
{



	Core::GetInstance()->Init(argc, argv, 800, 800);
	Core::GetInstance()->Render(draw);


	KeyManager::GetInstance()->Init();
	TimeManager::GetInstance()->Init();
	MouseManager::GetInstance()->Init();


	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	p.init();

	glutSetCursor(GLUT_CURSOR_NONE); // 마우스 커서 숨기기
	while (1)
	{
		KeyManager::GetInstance()->Update();
		TimeManager::GetInstance()->Update();


		p.update();



		glutPostRedisplay();
		glutMainLoopEvent();
	}

}


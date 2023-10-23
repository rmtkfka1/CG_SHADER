#include "pch.h"
#include "ex20.h"

ex20 p;

void draw()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	p.Render();
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

	Shader shader("res/shader/mvp.vs", "res/shader/mvp.fs");
	shader.Bind();

	auto& v = ObjectManager::GetInstance()->Get_Shader();
	v.push_back(&shader);

	p.Init();

	cout << "V / B: 크레인의 아래 몸체가 x축 방향으로 양 / 음 방향으로 이동한다.다시 누르면 멈춘다.		" << endl;
	cout << "M / N : 크레인의 중앙 몸체가 y축에 대하여 양 / 음 방향으로 회전한다.다시 누르면 멈춘다.	" << endl;
	cout << "1 / 2 : 포신이 y축에 대하여 양 / 음 방향으로 회전하는데, 두 포신이 서로 반대방향으로 회전한다.다시 누르면 멈춘다." << endl;
	cout << "E / R : 2개 포신이 조금씩 이동해서 한 개가 된다 / 다시 제자리로 이동해서 2개가 된다." << endl;
	cout << "이때 포신이 회전되어 있다면, 원래 자리까지 회전된 후 이동한다" << endl;
	cout << "t / T : 크레인의 맨 위 2개의 팔이 z축에 대하여 양 / 음 방향으로 서로 반대방향으로 회전한다.다시 누르면 멈춘다.	" << endl;																	
	cout << "카메라 변환								" << endl;
	cout << "W / S : 카메라가 z축 양 / 음 방향으로 이동									" << endl;
	cout << "A / D : 카메라가 x축 양 / 음 방향으로 이동							" << endl;
	cout << "X     :  카메라 기준 y축에 대하여 회전								" << endl;
	cout << "F/G   : 화면의 중심의 y축에 대하여 카메라가 회전(중점에 대하여 공전)				" << endl;
	cout << "Z     : 화면의 중심의 축에 대하여 카메라가 회전하는 애니메이션을 진행한다 / 멈춘다.	" << endl;
	cout << "3     : 모든 움직임 멈추기				" << endl;
	cout << "4     : 모든 움직임이 초기화된다.		" << endl;
	cout << "Q     : 프로그램 종료하기" << endl;

	while (1)
	{
		KeyManager::GetInstance()->Update();
		TimeManager::GetInstance()->Update();
		p.Update();
		glutPostRedisplay();
		glutMainLoopEvent();

	}

}
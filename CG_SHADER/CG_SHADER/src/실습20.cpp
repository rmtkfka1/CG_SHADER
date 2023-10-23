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

	cout << "V / B: ũ������ �Ʒ� ��ü�� x�� �������� �� / �� �������� �̵��Ѵ�.�ٽ� ������ �����.		" << endl;
	cout << "M / N : ũ������ �߾� ��ü�� y�࿡ ���Ͽ� �� / �� �������� ȸ���Ѵ�.�ٽ� ������ �����.	" << endl;
	cout << "1 / 2 : ������ y�࿡ ���Ͽ� �� / �� �������� ȸ���ϴµ�, �� ������ ���� �ݴ�������� ȸ���Ѵ�.�ٽ� ������ �����." << endl;
	cout << "E / R : 2�� ������ ���ݾ� �̵��ؼ� �� ���� �ȴ� / �ٽ� ���ڸ��� �̵��ؼ� 2���� �ȴ�." << endl;
	cout << "�̶� ������ ȸ���Ǿ� �ִٸ�, ���� �ڸ����� ȸ���� �� �̵��Ѵ�" << endl;
	cout << "t / T : ũ������ �� �� 2���� ���� z�࿡ ���Ͽ� �� / �� �������� ���� �ݴ�������� ȸ���Ѵ�.�ٽ� ������ �����.	" << endl;																	
	cout << "ī�޶� ��ȯ								" << endl;
	cout << "W / S : ī�޶� z�� �� / �� �������� �̵�									" << endl;
	cout << "A / D : ī�޶� x�� �� / �� �������� �̵�							" << endl;
	cout << "X     :  ī�޶� ���� y�࿡ ���Ͽ� ȸ��								" << endl;
	cout << "F/G   : ȭ���� �߽��� y�࿡ ���Ͽ� ī�޶� ȸ��(������ ���Ͽ� ����)				" << endl;
	cout << "Z     : ȭ���� �߽��� �࿡ ���Ͽ� ī�޶� ȸ���ϴ� �ִϸ��̼��� �����Ѵ� / �����.	" << endl;
	cout << "3     : ��� ������ ���߱�				" << endl;
	cout << "4     : ��� �������� �ʱ�ȭ�ȴ�.		" << endl;
	cout << "Q     : ���α׷� �����ϱ�" << endl;

	while (1)
	{
		KeyManager::GetInstance()->Update();
		TimeManager::GetInstance()->Update();
		p.Update();
		glutPostRedisplay();
		glutMainLoopEvent();

	}

}
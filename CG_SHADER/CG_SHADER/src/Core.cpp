#include "pch.h"
#include "Core.h"


GLvoid Reshape(int w, int h)
{
	glViewport(0, 0, w, h);
}

Core::Core()
{
	//init ���� ó����
}

Core::~Core()
{
}

void Core::Init(int argc, char** argv, int x, int y) //
{
	::glutInit(&argc, argv); // glut �ʱ�ȭ   GLUT�� openGL ȯ�� �ʱ�ȭ
	::glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // �÷���, ������ ���� �� �ʱ��� ��� ��带 �����Ѵ�.
	::glutInitWindowPosition(0, 0); // ������ ���� ���� (x,y)
	::glutInitWindowSize(x, y);  // ������ ũ�� ���� 
	::glutCreateWindow("my window");

	//--- GLEW �ʱ�ȭ�ϱ�
	::glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) // glew �ʱ�ȭ
	{
		std::cerr << "glew �ʱ�ȭ ����" << std::endl;
		exit(EXIT_FAILURE);
	}
	else
		std::cout << "glew �ʱ�ȭ ���� " << std::endl;



}

void Core::Render(void (*funcptr)(void))
{
	::glutDisplayFunc(funcptr);
	::glutReshapeFunc(Reshape);

}

void Core::Keyboard(void (*funcptr)(unsigned char, int, int))
{
	glutKeyboardFunc(funcptr);
}

void Core::mousein(void(*funcptr)(int button, int state, int x, int y))
{
	glutMouseFunc(funcptr);
}

void Core::mouse_move(void(*funcptr)(int x, int y))
{
	glutMotionFunc(funcptr);
}



#include "pch.h"
#include "MouseManager.h"
#include <chrono>



void MouseManager::Init()
{
	glutMouseFunc(MouseCallBack);
	glutMotionFunc(MousemoveCallBack);
	glutPassiveMotionFunc(MousemoveCallBack2);

}

void MouseManager::MouseCallBack(int button, int state, int x, int y)
{
	vec2 pos = Core::GetInstance()->convert(x, y, 800, 600);

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		MouseManager::GetInstance()->m_click = true;
		MouseManager::GetInstance()->m_pos = pos;
		MouseManager::GetInstance()->m_beforePos = pos;
	}

	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		MouseManager::GetInstance()->m_click = false;
		MouseManager::GetInstance()->m_diff.x = 0;
		MouseManager::GetInstance()->m_diff.y = 0;


	}
}

void MouseManager::MousemoveCallBack(int x, int y)
{
	vec2 pos = Core::GetInstance()->convert(x, y, 800, 600);

	MouseManager::GetInstance()->m_pos = pos;

	MouseManager::GetInstance()->m_diff = pos - MouseManager::GetInstance()->m_beforePos;
	MouseManager::GetInstance()->m_beforePos = pos;
    


}

void MouseManager::MousemoveCallBack2(int x, int y)
{




	if (MouseManager::GetInstance()->m_MouseFirstMoved) //���콺�� ó�� �����̱� �������� ���� ��ǥ�� �����ص�
	{
		MouseManager::GetInstance()->m_LastX = x;
		MouseManager::GetInstance()->m_LastY = y;
		MouseManager::GetInstance()->m_MouseFirstMoved = false;
	}

	else //��� �����δٸ�
	{
		//���� ������ ��ġ���� ���� ������ ��ġ�� �� ���� Change�� ����
		//y��ǥ�� �������� (�Ǵ� ���⼭ ������ �ʰ� ���� �������� ó���ص� ��� ����)
		MouseManager::GetInstance()->m_XChange = x - MouseManager::GetInstance()->m_LastX;
		MouseManager::GetInstance()->m_YChange = MouseManager::GetInstance()->m_LastY - y;

		//��ȭ���� ��������Ƿ�, �ֽ� ��ġ�� last�� ����
		MouseManager::GetInstance()->m_LastX = x;
		MouseManager::GetInstance()->m_LastY = y;

		/*std::cout << "XChange : " << windowObject->m_XChange <<
			" YChange : " << windowObject->m_YChange << std::endl;*/
	}

}

float MouseManager::GetXChange()
{
	float theChange = m_XChange;
	m_XChange = 0.0f; //�� �����Ӹ��� ��ȭ���� 0���� ���� ����
	return theChange;
}

float MouseManager::GetYChange()
{
	float theChange = m_YChange;
	m_YChange = 0.0f; //�� �����Ӹ��� ��ȭ���� 0���� ���� ����
	return theChange;
}






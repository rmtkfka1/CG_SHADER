#include "pch.h"
#include "MouseManager.h"
#include <chrono>



void MouseManager::Init()
{
	glutMouseFunc(MouseCallBack);
	glutMotionFunc(MousemoveCallBack);

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






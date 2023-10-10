#include "pch.h"
#include "MouseManager.h"

Pos MouseManager::m_pos = { 0,0 };
bool MouseManager::m_click=false;
void MouseManager::Update()
{
	glutMouseFunc(MouseCallBack);
	glutMotionFunc(MousemoveCallBack);
}

void MouseManager::MouseCallBack(int button, int state, int x, int y)
{
	Pos pos = Core::GetInstance()->convert(x, y, 800, 600);

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		m_click = true;
		m_pos = pos;
	}

	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		m_click = false;
	}
}

void MouseManager::MousemoveCallBack(int x, int y)
{
	Pos pos = Core::GetInstance()->convert(x, y, 800, 600);

	
	m_pos = pos;
	
}






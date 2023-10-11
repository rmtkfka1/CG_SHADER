#include "pch.h"
#include "MouseManager.h"
#include <chrono>


vec2 MouseManager::m_pos = { 0,0 };
bool MouseManager::m_click=false;
vec2 MouseManager::m_diff;
vec2 MouseManager::m_beforePos;

std::chrono::high_resolution_clock::time_point lastMouseEventTime;
void MouseManager::Update()
{
	glutMouseFunc(MouseCallBack);
	glutMotionFunc(MousemoveCallBack);

}

void MouseManager::MouseCallBack(int button, int state, int x, int y)
{
	vec2 pos = Core::GetInstance()->convert(x, y, 800, 600);

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		m_click = true;
		m_pos = pos;
		m_beforePos = pos;
	}

	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		m_click = false;
		m_diff.x = 0;
		m_diff.y = 0;
	}
}

void MouseManager::MousemoveCallBack(int x, int y)
{
	vec2 pos = Core::GetInstance()->convert(x, y, 800, 600);


	
	m_pos = pos;

     m_diff = pos - m_beforePos;
     m_beforePos = pos;
    

	

}






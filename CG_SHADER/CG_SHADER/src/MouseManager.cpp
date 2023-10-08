#include "pch.h"
#include "MouseManager.h"
#include "ObjectManager.h"
#include "p13.h"
Pos MouseManager::m_pos = { 0,0 };
bool MouseManager::m_click=false;
Pos MouseManager::m_diff;
Pos MouseManager::beforePos;
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
		beforePos = pos;
		m_diff.x = 0;
		m_diff.y = 0;
	}

	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		m_click = false;
		m_diff.x = 0;
		m_diff.y = 0;
		beforePos.x = 0;
		beforePos.y = 0;
	}


}

void MouseManager::MousemoveCallBack(int x, int y)
{
	
	Pos pos = Core::GetInstance()->convert(x, y, 800, 600);

	if (m_click)
	{
		m_pos = pos;
	}

	if (m_click)
	{
		m_diff.x = pos.x - beforePos.x;
		m_diff.y = pos.y - beforePos.y;



		auto &t =ObjectManger::GetInstance()->GetTri();
		t[0]->diff = Pos(m_diff.x, m_diff.y);





		beforePos = pos;
	}




}






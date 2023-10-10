#include "pch.h"
#include "MouseManager.h"
#include <chrono>


Pos MouseManager::m_pos = { 0,0 };
bool MouseManager::m_click=false;
Pos MouseManager::m_diff;
Pos MouseManager::m_beforePos;

std::chrono::high_resolution_clock::time_point lastMouseEventTime;
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
	Pos pos = Core::GetInstance()->convert(x, y, 800, 600);

<<<<<<< HEAD
	
	m_pos = pos;
	
=======
	if (m_click)
	{
		m_pos = pos;
	}

    if (m_click)
    {
        m_pos = pos;
        m_diff = pos - m_beforePos;
        m_beforePos = pos;
    }

	auto currentTime = std::chrono::high_resolution_clock::now();
	auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastMouseEventTime).count();

	// 일정 시간 동안 마우스 이벤트가 없을 경우 처리
	if (elapsedTime > 1000) {
		std::cout << "마우스 이벤트가 1초 동안 없었습니다." << std::endl;
	}
>>>>>>> 1c0dca82b24112ca3d9f4281b601d6d242cf4be7
}






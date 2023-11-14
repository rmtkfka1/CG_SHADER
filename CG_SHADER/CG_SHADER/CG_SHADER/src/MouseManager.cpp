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




	if (MouseManager::GetInstance()->m_MouseFirstMoved) //마우스가 처음 움직이기 시작했을 때의 좌표를 저장해둠
	{
		MouseManager::GetInstance()->m_LastX = x;
		MouseManager::GetInstance()->m_LastY = y;
		MouseManager::GetInstance()->m_MouseFirstMoved = false;
	}

	else //계속 움직인다면
	{
		//이전 프레임 위치에서 현재 프레임 위치를 뺀 값을 Change에 저장
		//y좌표는 뒤집어줌 (또는 여기서 뒤집지 않고 구현 로직에서 처리해도 상관 없음)
		MouseManager::GetInstance()->m_XChange = x - MouseManager::GetInstance()->m_LastX;
		MouseManager::GetInstance()->m_YChange = MouseManager::GetInstance()->m_LastY - y;

		//변화량을 계산했으므로, 최신 위치를 last로 저장
		MouseManager::GetInstance()->m_LastX = x;
		MouseManager::GetInstance()->m_LastY = y;

		/*std::cout << "XChange : " << windowObject->m_XChange <<
			" YChange : " << windowObject->m_YChange << std::endl;*/
	}

}

float MouseManager::GetXChange()
{
	float theChange = m_XChange;
	m_XChange = 0.0f; //매 프레임마다 변화량은 0으로 새로 설정
	return theChange;
}

float MouseManager::GetYChange()
{
	float theChange = m_YChange;
	m_YChange = 0.0f; //매 프레임마다 변화량은 0으로 새로 설정
	return theChange;
}






#include "pch.h"
#include "MouseManager.h"
#include <chrono>
#include "Camera2.h"


void MouseManager::Init()
{
	glutMouseFunc(MouseCallBack);
	glutMotionFunc(MousemoveCallBack);
	glutPassiveMotionFunc(MousemoveCallBack2);
	
}

void MouseManager::MouseCallBack(int button, int state, int x, int y)
{


	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{


	}

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{


	}

	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
	
		Camera2::GetInstance()->m_cameraControl = false;

	}

	if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP)
	{
		Camera2::GetInstance()->m_prevMousePos = glm::vec2(x, y);
		Camera2::GetInstance()->m_cameraControl = true;

	}
}

void MouseManager::MousemoveCallBack(int x, int y)
{



}

void MouseManager::MousemoveCallBack2(int x, int y)
{


	MouseManager::GetInstance()->m_pos.x = x;
	MouseManager::GetInstance()->m_pos.y = y;

	

	

	
	

}





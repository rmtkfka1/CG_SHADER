#include "pch.h"
#include "KeyManager.h"




void KeyManager::Update()
{
    glutKeyboardFunc(KeyboardCallback);
    glutKeyboardUpFunc(KeyboardUpCallback);
}

KeyManager::KeyManager()
{
	for (int i = 0; i < 256; ++i)
	{
		_states[i] = KeyState::NONE;
	}

	for (int i = 0; i < 1024; ++i)
	{
		_key[i] = false;
	}


}



void KeyManager::KeyboardCallback(unsigned char key, int x, int y)
{
	

	if (KeyManager::GetInstance()->_states[key] == KeyState::PRESS || KeyManager::GetInstance()->_states[key] == KeyState::DOWN)
		KeyManager::GetInstance()->_states[key] = KeyState::PRESS;
	else
		KeyManager::GetInstance()->_states[key] = KeyState::DOWN;


	KeyManager::GetInstance()->_key[key] = true;

	glutPostRedisplay();

}

void KeyManager::KeyboardUpCallback(unsigned char key, int x, int y)
{
	
	if (KeyManager::GetInstance()->_states[key] == KeyState::PRESS || KeyManager::GetInstance()->_states[key] == KeyState::DOWN)
		KeyManager::GetInstance()->_states[key] = KeyState::UP;
	else
		KeyManager::GetInstance()->_states[key] = KeyState::UP;

	KeyManager::GetInstance()->_key[key] = false;
	glutPostRedisplay();
    
}

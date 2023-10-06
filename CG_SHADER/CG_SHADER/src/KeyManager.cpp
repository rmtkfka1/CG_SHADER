#include "pch.h"
#include "KeyManager.h"


KeyState KeyManager::_states[256];



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
	
}

void KeyManager::KeyboardCallback(unsigned char key, int x, int y)
{
	

	if (_states[key] == KeyState::PRESS || _states[key] == KeyState::DOWN)
		_states[key] = KeyState::PRESS;
	else
		_states[key] = KeyState::DOWN;


}

void KeyManager::KeyboardUpCallback(unsigned char key, int x, int y)
{
	
	if (_states[key] == KeyState::PRESS || _states[key] == KeyState::DOWN)
		_states[key] = KeyState::UP;
	else
		_states[key] = KeyState::UP;

	
    
}

#pragma once
#include "pch.h"

enum class SHAPE
{
	dot = 0,
	rectangle,
	triangle,
};

enum class DIR
{
	UP_RIGHT,
	UP_LEFT,
	DOWN_RIGHT,
	DOWN_LEFT,
	LEFT,
	RIGHT,
	UP,
	DOWN,
};

enum class KeyType
{
	LeftMouse = VK_LBUTTON,
	RightMouse = VK_RBUTTON,
	SpaceBar = VK_SPACE,
	ESC = VK_ESCAPE,


	W = 'W',
	A = 'A',
	S = 'S',
	D = 'D',
	d = 'd',

	F = 'F',
	G = 'G',
	Z = 'Z',
	X=  'X',


	


	Up = VK_UP,
	Down = VK_DOWN,
	Left = VK_LEFT,
	Right = VK_RIGHT,



};

enum class KeyState
{
	NONE,//아무것도 아닌상태
	PRESS, //누르고있는상태
	DOWN, //한번눌림
	UP, //키보드 자판땜
	END
};

enum
{
	KEY_TYPE_COUNT = static_cast<int32>(UINT8_MAX) + 1,
	KEY_STATE_COUNT = static_cast<int32>(KeyState::END)
};

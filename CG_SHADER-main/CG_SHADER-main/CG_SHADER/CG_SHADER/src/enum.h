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

	//�÷��̾�1
	W = 'W',
	A = 'A',
	S = 'S',
	D = 'D',
	F = 'F',
	G = 'G',

	//�÷��̾�2
	Up = VK_UP,
	Down = VK_DOWN,
	Left = VK_LEFT,
	Right = VK_RIGHT,
	J = 'J',
	K = 'K',
	Z = 'Z',
	X = 'X',
	I = '1',
	O = '2',
	P = '3',
	Q = 'Q',

	U = 'U',
	on = 'O'


};

enum class KeyState
{
	NONE,//�ƹ��͵� �ƴѻ���
	PRESS, //�������ִ»���
	DOWN, //�ѹ�����
	UP, //Ű���� ���Ƕ�
	END
};

enum
{
	KEY_TYPE_COUNT = static_cast<int32>(UINT8_MAX) + 1,
	KEY_STATE_COUNT = static_cast<int32>(KeyState::END)
};

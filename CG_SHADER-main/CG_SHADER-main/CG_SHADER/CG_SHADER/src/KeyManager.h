#pragma once
#include "enum.h"

class KeyManager
{
	DECLARE_SINGLE(KeyManager);

public:
	void Init();

	void Update();

	//������������
	bool Getbutton(KeyType key) { return GetState(key) == KeyState::PRESS; }

	//��ó�� ��������
	bool GetbuttonDown(KeyType key) { return GetState(key) == KeyState::DOWN; }

	//��ó�� �����ٰ� ����
	bool GetbuttonUp(KeyType key) { return GetState(key) == KeyState::UP; }

	vector<KeyState>& Getstate() { return _states; } //���������ͼ� ����ϱ�
private:
	KeyState GetState(KeyType key) { return _states[static_cast<uint8>(key)]; }
	vector<KeyState> _states;



};

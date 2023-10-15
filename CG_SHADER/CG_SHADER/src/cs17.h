#pragma once

#include "Line.h"
#include "Cube.h"
#include "Cylinder.h"
#include "Spiral.h"

struct Stat
{
	float m_size = 1.0f; //���������� ����
	float m_size2 = 1.0f; //�ڱ��߽ɿ����� ����
	float dx = 0;
	float dy = 0;
	float dz = 0;
	float x = 0;
	float y = 0;
	float z = 0;
};


class cs17
{

public:

	static cs17* GetInstance()
	{
		static cs17 c;
		return &c;
	}
	void Init();
	void Update();
	void Render();


	static void key_call_back(unsigned char key, int x, int y);
	void update_key(unsigned char key, int x, int y);



private:

	const float pi = 3.14159265356f;
	float degreesToRadians(float degrees)
	{
		return degrees * (pi / 180.0);
	}

	void reset();


	Line line;


	//ť��//
	Cube cube;
	Stat c1; 

	//�Ǹ���//
	Cylinder cl; 
	Stat c2; 

	//�����̷�
	Spiral spiral;
	Stat c3; //�����̷�����
	void zigzag();
	bool start_zigzag = false;
	bool init_zigzag = false;
	float radian = 0.0f; // ����
	float radius = 0.01f; // ������


};


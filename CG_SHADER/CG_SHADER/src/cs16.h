#pragma once

#include "Cube.h"
#include "Pyramid.h"
#include "Line.h"
enum Mode {
	e_rotate,
	e_revolve,


};


class cs16
{


public:

	static cs16* GetInstance()
	{
		static cs16 c;
		return &c;
	}


	void Init();
	void Update();
	void Render();
	static void call_back_key(unsigned char key, int x, int y);
	void Update_key(unsigned char key, int x, int y);

private:

	Line line;
	Mode mode;



	////////////////////////큐브///////////////////////////////
	Cube cube;
	vec3 cube_m_pos = { -0.9f ,0.3f, 0 };//초기 포지션 

	glm::vec4 temp;
	glm::mat4 t1;
	glm::mat4 t2;
	glm::mat4 t3;
	glm::mat4 result;
	vec2 cube_revolve; //공전
	vec2 cube_rotate; //자전

	////////////////////////삼각뿔///////////////////////////////
	Pyramid pr;
	vec3 pr_m_pos = { 0.9f ,0.3f, 0 };//초기 포지션 


};


#pragma once

#include "Cube.h"
#include "Pyramid.h"
#include "Line.h"
enum Mode {
	revolve,
	rotate,
};

enum XY {
	rotate_x_plus,
	rotate_x_minus,
	rotate_y_plus,
	rotate_y_minus,
};

struct my
{

	glm::vec4 temp;
	glm::mat4 t1;
	glm::mat4 t2;
	glm::mat4 t3;
	glm::mat4 t4;
	glm::mat4 goto00;
	glm::mat4 backtopos;
	glm::mat4 result;
	glm::mat4 result2;
	vec2 revolve; //°øÀü
	vec2 rotate; //ÀÚÀü

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
	XY mode2;

	bool change_mode = false;
	////////////////////////Å¥ºê///////////////////////////////
	Cube cube;
	vec3 cube_m_pos = { -0.9f ,0.3f, 0 };//ÃÊ±â Æ÷Áö¼Ç 
	////////////////////////»ï°¢»Ô///////////////////////////////
	Pyramid pyramid;
	vec3 pr_m_pos = { 0.9f,0.3f,0 };

	////////////////////////»ï°¢»Ô///////////////////////////////
	GLUquadricObj* qobj;

	my cb; //Å¥ºê
	my pr; //»ï°¢»Ô
	my sp; //±¸ 

	

};


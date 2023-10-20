#pragma once

#include "rect18.h"
#include "tri18.h"
#include "Line.h"

enum class who_start
{
	left,
	right,
	front,
	back
};


class cs18
{

public:

	cs18() {};
	~cs18() {};

	void Init();
	void Update();
	void Render();
	
	void RectRender();
	void TriRender();
	


private:

	
	bool rectdraw = false;

	Line line;
	rect18 rect;
	tri18 tri;

	void keyhandle();


	//y축자전
	void y_animation();
	bool start_y_anim = false;
	float y_degree=0;

	//애니메이션 T
	void t_animation();
	bool  start_t_anim = false;
	float t_degree = 0;

	//애니메이션 F
	void f_animation();
	bool  start_f_anim = false;
	bool f_open = true;
	float f_degree = 0;


	//애니메이션 S
	void s_animation();
	bool  start_s_anim = false;
	bool s_open = true;
	float s_dt = 0;


	//애니메이션 b
	void b_animation();
	bool  start_b_anim = false;
	bool b_open = true;
	float b_dt = 1.0f;

	//애니메이션 O,R
	void o_animation();
	void r_animation();
	bool  start_o_anim = false;
	bool  start_r_anim = false;

	bool o_open = true;
	float o_dt_left = 0;
	float o_dt_right = 0;
	float o_dt_front = 0;
	float o_dt_back = 0;

	bool r_open = true;
	who_start start= who_start::front;
	//카메라
	float camera_speed = 0.1f;
	float dt = 0;

	//투영 
	bool perspective = true;
};


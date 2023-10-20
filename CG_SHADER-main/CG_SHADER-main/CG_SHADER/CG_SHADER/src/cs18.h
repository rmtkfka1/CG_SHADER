#pragma once

#include "rect18.h"
#include "Line.h"


class cs18
{

public:

	cs18() {};
	~cs18() {};

	void Init();
	void Update();
	void Render();

	


private:

	Line line;
	rect18 rect;

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


	float camera_speed = 0.1f;
	float dt = 0;
};


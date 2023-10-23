#pragma once

class Body;
class Arm;
class Small_body;
class Small_arm;
class Line;
class Bottom;

class ex20
{

public:


	void Init();

	void Update();

	void Render();



	void HandleKey();


	Line* line;
	Body* body;
	Bottom* bottom;

	//아래몸체 이동하기위한 변수
	void b_animation();
	void v_animation();
	float b_dx=0;
	float v_anim=false;
	float b_anim=false;


	//윗몸체 이동하기위한 변수
	float m_dx=0;
	float n_anim = false;
	float m_anim = false;
	void m_animation();
	void n_animation();

	//포신 이동하기위한 변수
	float dx_1 = 0;
	bool start_1 = false;
	float anim_1 = false;
	float anim_2 = false;
	void animation_1();
	void animation_2();

	//포신 이동하기위한 변수2
	float dx_e = 0;
	bool start_e;
	float anim_e = false;
	bool anim_r = false;
	void animation_e();
	void animation_r();



	//눈깔움직이기
	void t_animation();
	bool t_anim = false;
	float t_dx = 0;


	//카메라 자전시키기
	bool  camera_bingle = false;
	void  x_animation();
	float  camera_revolve_dx;
	float  camera_revolve_dz;
	float  camera_angle2 = 260.0f;

	//카메라 변수
	bool  camera_auto_rotate = false;
	bool   move_xy = true;
	float camera_angle = 0.0f;
	float dt = 0;
	float camera_rotate_dx;
	float camera_rotate_dz;
	float camera_dx = 0.0f;
	float camera_dy = 50.0f;
	float camera_dz = 100.0f;
};


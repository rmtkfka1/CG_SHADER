#pragma once

#include "robot.h"
#include "stage.h"
#include "front.h"


enum class Dir
{
	left,
	right,
	up,
	down
};


class cs22
{

public:

	void Init();
	void Update();
	void Render();

	void OpenTheDoor();
	void jump();

private:

	stage st;

	front left;
	front right;

	//////////////////////////////////

	robot head;

	robot body;

	robot nose;

	robot left_arm;
	robot right_arm;

	robot left_leg;
	robot right_leg;

	float dt;


	float open_dx = 0;

	bool doyouwantopen = false;

	Dir dir;

	float degree = 0;

	float move_dx = 0;
	float move_dz = 0;

	float dy = 0;

	float swing;
	float swing2;
	int count = 0;

	float test;
	float speed=1.0f;

	bool doyouwantjump = false;

	float camera_dx;
	float camera_dz;

	bool camera_flag = false;
};


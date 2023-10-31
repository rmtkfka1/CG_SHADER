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

	float dx = 0;
	float open_dx = 0;

	bool doyouwantopen = false;

	Dir dir;

	float degree = 0;

	float move_dx = 0;
	float move_dz = 0;

	float swing;
};


#pragma once

#include "rect18.h"
#include "Line.h"

enum rect_dir
{
	left,
	right,
	up,
	down,
	back,
	front
};




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
	rect18 rect[6];


	float camera_speed = 0.1f;
	float dt = 0;
};


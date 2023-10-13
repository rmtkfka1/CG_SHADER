#pragma once

#include "Cube.h"
#include "Pyramid.h"

enum class Mode
{
	Wire,
	Solid,
};


class cs15
{

public:


	void Init();
	void Update();
	void Render();

private:
	Cube solid_cube;
	Cube wire_cube;
	Pyramid solid_pramid;
	Pyramid wire_pramid;

	Mode mode=Mode::Solid;
	int what_draw = -1;
	bool cull_face=false;

	float dx = 0;
	float dy = 0;

	float degree_x=20.0f;
	float degree_y=20.0f;
};


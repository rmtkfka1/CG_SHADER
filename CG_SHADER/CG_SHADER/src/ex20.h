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

	Line* line;
	Body* body;
	Small_body* s_body;
	Arm* arm;
	Small_arm* s_arm;
	Bottom* bottom;

	float dx=0;
	float dy=0;
	float dz=0;
};


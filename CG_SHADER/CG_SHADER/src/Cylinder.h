#pragma once


class Cylinder
{

public:
	Cylinder();
	~Cylinder();

	void Render();

private:

	GLUquadricObj* ptr =nullptr;

};


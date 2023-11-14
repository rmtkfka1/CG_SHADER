#pragma once
class Circle
{

public:
	Circle(float i_radius,float o_radius);
	~Circle();

	void Update();
	void Render();


private:

	float _i_radius;
	float _o_radius;
	GLUquadricObj* ptr = nullptr;


};
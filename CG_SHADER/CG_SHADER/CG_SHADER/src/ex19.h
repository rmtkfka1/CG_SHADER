#pragma once

class Sphere;
class Circle;

class ex19
{


public:

	void Init();
	void Update();
	void Render();



private:

	//Áö±¸
	Sphere*  earth        = nullptr;
	Circle * earth_circle = nullptr;

	Sphere * moon         = nullptr;
	Circle * moon_circle  = nullptr;

	Sphere * star         = nullptr;



	float speed_0 = 3.0f;

	float speed_1 = 6.0f;

	float speed_2 = 8.0f;

	float dx = 0;
	float dy =0;
	float dz = 0;

	bool perspective = true;

	float rotate_y = 0;
	float rotate_z = 0;

	float dt = 0;

};


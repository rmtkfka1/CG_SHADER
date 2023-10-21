#pragma once

#include "Sphere.h"
#include "Circle.h"


class ex19
{


public:

	void Init();
	void Update();
	void Render();



private:

	//Áö±¸
	Sphere* earth = new Sphere(3.0f);
	Circle* earth_circle = new Circle(12.0f, 12.0f);

	
	Sphere* moon = new Sphere(1.0f);
	Circle* moon_circle = new Circle(5.0f, 5.0f);


	Sphere* star = new Sphere(0.5f);



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


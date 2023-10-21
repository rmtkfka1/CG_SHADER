#pragma once
class Sphere
{

public:
	Sphere(float radius);
	~Sphere();

	void Update();
	void Render();

private:

	float _radius;
	GLUquadricObj* ptr = nullptr;


};


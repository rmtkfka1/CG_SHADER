#include "pch.h"
#include "Circle.h"

Circle::Circle(float i_radius,float _o_radius) :_i_radius(i_radius),_o_radius(_o_radius)
{
	ptr = gluNewQuadric();
	gluQuadricDrawStyle(ptr, GLU_LINE); // 도형 스타일
	gluQuadricNormals(ptr, GLU_SMOOTH);
	gluQuadricOrientation(ptr, GLU_OUTSIDE);
}


Circle::~Circle()
{
	gluDeleteQuadric(ptr);

}

void Circle::Update()
{

}

void Circle::Render()
{
	gluDisk(ptr,_i_radius, _o_radius, 100,100);
}

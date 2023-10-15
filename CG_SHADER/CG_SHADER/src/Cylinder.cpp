#include "pch.h"
#include "Cylinder.h"

Cylinder::Cylinder()
{
	ptr = gluNewQuadric();
	gluQuadricDrawStyle(ptr, GLU_LINE); // 도형 스타일
	gluQuadricNormals(ptr, GLU_SMOOTH);
	gluQuadricOrientation(ptr, GLU_OUTSIDE);
}

Cylinder::~Cylinder()
{
	gluDeleteQuadric(ptr);
}

void Cylinder::Render()
{
	gluCylinder(ptr, 0.001, 0.1, 0.1, 20, 30);// 객체 만들기
}

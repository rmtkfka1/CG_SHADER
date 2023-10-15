#include "pch.h"
#include "Cylinder.h"

Cylinder::Cylinder()
{
	ptr = gluNewQuadric();
	gluQuadricDrawStyle(ptr, GLU_LINE); // ���� ��Ÿ��
	gluQuadricNormals(ptr, GLU_SMOOTH);
	gluQuadricOrientation(ptr, GLU_OUTSIDE);
}

Cylinder::~Cylinder()
{
	gluDeleteQuadric(ptr);
}

void Cylinder::Render()
{
	gluCylinder(ptr, 0.001, 0.1, 0.1, 20, 30);// ��ü �����
}

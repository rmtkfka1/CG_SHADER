#include "pch.h"
#include "Sphere.h"

Sphere::Sphere(float radius):_radius(radius)
{
	ptr = gluNewQuadric();
	gluQuadricDrawStyle(ptr, GLU_LINE); // 도형 스타일
	gluQuadricNormals(ptr, GLU_SMOOTH);
	gluQuadricOrientation(ptr, GLU_OUTSIDE);

}


Sphere::~Sphere()
{
	gluDeleteQuadric(ptr);

}

void Sphere::Update()
{
	if(KeyManager::GetInstance()->GetbuttonDown(KeyType::ONE))
	{
		gluQuadricDrawStyle(ptr, GLU_FILL); // 도형 스타일
		gluQuadricNormals(ptr, GLU_SMOOTH);
		gluQuadricOrientation(ptr, GLU_OUTSIDE);
	}

	if (KeyManager::GetInstance()->GetbuttonDown(KeyType::TWO))
	{
		gluQuadricDrawStyle(ptr, GLU_LINE); // 도형 스타일
		gluQuadricNormals(ptr, GLU_SMOOTH);
		gluQuadricOrientation(ptr, GLU_OUTSIDE);
	}

}

void Sphere::Render()
{
	gluSphere(ptr, _radius, 30, 10);
}

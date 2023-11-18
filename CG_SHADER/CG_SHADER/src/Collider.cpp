#include "pch.h"
#include "Collider.h"

Collider::Collider(ColliderType colliderType)
{
}

Collider::~Collider()
{
}

void Collider::Init()
{
}

void Collider::Update()
{
}

void Collider::Render(Shader& shader)
{

}

bool Collider::CheckCollision(Collider* other)
{
	return false;
}

bool Collider::CheckCollisionBox2Box(BoxCollider* b1, BoxCollider* b2)
{
	return false;
}

bool Collider::CheckCollisionSphere2Box(SphereCollider* s1, BoxCollider* b2)
{
	return false;
}

bool Collider::CheckCollisionSphere2Sphere(SphereCollider* s1, SphereCollider* s2)
{
	return false;
}

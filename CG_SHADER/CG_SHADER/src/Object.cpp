#include "pch.h"
#include "Object.h"


Object::Object()
{
	cout << "object 기본생성자 호출" << endl;
}

Object::~Object()
{
	cout << "object 소멸자 호출" << endl;
}

void Object::Init()
{

}

void Object::Update()
{

}

void Object::Render(Shader& shader)
{

}

void Object::PrintInfo()
{
	_model->PrintInfo();
}


#include "pch.h"
#include "Object.h"


Object::Object()
{
	cout << "object �⺻������ ȣ��" << endl;
}

Object::~Object()
{
	cout << "object �Ҹ��� ȣ��" << endl;
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


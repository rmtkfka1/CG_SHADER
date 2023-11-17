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

void Object::SetRotate(Shader& shader, float radian, float x, float y, float z)
{

	shader.Bind();

	auto trans1 = glm::translate(glm::mat4(1.0f), glm::vec3(-_center.x, -_center.y, -_center.z)); // �������� �̵���Ŵ

	auto rotate = glm::rotate(glm::mat4(1.0f), glm::radians(radian), glm::vec3(x, y, z)); //���� ��Ŵ

	auto trans2 = glm::translate(glm::mat4(1.0f), glm::vec3(_center.x, _center.y, _center.z)); // ���ڸ��� �̵���Ŵ

	auto result = trans2 * rotate * trans1;

	shader.SetUniformMat4f("u_model", result);


}

void Object::PrintInfo()
{
	_model->PrintInfo();


}


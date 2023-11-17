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

void Object::SetRotate(Shader& shader, float radian, float x, float y, float z)
{

	shader.Bind();

	auto trans1 = glm::translate(glm::mat4(1.0f), glm::vec3(-_center.x, -_center.y, -_center.z)); // 원점으로 이동시킴

	auto rotate = glm::rotate(glm::mat4(1.0f), glm::radians(radian), glm::vec3(x, y, z)); //자전 시킴

	auto trans2 = glm::translate(glm::mat4(1.0f), glm::vec3(_center.x, _center.y, _center.z)); // 제자리로 이동시킴

	auto result = trans2 * rotate * trans1;

	shader.SetUniformMat4f("u_model", result);


}

void Object::PrintInfo()
{
	_model->PrintInfo();


}


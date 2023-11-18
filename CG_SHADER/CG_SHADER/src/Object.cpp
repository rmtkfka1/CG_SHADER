#include "pch.h"
#include "Object.h"


Object::Object()
{

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


glm::mat4 Object::GetRotate(float radian, float x, float y, float z)
{

	
	auto trans1 = glm::translate(glm::mat4(1.0f), glm::vec3(-_center.x, -_center.y, -_center.z)); // �������� �̵���Ŵ

	auto rotate = glm::rotate(glm::mat4(1.0f), glm::radians(radian), glm::vec3(x, y, z)); //���� ��Ŵ

	auto trans2 = glm::translate(glm::mat4(1.0f), glm::vec3(_center.x, _center.y, _center.z)); // ���ڸ��� �̵���Ŵ

	auto result = trans2 * rotate * trans1;

	return result;

}

glm::mat4 Object::GetScale(float dx,float dy ,float dz)
{
	
	auto trans1 = glm::translate(glm::mat4(1.0f), glm::vec3(-_center.x, -_center.y, -_center.z)); // �������� �̵���Ŵ

	auto resize = glm::scale(glm::mat4(1.0f), glm::vec3(dx, dy, dz));

	auto trans2 = glm::translate(glm::mat4(1.0f), glm::vec3(_center.x, _center.y, _center.z)); // ���ڸ��� �̵���Ŵ

	auto result = trans2 * resize * trans1;

	_size.x *= dx;
	_size.y *= dy;
	_size.z *= dz;

	return result;

}

glm::mat4 Object::GetTransPose(float dx, float dy, float dz)
{
	auto trans = glm::translate(glm::mat4(1.0f), glm::vec3(dx, dy, dz)); // �������� �̵���Ŵ
	return trans;
}

void Object::SetSimple(Shader& shader)
{
	shader.Bind();
	shader.SetUniformMat4f("u_model", glm::mat4(1.0f));
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

void Object::SetScale(Shader& shader, float dx, float dy, float dz) 
{

	shader.Bind();

	auto trans1 = glm::translate(glm::mat4(1.0f), glm::vec3(-_center.x, -_center.y, -_center.z)); // �������� �̵���Ŵ

	auto resize = glm::scale(glm::mat4(1.0f), glm::vec3(dx, dy, dz));

	auto trans2 = glm::translate(glm::mat4(1.0f), glm::vec3(_center.x, _center.y, _center.z)); // ���ڸ��� �̵���Ŵ

	auto result = trans2 * resize * trans1;


	_size.x *= dx;
	_size.y *= dy;
	_size.z *= dz;

	shader.SetUniformMat4f("u_model", result);
}

void Object::SetTransPose(Shader& shader, float dx, float dy, float dz)
{
	shader.Bind();

	auto trans = glm::translate(glm::mat4(1.0f), glm::vec3(dx, dy, dz)); // �������� �̵���Ŵ


	shader.SetUniformMat4f("u_model", trans);

}

void Object::PrintInfo()
{
	_model->PrintInfo();
}


#include "pch.h"
#include "Object.h"
#include "Component.h"
#include "Collider.h"

Object::Object()
{

}

Object::~Object()
{
	for (int i = 0; i < v_component.size(); ++i)
	{
		delete v_component[i];
		v_component[i] = nullptr;
	}

	v_component.clear();
}

void Object::Init()
{
	for (Component* component : v_component)
	{
		component->Init();
	}

}

void Object::Update()
{
	for (Component* component : v_component)
	{
		component->Update();
	}
}

void Object::Render(Shader& shader , glm::mat4 tesk)
{

	for (Component* component : v_component)
	{
		component->Render(shader);
	}

}


glm::mat4 Object::GetRotate(float radian, float x, float y, float z)
{

	
	auto trans1 = glm::translate(glm::mat4(1.0f), glm::vec3(-_center.x, -_center.y, -_center.z)); // 원점으로 이동시킴

	auto rotate = glm::rotate(glm::mat4(1.0f), glm::radians(radian), glm::vec3(x, y, z)); //자전 시킴

	auto trans2 = glm::translate(glm::mat4(1.0f), glm::vec3(_center.x, _center.y, _center.z)); // 제자리로 이동시킴

	auto result = trans2 * rotate * trans1;

	return result;

}

glm::mat4 Object::GetScale(float dx,float dy ,float dz)
{
	
	auto trans1 = glm::translate(glm::mat4(1.0f), glm::vec3(-_center.x, -_center.y, -_center.z)); // 원점으로 이동시킴

	auto resize = glm::scale(glm::mat4(1.0f), glm::vec3(dx, dy, dz));

	auto trans2 = glm::translate(glm::mat4(1.0f), glm::vec3(_center.x, _center.y, _center.z)); // 제자리로 이동시킴

	auto result = trans2 * resize * trans1;



	return result;

}

glm::mat4 Object::GetTransPose(float dx, float dy, float dz)
{

	auto trans = glm::translate(glm::mat4(1.0f), glm::vec3(dx, dy, dz)); // 원점으로 이동시킴
	

	return trans;

}

//void Object::SetSimple(Shader& shader)
//{
//	shader.Bind();
//	shader.SetUniformMat4f("u_model", glm::mat4(1.0f));
//}
//
//void Object::SetRotate(Shader& shader, float radian, float x, float y, float z)
//{
//
//	shader.Bind();
//
//	auto trans1 = glm::translate(glm::mat4(1.0f), glm::vec3(-_center.x, -_center.y, -_center.z)); // 원점으로 이동시킴
//
//	auto rotate = glm::rotate(glm::mat4(1.0f), glm::radians(radian), glm::vec3(x, y, z)); //자전 시킴
//
//	auto trans2 = glm::translate(glm::mat4(1.0f), glm::vec3(_center.x, _center.y, _center.z)); // 제자리로 이동시킴
//
//	auto result = trans2 * rotate * trans1;
//
//	shader.SetUniformMat4f("u_model", result);
//
//}
//
//void Object::SetScale(Shader& shader, float dx, float dy, float dz) 
//{
//
//	shader.Bind();
//
//	auto trans1 = glm::translate(glm::mat4(1.0f), glm::vec3(-_center.x, -_center.y, -_center.z)); // 원점으로 이동시킴
//
//	auto resize = glm::scale(glm::mat4(1.0f), glm::vec3(dx, dy, dz));
//
//	auto trans2 = glm::translate(glm::mat4(1.0f), glm::vec3(_center.x, _center.y, _center.z)); // 제자리로 이동시킴
//
//	auto result = trans2 * resize * trans1;
//
//
//	_size.x *= dx;
//	_size.y *= dy;
//	_size.z *= dz;
//
//	shader.SetUniformMat4f("u_model", result);
//}
//
//void Object::SetTransPose(Shader& shader, float dx, float dy, float dz)
//{
//	shader.Bind();
//
//	auto trans = glm::translate(glm::mat4(1.0f), glm::vec3(dx, dy, dz)); // 원점으로 이동시킴
//
//
//	shader.SetUniformMat4f("u_model", trans);
//
//}

void Object::PrintInfo()
{
	_model->PrintInfo();
}

void Object::AddComponent(Component* component)
{
	if (component == nullptr)
		return;

	component->SetOwner(this);
	v_component.push_back(component);

}

void Object::RemoveComponent(Component* component)
{

	auto findIt = std::find(v_component.begin(), v_component.end(), component);

	if (findIt == v_component.end())
		return;

	v_component.erase(findIt);
}

void Object::OnComponentBeginOverlap(Collider* collider, Collider* other)
{


}

void Object::OnComponentEndOverlap(Collider* collider, Collider* other)
{
}


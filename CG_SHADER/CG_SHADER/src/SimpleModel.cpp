#include "pch.h"
#include "SimpleModel.h"
#include "Object.h"
#include "Collider.h"

SimpleModel::SimpleModel(const string& model_filepath)
{


	_model = new Model();
	_model->LoadModel(model_filepath);
	_center = _model->GetCenter();
	_size = _model->GetSize();
	_first_center.x = _model->GetCenter().x;
	_first_center.y = _model->GetCenter().y;
	_first_center.z = _model->GetCenter().z;


}

SimpleModel::~SimpleModel()
{
	delete _model;
}

void SimpleModel::Init()
{
	Super::Init();


}

void SimpleModel::Update()
{
	Super::Update();

}

void SimpleModel::Render(Shader& shader, glm::mat4 tesk)
{
	

	shader.SetUniform3f("control_color", _debug_color.x, _debug_color.y, _debug_color.z);
	auto simple = glm::mat4(1.0f);
	shader.SetUniformMat4f("u_model", simple);
	Super::Render(shader, simple);


	shader.SetUniform3f("control_color", 0, 0, 0);
	shader.SetUniformMat4f("u_model", tesk);
	_model->RenderModel(shader);




}

void SimpleModel::OnComponentBeginOverlap(Collider* collider, Collider* other)
{
	_debug_color.x = 0;
	_debug_color.y = 1;
	_debug_color.z = 0;
}

void SimpleModel::OnComponentEndOverlap(Collider* collider, Collider* other)
{
	_debug_color.x = 1;
	_debug_color.y = 0;
	_debug_color.z = 0;
}

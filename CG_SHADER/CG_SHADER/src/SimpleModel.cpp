#include "pch.h"
#include "SimpleModel.h"
#include "Object.h"


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


	shader.SetUniform3f("contorl_color", 1, 0, 0);
	auto simple = glm::mat4(1.0f);
	shader.SetUniformMat4f("u_model", simple);
	Super::Render(shader, simple);


	shader.SetUniform3f("contorl_color", 0, 0, 0);
	shader.SetUniformMat4f("u_model", tesk);
	_model->RenderModel(shader);




}

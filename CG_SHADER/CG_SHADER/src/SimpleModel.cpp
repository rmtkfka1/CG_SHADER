#include "pch.h"
#include "SimpleModel.h"
#include "Object.h"


SimpleModel::SimpleModel(const string& model_filepath)
{


	_model = new Model();
	_model->LoadModel(model_filepath);
	_center = _model->GetCenter();
	_size = _model->GetSize();



}

SimpleModel::~SimpleModel()
{

}

void SimpleModel::Init()
{

}

void SimpleModel::Update()
{


}

void SimpleModel::Render(Shader& shader)
{

	_model->RenderModel(shader);



}

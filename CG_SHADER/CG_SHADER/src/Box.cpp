#include "pch.h"
#include "Box.h"
#include "Object.h"


Box::Box(const string& model_filepath, const string& texture_filepath,int slot)
{


	_model = new Model();
	_texture = new Texture(texture_filepath);

	_model->LoadModel(model_filepath);
	_center = _model->GetCenter();
	_size = _model->GetSize();

	_slot = slot;

	_texture->Bind(_slot);


}

Box::~Box()
{

}

void Box::Init()
{

}

void Box::Update()
{


}

void Box::Render(Shader& shader)
{

	shader.SetUniform1i("u_texture", _slot); //0�� ������ �ؽ�ó�� ����� ���̶�� ���� ���̴��� ���
	_model->RenderModel(shader);

}

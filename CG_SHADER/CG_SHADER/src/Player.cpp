#include "pch.h"
#include "Player.h"
#include "Object.h"
#include "Object.h"
#include "Collider.h"

Player::Player(const string& model_filepath)
{


	_model = new Model();
	_model->LoadModel(model_filepath);
	_center = _model->GetCenter();
	_size = _model->GetSize();
	_first_center.x = _model->GetCenter().x;
	_first_center.y = _model->GetCenter().y;
	_first_center.z = _model->GetCenter().z;


}

Player::~Player()
{

}

void Player::Init()
{
	Super::Init();


}

void Player::Update()
{
	Super::Update();

}

void Player::Render(Shader& shader, glm::mat4 tesk)
{


	shader.SetUniform3f("contorl_color", _debug_color.x, _debug_color.y, _debug_color.z);
	auto simple = glm::mat4(1.0f);
	shader.SetUniformMat4f("u_model", simple);
	Super::Render(shader, simple);


	shader.SetUniform3f("contorl_color", 0, 0, 0);
	shader.SetUniformMat4f("u_model", tesk);
	_model->RenderModel(shader);




}

void Player::OnComponentBeginOverlap(Collider* collider, Collider* other)
{


	_collusion = true;

	_debug_color.x = 0;
	_debug_color.y = 1;
	_debug_color.z = 0;

	vector<Shader*>& shader =ObjectManager::GetInstance()->Get_Shader();
	//반대로 밀어버리면된다?





}

void Player::OnComponentEndOverlap(Collider* collider, Collider* other)
{
	_collusion = false;

	_debug_color.x = 1;
	_debug_color.y = 0;
	_debug_color.z = 0;



}

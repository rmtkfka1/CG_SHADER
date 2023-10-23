#include "pch.h"
#include "Arm.h"
#include "Body.h"


void Arm::Init()
{
	body = new Body;

	body->Init();
}

void Arm::Update()
{
}

void Arm::Render()
{

	auto v = ObjectManager::GetInstance()->Get_Shader();
	
	body->Render();
}

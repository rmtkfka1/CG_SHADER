#include "pch.h"
#include "p14_world.h"

p14_world::p14_world()
{

}

void p14_world::Init(vec3 center, float size)
{
	sakak.Init();
	palkak.Init(vec3(0,0,0),0.3f);
}

void p14_world::Update()
{
	sakak.Update();
	palkak.Update();
}

void p14_world::Render()
{
	sakak.Render();
	palkak.Render();

}

void p14_world::changesakak()
{
	sakak.SetDraw(false);
}

void p14_world::changepalkak()
{
	palkak.SetDraw(false);
}

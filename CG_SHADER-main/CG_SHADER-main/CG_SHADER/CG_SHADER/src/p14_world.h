#pragma once

#include "p14.h"
#include "p14_4.h"

class p14_world
{
public:

	p14_world();


	void Init(vec3 center, float size);
	void Update();
	void Render();

	void changesakak();
	void changepalkak();

private:
	p14 palkak;
	p14_4 sakak;

};


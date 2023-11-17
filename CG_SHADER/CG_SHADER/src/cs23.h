#pragma once

class SimpleModel;
class Shader;
class Texture;

class cs23
{

public:

	cs23();
	~cs23();


	void Init();
	void Update();
	void Render();

private:
	
	SimpleModel* plane;
	SimpleModel* box;

	Shader* shader;

	Texture* box_texture;
	Texture* plane_texture;

	float dx = 0;
	float dz = 30;
	float dy = 30;
	
	float testing = 0;



};


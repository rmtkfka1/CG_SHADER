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
	void keyboard();
	void Render();

private:
	
	SimpleModel* plane;
	SimpleModel* box;

	SimpleModel* door_left;
	SimpleModel* door_right;

	SimpleModel* hat;

	Shader* shader;

	Texture* box_texture;
	Texture* plane_texture;

	/////////////////
	void door_animation();
	bool door_open = false;

	float left_door_degree = 0;
	float right_door_degree = 0;

	float left_door_degree2 = 0;
	float right_door_degree2 = 0;

	//testing �� ������
	float dx = 0;
	float dy = 280;
	float dz = 330;
	//170 270

	float testing2 = 0;
	float testing = 28;



};


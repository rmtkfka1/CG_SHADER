#pragma once

class SimpleModel;
class Shader;
class Texture;
class Player;

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
	SimpleModel* box2;
	SimpleModel* box3;

	SimpleModel* door_left;
	SimpleModel* door_right;

	SimpleModel* hat;

	Player* people_body;


	Shader* shader;

	Texture* body_texture;
	Texture* box_texture;
	Texture* plane_texture;

	/////////////////
	void door_animation();
	bool door_open = false;

	float left_door_degree = 0;
	float right_door_degree = 0;

	float left_door_degree2 = 0;
	float right_door_degree2 = 0;

	//사람
	float people_x=0;
	float people_y=0;
	float people_z=0;


	bool is_jump = false;
	bool is_down = false;
	void jump_animation();


	//testing 용 변수들
	float dx = 0;
	float dy = 280;
	float dz = 330;
	//170 270

	float testing2 = 0;
	float testing = 28;



};


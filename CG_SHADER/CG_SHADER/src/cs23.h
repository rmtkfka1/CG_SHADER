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

	//
	SimpleModel* hey_left;
	SimpleModel* hey_right;
	SimpleModel* hey_top;

	SimpleModel* p1[4];

	vector<SimpleModel*> v_baby;

	Shader* shader;

	Texture* body_texture;
	Texture* box_texture;
	Texture* plane_texture;
	Texture* baby_texture;
	/////////////////



	void makebaby();
	void removebaby();

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


	float baby_y = 0;
	bool baby_is_jump = false;
	bool baby_is_down = false;
	void baby_jump_animation();


	//testing 용 변수들
	float dx = 0;
	float dy = 280;
	float dz = 330;
	//170 270

	float testing2 = 0;
	float testing = 0;





};


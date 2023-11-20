#pragma once


class Shader;
class SimpleModel;
class Texture;
class Light;
class Camera;



class cs25
{


public:

	cs25();
	~cs25();

	void Init();
	void Update();
	void Render();

private:

	
	Shader* shader;

	SimpleModel* rect;

	SimpleModel* camera;


	Texture* texture;
	Texture* texture2;

	Light *light;

	bool draw_rect = true;

	//Camera* camera;


	void KeyUpdate();

	float rect_degree = 0;

	float camera_radius = 30.0f;

	void ChangeLight();

	float degree = 0;

	bool light_on = true;

	float testing=0;
	float testing2 = 0;

	float camera_speed = 0;

	float x = 0;
	float z = 0;

};


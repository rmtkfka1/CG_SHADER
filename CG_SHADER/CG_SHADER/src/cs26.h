#pragma once


class SimpleModel;
class Texture;
class Shader;
class Light;
class Camera;


class cs26
{

public:


	void Init();
	void Update();
	void Render();

	void Rotate();

private:

	void KeyUpdate();

	Shader* shader;

	SimpleModel* circle1;


	Texture* texture;
	Light* light;

	Camera* camera;


	float testing;

	bool rotate = false;
	float camera_speed;

};


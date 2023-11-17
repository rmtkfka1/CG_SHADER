#pragma once

class Texture;
class Model;
class Camera;
class Shader;

class cs23
{

public:

	cs23();
	~cs23();


	void Init();
	void Update();
	void Render();

private:
	

	shared_ptr<Model> _plane;
	shared_ptr<Model> _rect;
	shared_ptr<Texture> _texture;
	shared_ptr<Texture> _texture_box;
	shared_ptr<Camera> _camera;
	shared_ptr<Shader> _shader;



	float dx = 0;
	float dz = 30;
	float dy = 30;
	






};


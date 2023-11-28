#pragma once

class Shader;
class Model;
class Light2;
class Texture;
class cs27
{


public:
	void init();

	void update();


	void render();

	void keyupdate();

	Shader* shader;

	Model* model;
	Model* model2;

	Texture* texture;
	Texture* texture2;
	Light2* light;

};


#pragma once
class Shader;
class Model;
class Light2;
class Texture;
class cs28
{


public:
	void init();

	void update();


	void render();

	void keyupdate();

	Shader* shader;

	Model* model;
	Model* model2;
	Model* mdoel3;
	Model* model4;
	Model* model5;
	Model* mdoel6;

	Model* bg;

	Model* tri;
	Model* tri2;
	Model* tri3;
	Model* tri4;
	Model* tri5;


	Texture* texture;
	Texture* texture2;
	Texture* texture3;
	Texture* texture4;
	Texture* texture5;
	Texture* texture6;
	Texture* texture7;

	Light2* light;


	bool a;
	bool six=true;

	float degree = 0;
	float degree2 = 0;
};
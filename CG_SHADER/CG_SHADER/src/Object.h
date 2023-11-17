#pragma once


class Texture;
class Model;
class Shader;

class Object
{

public:

	Object();
	virtual ~Object();

	virtual void Init();
	virtual void Update();
	virtual void Render(Shader& shader);
	void PrintInfo();

protected:
	Model* _model;
	Texture*_texture;


	int _slot; //texture ½½·Ô
	glm::vec3 _center;
	glm::vec3 _size;


};


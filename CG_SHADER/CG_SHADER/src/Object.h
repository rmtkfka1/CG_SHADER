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


	void SetRotate(Shader& shader, float radian , float x, float y, float z);// radian �� ��������
	void PrintInfo();

protected:

	Model* _model;
	int _slot; //texture ����
	glm::vec3 _center;
	glm::vec3 _size;


};


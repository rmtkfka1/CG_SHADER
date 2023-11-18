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

	glm::vec3 GetCenter() { return _center; }
	glm::vec3 GetSize() { return _size; }

	glm::mat4 GetRotate(float radian, float x, float y, float z);
	glm::mat4 GetScale(float dx,float dy, float dz); // ũ������ �ڵ�ȭ(mat4 ����� ��Ľ� �����ؼ� ����ҋ� ���)
	glm::mat4 GetTransPose(float dx, float dy, float dz); // ũ������ �ڵ�ȭ(mat4 ����� ��Ľ� �����ؼ� ����ҋ� ���)


	void SetSimple(Shader& shader);
	void SetRotate(Shader& shader,float radian, float x, float y, float z);// ���� �ڵ�ȭ ( �ѹ�������)
	void SetScale(Shader& shader ,float dx, float dy, float dz); // ũ������ �ڵ�ȭ (�ѹ��� ����)
	void SetTransPose(Shader& shader, float dx, float dy, float dz);

	void PrintInfo();
	

	//�ӽÿ�
	void SetCenter(glm::vec3 temp) { _center = temp; }

protected:

	bool test=false;

	Model* _model{};
	glm::vec3 _center{};
	glm::vec3 _size{};


};


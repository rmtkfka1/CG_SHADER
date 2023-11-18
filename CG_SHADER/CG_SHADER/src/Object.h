#pragma once

class Component;
class Texture;
class Model;
class Shader;
class Collider;

class Object
{

public:

	Object();
	virtual ~Object();

	virtual void Init();
	virtual void Update();
	virtual void Render(Shader& shader,glm::mat4 tesk);



	glm::mat4 GetRotate(float radian, float x, float y, float z);
	glm::mat4 GetScale(float dx,float dy, float dz); // ũ������ �ڵ�ȭ(mat4 ����� ��Ľ� �����ؼ� ����ҋ� ���)
	glm::mat4 GetTransPose(float dx, float dy, float dz); // ũ������ �ڵ�ȭ(mat4 ����� ��Ľ� �����ؼ� ����ҋ� ���)


	//void SetSimple(Shader& shader);
	//void SetRotate(Shader& shader,float radian, float x, float y, float z);// ���� �ڵ�ȭ ( �ѹ�������)
	//void SetScale(Shader& shader ,float dx, float dy, float dz); // ũ������ �ڵ�ȭ (�ѹ��� ����)
	//void SetTransPose(Shader& shader, float dx, float dy, float dz);

	void PrintInfo();
	
	void AddComponent(Component* component);
	void RemoveComponent(Component* component);

	// OnCollisionEnter2D / OnCollisionExit2D
	virtual void OnComponentBeginOverlap(Collider* collider, Collider* other);
	virtual void OnComponentEndOverlap(Collider* collider, Collider* other);


	//�ӽÿ�
	glm::vec3 GetCenter() { return _center; }
	glm::vec3 GetSize() { return _size; }

	void SetCenter(glm::vec3 temp) { _center = temp; }
	void SetCenter_x(float x) { _center.x = x; }
	void SetCenter_y(float y) { _center.y = y; }
	void SetCenter_z(float z) { _center.z = z; }

	float GetCenter_x() { return _center.x; }
	float GetCenter_y() { return _center.y; }
	float GetCenter_z() { return _center.z; }

	float GetFirstCenter_x() { return _first_center.x; }
	float GetFirstCenter_y() { return _first_center.y; }
	float GetFirstCenter_z() { return _first_center.z; }
protected:

	glm::vec3 _first_center{};

	vector<Component*> v_component;
	bool test=false;
	Model* _model{};
	glm::vec3 _center{};
	glm::vec3 _size{};


public:
	glm::vec3 _debug_color = { 1,0,0 };
};


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
	glm::mat4 GetScale(float dx,float dy, float dz); // 크기조절 자동화(mat4 뱉어줌 행렬식 조합해서 사용할떄 사용)
	glm::mat4 GetTransPose(float dx, float dy, float dz); // 크기조절 자동화(mat4 뱉어줌 행렬식 조합해서 사용할떄 사용)


	void SetSimple(Shader& shader);
	void SetRotate(Shader& shader,float radian, float x, float y, float z);// 자전 자동화 ( 한번에설정)
	void SetScale(Shader& shader ,float dx, float dy, float dz); // 크기조절 자동화 (한번에 설정)
	void SetTransPose(Shader& shader, float dx, float dy, float dz);

	void PrintInfo();
	

	//임시용
	void SetCenter(glm::vec3 temp) { _center = temp; }

protected:

	bool test=false;

	Model* _model{};
	glm::vec3 _center{};
	glm::vec3 _size{};


};


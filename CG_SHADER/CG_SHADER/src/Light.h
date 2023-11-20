#pragma once



class Light
{
public:
	Light();
	~Light();

	void SetLvector(glm::vec3 lvector);
	void SetAmbientIntensity(float ambientIntensity);
	void SetDiffuseIntensity(float diffuseIntensity);

	void SetSpecularIntensity(float specularIntensity);
	void SetShinIness(float shinelness);
	void SetLightColor(glm::vec3 lightcolor);
	void UseLight(Shader& shader);

private:


	glm::vec3 _lightColor;
	glm::vec3 _lvector; // max((n*l),0)*sd*md ������ l

	float _ambientIntensity; // �ں��Ʈ ���� 
	float _diffuseIntensity; //  ���� 

	float _specularIntensity; //����ŧ�� ����
	float _shinIness; //��¦�� ���
};
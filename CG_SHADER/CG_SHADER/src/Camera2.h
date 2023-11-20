#pragma once


class Camera2
{

public:

	static Camera2* GetInstance()
	{
		static Camera2 MM;
		return &MM;
	}


	void KeyUpdate();
	void MouseUpdate(float x, float y);

	glm::mat4 GetMatrix();


	bool m_cameraControl{ true };
	glm::vec2 m_prevMousePos{ glm::vec2(0.0f) };
private:



	
	float m_cameraPitch{ 0.0f };
	float m_cameraYaw{ 0.0f };

	glm::vec3 m_cameraPos{ glm::vec3(0.0f,0.0f,3.0f) };
	glm::vec3 m_cameraFront{ glm::vec3(0.0f,0.0f,-1.0f) };
	glm::vec3 m_cameraUp{ glm::vec3(0.0f,1.0f,0.0f) };




};


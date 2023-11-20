#pragma once


class Camera2
{

public:

	void KeyUpdate();


	glm::mat4 GetMatrix();

private:


	glm::vec3 m_cameraPos{ glm::vec3(0.0f,0.0f,3.0f) };
	glm::vec3 m_cameraFront{ glm::vec3(0.0f,0.0f,-1.0f) };
	glm::vec3 m_cameraUp{ glm::vec3(0.0f,1.0f,0.0f) };


};


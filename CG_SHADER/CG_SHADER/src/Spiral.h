#pragma once

class Spiral
{


public:
	

	void Init();
	void Update();
	void Render();




private:
	float degreesToRadians(float degrees)
	{
		return degrees * (pi / 180.0);
	}
	const float pi = 3.14159265356f;
	float radian = 0.0f; // 각도
	float radius = 0.1f; // 반지름

	VAO m_vao;
	VBO m_vbo;

};


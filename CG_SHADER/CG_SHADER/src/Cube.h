#pragma once
class Cube
{

public:

	Cube();
	~Cube();

	void Init(vec3 center, float size);
	void Update();
	void Render();


protected:

	vec3 m_center{}; // center pos 
	float m_size{}; // 사이즈 값 


	VAO m_vao;
	VBO m_vbo; 
	VBO m_vbo2;
	IBO m_ibo;




};


#pragma once
class p14
{

public:

	p14();
	~p14();

	void Init(vec3 center, float size);
	void Update();
	void Render();


protected:

	vec3 m_center{}; // center pos 
	float m_size{}; // ������ �� 

	VAO m_vao;
	VBO m_vbo;
	VBO m_vbo2;
	IBO m_ibo;

	int m_counting = 0;


};


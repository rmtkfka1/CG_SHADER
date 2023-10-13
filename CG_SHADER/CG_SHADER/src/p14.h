#pragma once
class p14
{

public:

	p14();
	~p14();

	void Init(vec3 center, float size);
	void Update();
	void Render();

	void SetDraw(bool what) { m_draw = what; }

private:

	vec3 m_center{}; // center pos 
	float m_size{}; // ������ �� 

	VAO m_vao;
	VBO m_vbo;
	IBO m_ibo;

	int m_counting = 0;
	bool m_draw = false;


};


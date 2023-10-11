#pragma once
class p14_4
{

public:

	p14_4();
	~p14_4();

	void Init();
	void Update();
	void Render();

	void SetDraw(bool what) { m_draw = what; }

private:



	VAO m_vao;
	VBO m_vbo;
	VBO m_vbo2;
	IBO m_ibo;

	int m_counting = 0;
	bool m_draw = false;
};


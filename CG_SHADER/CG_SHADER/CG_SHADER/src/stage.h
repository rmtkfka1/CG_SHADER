#pragma once
class stage
{

public:

	void Init();
	void Update();
	void Render();



private:
	VAO m_vao;
	VBO m_vbo;
	IBO m_ibo;
};


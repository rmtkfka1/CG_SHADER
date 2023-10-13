#pragma once

class Line
{


public:

	Line();
	~Line();

	void Init();
	void Render();



protected:

	

	VAO m_vao;
	VBO m_vbo;
	VBO m_vbo2;
	IBO m_ibo;


};


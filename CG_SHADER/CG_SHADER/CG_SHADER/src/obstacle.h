#pragma once
class obstacle
{

public:

	void Init();
	void Update();
	void Render();

	float x = 0;
	float y = 0;
	float z = 0;
	float m_size = 0.3f;


private:

	VAO vao;
	VBO vbo;
	IBO ibo;



};


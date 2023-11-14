#pragma once
class front
{


public:
	void Init();
	void Update();
	void Render();



	bool left;

private:
	VAO vao;
	VBO vbo;
	IBO ibo;
};


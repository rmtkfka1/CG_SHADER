#pragma once


enum class Shape
{
	body,
	arm,
	leg,
	head,
	nose
};



class robot
{


public:

	void Init();
	void Update();
	void Render();

	Shape shape;
	float x, y, z;

private:

	VAO vao;
	VBO vbo;
	IBO ibo;




};


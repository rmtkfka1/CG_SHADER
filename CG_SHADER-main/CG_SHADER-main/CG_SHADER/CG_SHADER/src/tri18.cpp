#include "pch.h"
#include "tri18.h"

void tri18::Init()
{

	_vao.Gen();

	float vertex[] =
	{
		0,10.0f,0  , 1.0f,0,0, //0
		-5.0f,0,0   ,0,1.0f,0, //1
		5.0f,0,0   ,0,0,1.0f   //2
	};

	VertexBufferLayout layout;

	_vbo.Gen(vertex, sizeof(vertex));
	layout.Push<float>(3);
	layout.Push<float>(3);

	_vao.AddBuffer(_vbo, layout);

	unsigned int index[] =
	{
		0,1,2,
	};

	_ibo.Gen(index, 3);


}

void tri18::Update()
{
}

void tri18::Render()
{
	_vao.Bind();
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
}

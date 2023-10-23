#include "pch.h"
#include "Bottom.h"

void Bottom::Init()
{

	float vertex[] =
	{
		-70.0f,0,-70.0f, 0,0.5f,0.9f,
		-70.0f,0,70.0f,  0,1.0f,0.9f,
		 70.0f,0,70.0f,  0,0.3f,0.9f,
		 70.0f,0,-70.0f, 0,0.4f,0.9f,
	};

	unsigned int index[] =
	{
		0,1,2,
		0,2,3
	};


	VertexBufferLayout layout;

	vao.Gen();
	vbo.Gen(vertex, sizeof(vertex));

	layout.Push<float>(3);
	layout.Push<float>(3);

	vao.AddBuffer(vbo, layout);

	ibo.Gen(index, 6);

}

void Bottom::Update()
{
}

void Bottom::Render()
{
	vao.Bind();
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

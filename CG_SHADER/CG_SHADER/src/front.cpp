#include "pch.h"
#include "front.h"

void front::Init()
{

	if (left)
	{
		float vertex[] =
		{
			-2.0f,2.0f,0, 1.0f,0,0,
			-2.0f,-2.0f,0, 1.0f,0,0,
			0.0f,-2.0f,0, 1.0f,0,0,
			0.0f,2.0f,0, 1.0f,0,0
		};

		unsigned int indice[] =
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
		ibo.Gen(indice, 6);

	}


	else
	{
		float vertex[] =
		{
			0.0f,2.0f,0, 1.0f,0,0,
			0.0f,-2.0f,0, 1.0f,0,0,
			2.0f,-2.0f,0, 1.0f,0,0,
			2.0f,2.0f,0, 1.0f,0,0
		};

		unsigned int indice[] =
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
		ibo.Gen(indice, 6);








	}


}

void front::Update()
{


}

void front::Render()
{
	vao.Bind();

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

}

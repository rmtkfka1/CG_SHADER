#include "pch.h"
#include "obstacle.h"

void obstacle::Init()
{

	VertexBufferLayout layout;



	float vertex[] =
	{
		-m_size , +m_size/3,  -m_size ,   0.5f, 0.5f, 0.5f, //0
		-m_size , +m_size/3,  +m_size ,   0.5f, 0.5f, 0.5f, //0
		+m_size , +m_size/3,  +m_size ,   0.5f, 0.5f, 0.5f, //0
		+m_size  , +m_size/3,  -m_size ,  0.5f, 0.5f, 0.5f, //0
		-m_size , -m_size/3,  -m_size , 0.5f, 0.5f, 0.5f, //0
		-m_size , -m_size/3,  +m_size ,  0.5f, 0.5f, 0.5f, //0
		+m_size , -m_size/3,  +m_size ,  0.5f, 0.5f, 0.5f, //0
		+m_size , -m_size/3,  -m_size ,  0.5f, 0.5f, 0.5f, //0
	};

	unsigned int indices[] =
	{
		//À­¸é
		0, 1, 2,
		0, 2, 3,

		//¹Ø¸é
		4, 6, 5,
		4, 7, 6,

		//µÞ¸é
		0, 3, 7,
		0, 7, 4,

		//¾Õ¸é
		1, 5, 6,
		1, 6, 2,

		//¿Þ¸é
		0, 1, 5,
		0, 5, 4,

		//¿À¸¥¸é
		2, 6, 7,
		2, 7, 3,
	};

	vao.Gen();
	vbo.Gen(vertex, sizeof(vertex));
	layout.Push<float>(3);
	layout.Push<float>(3);
	vao.AddBuffer(vbo, layout);
	ibo.Gen(indices, 36);
}

void obstacle::Update()
{
}

void obstacle::Render()
{
	vao.Bind();
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}

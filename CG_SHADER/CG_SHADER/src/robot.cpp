#include "pch.h"
#include "robot.h"

void robot::Init()
{




	VertexBufferLayout layout;

	if (shape == Shape::body)
	{
		float m_size = 0.2f;

		float vertex[] =
		{
			-m_size / 2, +m_size,  -m_size/2,   0.0f, 0.0f, 1.0f, //0
			-m_size / 2, +m_size,  +m_size/2,   0.0f, 0.0f, 1.0f,  //1
			+m_size / 2, +m_size,  +m_size/2,  0.0f, 0.0f, 1.0f, //2
			+m_size / 2, +m_size,  -m_size/2,  0.0f, 0.0f, 1.0f,  //3
			-m_size / 2, -m_size,  -m_size/2,  0.0f, 0.0f, 1.0f,
			-m_size / 2, -m_size,  +m_size/2,  0.0f, 0.0f, 1.0f, //5
			+m_size / 2, -m_size,  +m_size/2,  0.0f, 0.0f, 1.0f, //6
			+m_size / 2, -m_size,  -m_size/2,  0.0f, 0.0f, 1.0f,
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


	if (shape == Shape::arm)
	{

		float m_size = 0.1f;

		float vertex[] =
		{
			-m_size / 5, +m_size,  -m_size/5,   0.0f, 1.0f, 0.0f, //0
			-m_size / 5, +m_size,  +m_size/5,   0.0f, 1.0f, 0.0f,  //1
			+m_size / 5, +m_size,  +m_size/5,  0.0f, 1.0f, 0.0f, //2
			+m_size / 5, +m_size,  -m_size/5,  0.0f, 1.0f, 0.0f,  //3
			-m_size / 5, -m_size,  -m_size/5,  0.0f, 1.0f, 0.0f,
			-m_size / 5, -m_size,  +m_size/5,  0.0f, 1.0f, 0.0f, //5
			+m_size / 5, -m_size,  +m_size/5,  0.0f, 1.0f, 0.0f, //6
			+m_size / 5, -m_size,  -m_size/5,  0.0f, 1.0f, 0.0f,
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

	if (shape == Shape::leg)
	{

		float m_size = 0.1f;

		float vertex[] =
		{
			-m_size / 5, +m_size,  -m_size/5,   0.0f, 1.0f, 0.0f, //0
			-m_size / 5, +m_size,  +m_size/5,   0.0f, 1.0f, 0.0f,  //1
			+m_size / 5, +m_size,  +m_size/5,  0.0f, 1.0f, 0.0f, //2
			+m_size / 5, +m_size,  -m_size/5,  0.0f, 1.0f, 0.0f,  //3
			-m_size / 5, -m_size,  -m_size/5,  0.0f, 1.0f, 0.0f,
			-m_size / 5, -m_size,  +m_size/5,  0.0f, 1.0f, 0.0f, //5
			+m_size / 5, -m_size,  +m_size/5,  0.0f, 1.0f, 0.0f, //6
			+m_size / 5, -m_size,  -m_size/5,  0.0f, 1.0f, 0.0f,
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


	if (shape == Shape::head)
	{

		float m_size = 0.05f;

		float vertex[] =
		{
			-m_size , +m_size,  -m_size,  1.0f, 1.0f, 0.0f, //0
			-m_size , +m_size,  +m_size,  1.0f, 1.0f, 0.0f,  //1
			+m_size , +m_size,  +m_size,  1.0f, 1.0f, 0.0f, //2
			+m_size , +m_size,  -m_size,  1.0f, 1.0f, 0.0f,  //3
			-m_size , -m_size,  -m_size,  1.0f, 1.0f, 0.0f,
			-m_size , -m_size,  +m_size,  1.0f, 1.0f, 0.0f, //5
			+m_size , -m_size,  +m_size,  1.0f, 1.0f, 0.0f, //6
			+m_size , -m_size,  -m_size,  1.0f, 1.0f, 0.0f,
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

	if (shape == Shape::nose)
	{

		float m_size = 0.03f;

		float vertex[] =
		{
			-m_size , +m_size,  -m_size,  0.0f, 0.0f, 0.0f, //0
			-m_size , +m_size,  +m_size,  0.0f, 0.0f, 0.0f,  //1
			+m_size , +m_size,  +m_size,  0.0f, 0.0f, 0.0f, //2
			+m_size , +m_size,  -m_size,  0.0f, 0.0f, 0.0f,  //3
			-m_size , -m_size,  -m_size,  0.0f, 0.0f, 0.0f,
			-m_size , -m_size,  +m_size,  0.0f, 0.0f, 0.0f, //5
			+m_size , -m_size,  +m_size,  0.0f, 0.0f, 0.0f, //6
			+m_size , -m_size,  -m_size,  0.0f, 0.0f, 0.0f,
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




};

void robot::Update()
{
}

void robot::Render()
{
	vao.Bind();
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}

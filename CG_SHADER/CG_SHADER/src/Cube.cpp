#include "pch.h"
#include "Cube.h"



Cube::Cube()
{

}

Cube::~Cube()
{
}

void Cube::Init(vec3 center, float size , int mode )
{


	m_center = center;
	m_size = size;
	m_mode = mode;

	VertexBufferLayout layout;

	float vertex[] =
	{
	 m_center.x - m_size,  m_center.y + m_size,   m_center.z - m_size, 1.0f, 0.0f, 0.0f,
	 // Á¤Á¡ 1
	 m_center.x - m_size,  m_center.y + m_size,   m_center.z + m_size, 0.0f, 1.0f, 0.0f,
	 // Á¤Á¡ 2
	 m_center.x + m_size,  m_center.y + m_size,    m_center.z + m_size,  0.0f, 0.0f, 1.0f,
	 // Á¤Á¡ 3
	 m_center.x + m_size,  m_center.y + m_size,    m_center.z - m_size,  1.0f, 0.5f, 0.0f,
	 // Á¤Á¡ 4


	 m_center.x - m_size,  m_center.y - m_size,    m_center.z - m_size,  0.5f, 0.5f, 1.0f,
	 // Á¤Á¡ 5
	 m_center.x - m_size,  m_center.y - m_size,    m_center.z + m_size,  1.0f, 1.0f, 0.5f,
	 // Á¤Á¡ 6
	 m_center.x + m_size,  m_center.y - m_size,    m_center.z + m_size,  0.5f, 1.0f, 1.0f,
	 // Á¤Á¡ 7
	 m_center.x + m_size,  m_center.y - m_size,    m_center.z - m_size,  0.2f, 0.7f, 0.2f,
	};


	if (mode == 0)
	{
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

		m_vao.Gen();
		m_vbo.Gen(vertex, sizeof(vertex));
		layout.Push<float>(3);
		layout.Push<float>(3);
		m_vao.AddBuffer(m_vbo, layout);
		m_ibo.Gen(indices, 36);


	}

	else if (mode == 1)
	{
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

				1,2,
				0,4,
				5,6
			};

			m_vao.Gen();
			m_vbo.Gen(vertex, sizeof(vertex));
			layout.Push<float>(3);
			layout.Push<float>(3);
			m_vao.AddBuffer(m_vbo, layout);
			m_ibo.Gen(indices, 42);

	}

	

}

void Cube::Update()
{


	

}

void Cube::Render()
{
	m_vao.Bind();
	if(m_mode==0)
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
	
	if (m_mode == 1)
	glDrawElements(GL_LINES, 42, GL_UNSIGNED_INT, 0);
}

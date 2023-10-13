#include "pch.h"
#include "Pyramid.h"

Pyramid::Pyramid()
{
}

Pyramid::~Pyramid()
{
}

void Pyramid::Init(vec3 center, float size, int mode)
{
	m_center = center;
	m_size = size;
	m_mode = mode;

	VertexBufferLayout layout;

	float vertex[] =
	{
	
	 m_center.x , m_center.y +m_size+0.1f , m_center.z , 0.5f,1.0f,0,

	 m_center.x - m_size,  m_center.y - m_size,    m_center.z - m_size,  0.5f, 0.5f, 1.0f,
	 // 정점 5
	 m_center.x - m_size,  m_center.y - m_size,    m_center.z + m_size,  1.0f, 1.0f, 0.5f,
	 // 정점 6
	 m_center.x + m_size,  m_center.y - m_size,    m_center.z + m_size,  0.5f, 1.0f, 1.0f,
	 // 정점 7
	 m_center.x + m_size,  m_center.y - m_size,    m_center.z - m_size,  0.2f, 0.7f, 0.2f,
	};


	if (mode == 0)
	{
		unsigned int indices[] =
		{
			0,1,2,
			0,2,3,
			0,3,4,
			0,4,1
		};

		m_vao.Gen();
		m_vbo.Gen(vertex, sizeof(vertex));
		layout.Push<float>(3);
		layout.Push<float>(3);
		m_vao.AddBuffer(m_vbo, layout);
		m_ibo.Gen(indices, 12);


	}

	else if (mode == 1)
	{
		unsigned int indices[] =
		{
			0,1,
			0,2,
			1,2,

			0,2,
			0,3,
			2,3,

			0,3,
			0,4,
			3,4,

			0,1,
			0,4,
			1,4
		};

		m_vao.Gen();
		m_vbo.Gen(vertex, sizeof(vertex));
		layout.Push<float>(3);
		layout.Push<float>(3);
		m_vao.AddBuffer(m_vbo, layout);
		m_ibo.Gen(indices, 24);


	}

}

void Pyramid::Update()
{
}

void Pyramid::Render()
{
	m_vao.Bind();

	if (m_mode == 0)
		glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, 0);

	if (m_mode == 1)
		glDrawElements(GL_LINES, 24, GL_UNSIGNED_INT, 0);
}

#include "pch.h"
#include "stage.h"

void stage::Init()
{


	vec3 m_center = { 0,0,0 };
	float m_size = 2.0f;

	VertexBufferLayout layout;

	float vertex[] =
	{
	 m_center.x - m_size,  m_center.y + m_size,   m_center.z - m_size,   0.5f, 0.0f, 0.0f,
	 m_center.x - m_size,  m_center.y + m_size,   m_center.z + m_size,   0.0f, 0.3f, 0.0f,
	 m_center.x + m_size,  m_center.y + m_size,    m_center.z + m_size,  0.5f, 0.0f, 0.0f,
	 m_center.x + m_size,  m_center.y + m_size,    m_center.z - m_size,  1.0f, 0.0f, 0.0f,
	 m_center.x - m_size,  m_center.y - m_size,    m_center.z - m_size,  0.3f, 0.3f, 0.5f,
	 m_center.x - m_size,  m_center.y - m_size,    m_center.z + m_size,  1.0f, 0.3f, 0.5f,
	 m_center.x + m_size,  m_center.y - m_size,    m_center.z + m_size,  1.0f, 0.3f, 0.3f,
	 m_center.x + m_size,  m_center.y - m_size,    m_center.z - m_size,  0.3f, 0.3f, 0.3f,
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
	m_ibo.Gen(indices, 30);










};

void stage::Update()
{
}

void stage::Render()
{
	m_vao.Bind();
	glDrawElements(GL_TRIANGLES, 30, GL_UNSIGNED_INT, 0);
}

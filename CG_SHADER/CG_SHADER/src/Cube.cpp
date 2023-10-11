#include "pch.h"
#include "Cube.h"



Cube::Cube()
{

}

Cube::~Cube()
{
}

void Cube::Init(vec3 center, float size)
{
	m_center = center;
	m_size = size;

	float vertex[] =
	{
	 m_center.x - m_size,  m_center.y + m_size,   m_center.z - m_size, 1.0f, 0.0f, 0.0f,
	 // 정점 1
	 m_center.x - m_size,  m_center.y + m_size,   m_center.z + m_size, 0.0f, 1.0f, 0.0f,
	 // 정점 2
	 m_center.x + m_size,  m_center.y + m_size,    m_center.z + m_size,  0.0f, 0.0f, 1.0f,
	 // 정점 3
	 m_center.x + m_size,  m_center.y + m_size,    m_center.z - m_size,  1.0f, 0.5f, 0.0f,
	 // 정점 4


	 m_center.x - m_size,  m_center.y - m_size,    m_center.z - m_size,  0.5f, 0.5f, 1.0f,
	 // 정점 5
	 m_center.x - m_size,  m_center.y - m_size,    m_center.z + m_size,  1.0f, 1.0f, 0.5f,
	 // 정점 6
	 m_center.x + m_size,  m_center.y - m_size,    m_center.z + m_size,  0.5f, 1.0f, 1.0f,
	 // 정점 7
	 m_center.x + m_size,  m_center.y - m_size,    m_center.z - m_size,  0.2f, 0.7f, 0.2f,
	};



	unsigned int indices[] =
	{
		//윗면
		0, 1, 2,
		0, 2, 3,

		//밑면
		4, 6, 5,
		4, 7, 6,

		//뒷면
		0, 3, 7,
		0, 7, 4,

		//앞면
		1, 5, 6,
		1, 6, 2,

		//왼면
		0, 1, 5,
		0, 5, 4,

		//오른면
		2, 6, 7,
		2, 7, 3,
	};


	VertexBufferLayout layout;

	m_vao.Gen();
	m_vbo.Gen(vertex, sizeof(vertex));
	layout.Push<float>(3);
	layout.Push<float>(3);
	m_vao.AddBuffer(m_vbo, layout);
	m_ibo.Gen(indices,36);

}

void Cube::Update()
{


	

}

void Cube::Render()
{
	m_vao.Bind();
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0); 
	//glDrawArrays(GL_TRIANGLES, 0, 3);

}

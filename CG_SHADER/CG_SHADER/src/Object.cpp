#include "pch.h"
#include "Object.h"

Object::Object()
{
	m_center = { 0,0 };
	m_size = 0.5f;
}

Object::~Object()
{




}

void Object::Init()
{
	m_position = new float[9];

	float position[9] =
	{
		m_center.x, m_center.y + m_size , 0,
		m_center.x- m_size , m_center.y-m_size,0,
		m_center.x+m_size, m_center.y-m_size,0
	};

	float color[9]
	{
		1.0f,0,0,
		1.0f,0,0,
		1.0f,0,0
	};

	memcpy(m_position, position, 9 * sizeof(float));

	m_vao.Gen();
	m_vbo.Gen(m_position,9*sizeof(float));
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
	glEnableVertexAttribArray(0);

	m_vbo2.Gen(color,9*sizeof(float));
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
	glEnableVertexAttribArray(1);

}

void Object::Update()
{

	if (KeyManager::GetInstance()->Getbutton('d'))
	{
		m_position[0] += 0.001f;
		m_position[3] += 0.001f;
		m_position[6] += 0.001f;


		m_vao.Bind();
		m_vbo.Gen(m_position, 9 * sizeof(float));
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
		glEnableVertexAttribArray(0);

	}

}


void Object::Render()
{
	glDrawArrays(GL_TRIANGLES, 0, 3);
}







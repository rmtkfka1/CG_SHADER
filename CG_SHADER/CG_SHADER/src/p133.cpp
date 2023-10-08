#include "pch.h"
#include "p133.h"

p133::p133()
{
}

p133::~p133()
{

}

void p133::Init()
{
	m_center = { 0,0 };
	m_size = { 0.4f,0.2f };

	m_position = new float[24];

	float position[] =
	{
		m_center.x - m_size.x ,  m_center.y + m_size.y , 0 , //0
		m_center.x - m_size.x ,  m_center.y - m_size.y , 0 , //1
		m_center.x - m_size.x ,  m_center.y - m_size.y , 0 , //2
		m_center.x + m_size.x ,  m_center.y - m_size.y , 0 , //3
		m_center.x + m_size.x ,  m_center.y - m_size.y , 0 , //4
		m_center.x + m_size.x ,  m_center.y + m_size.y , 0 , //5
		m_center.x + m_size.x ,  m_center.y + m_size.y , 0 , //6
		m_center.x - m_size.x ,  m_center.y + m_size.y , 0 , //7
	};

	float color[9]
	{
		1.0f,0,0,
		1.0f,0,0,
		1.0f,0,0
	};

	memcpy(m_position, position, 24 * sizeof(float));

	m_vao.Gen();
	m_vbo.Gen(m_position, 24 * sizeof(float));
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
	glEnableVertexAttribArray(0);

	m_vbo2.Gen(color, 9 * sizeof(float));
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
	glEnableVertexAttribArray(1);

}

void p133::Update()
{
	if (MouseManager::GetInstance()->Getboolclick()) 
	{ 

		diff = MouseManager::GetInstance()->Getdiff();

		m_position[0] += diff.x;
		m_position[3] += diff.x;
		m_position[6] += diff.x;
		m_position[9] += diff.x;
		m_position[12] += diff.x;
		m_position[15] += diff.x;
		m_position[18] += diff.x;
		m_position[21] += diff.x;

		m_position[1] += diff.y;
		m_position[4] += diff.y;
		m_position[7] += diff.y;
		m_position[10] += diff.y;
		m_position[13] += diff.y;
		m_position[16] += diff.y;
		m_position[19] += diff.y;
		m_position[22] += diff.y;

		

		m_vao.Gen();
		m_vbo.Gen(m_position, 24 * sizeof(float));
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
		glEnableVertexAttribArray(0);

		
	}
}

void p133::Render()
{

	m_vao.Bind();
	glDrawArrays(GL_LINES, 0, 8);
}

int p133::checkbox()
{
	return 0;
}

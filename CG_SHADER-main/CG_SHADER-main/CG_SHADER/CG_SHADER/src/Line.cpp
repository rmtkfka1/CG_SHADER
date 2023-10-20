#include "pch.h"
#include "Line.h"

Line::Line()
{

	


};

Line::~Line()
{

}

void Line::Init()
{
	VertexBufferLayout layout;

	float position[] =
	{
		-50.0f,0,0, //x��
		50.0f,0,0,

		0,50.0f,0,
		0,-50.0f,0,

		0,0,50.0f,
		0,0,-50.0f
	};

	float color[]
	{
		1.0f,0,0,
		1.0f,0,0,
		0.0f,1.0f,0,
		0.0f,1.0f,0,
		0.0f,0,1.0f,
		0.0f,0,1.0f
	};


	m_vao.Gen();
	m_vbo.Gen(position, sizeof(position));
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
	glEnableVertexAttribArray(0);

	m_vbo2.Gen(color, sizeof(color));
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
	glEnableVertexAttribArray(1);
}

void Line::Render()
{


	m_vao.Bind();
	glDrawArrays(GL_LINES, 0,6);

}

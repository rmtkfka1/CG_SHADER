#include "pch.h"
#include "Spiral.h"

void Spiral::Init()
{


	float positions[180];

	vec3 converse;

	for (int i = 0; i < 180; ++i)
	{

		converse.x = 0 + radius * cos(degreesToRadians(radian));
		converse.y = 0 + radius * sin(degreesToRadians(radian));
		converse.z = 0;

		if (i % 3 == 0)
		{
			positions[i] = converse.x;
		}
		else if (i % 3 == 1)
		{
			positions[i] = converse.y;
		}

		else if (i % 3 == 2)
		{
			positions[i] = converse.z;
		}

		radius += 0.007f;
		radian += 10.0f;
	}

	m_vao.Gen();
	m_vbo.Gen(positions, sizeof(positions));

	VertexBufferLayout layout;
	layout.Push<float>(3);
	m_vao.AddBuffer(m_vbo, layout);
	m_vao.Bind();





}

void Spiral::Update()
{
}

void Spiral::Render()
{
	m_vao.Bind();
	glDrawArrays(GL_LINE_STRIP, 0, 60);
}

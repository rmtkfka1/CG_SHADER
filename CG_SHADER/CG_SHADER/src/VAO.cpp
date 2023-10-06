#include "pch.h"
#include "VAO.h"


VAO::VAO()
{
}

VAO::~VAO()
{
	GLCall(glDeleteVertexArrays(1, &m_RendererID));

}

void VAO::Gen()
{
	if (!m_RendererID)
	{
		GLCall(glGenVertexArrays(1, &m_RendererID)); //vao »ý¼º
	}
	glBindVertexArray(m_RendererID);
}

void VAO::Bind() const
{

	GLCall(glBindVertexArray(m_RendererID));
}

void VAO::Unbind() const
{
	GLCall(glBindVertexArray(0));
}

void VAO::Delete() const
{
	Unbind();
	GLCall(glDeleteVertexArrays(1, &m_RendererID));

}

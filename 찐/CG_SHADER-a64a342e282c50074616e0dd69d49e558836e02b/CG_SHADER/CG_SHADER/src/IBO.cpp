#include "pch.h"
#include "IBO.h"




IBO::IBO(const unsigned int* data, unsigned int count)
	: m_Count{ count }
{
	ASSERT(sizeof(unsigned int) == sizeof(GLuint));
	GLCall(glGenBuffers(1, &m_RendererID)); //1. ���� ����
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID)); //2. ���ε�("�۾� ����")
	GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW));  //3. �۾� ���� ���ۿ� ������ ����
}

IBO::~IBO()
{
	GLCall(glDeleteBuffers(1, &m_RendererID));
}



void IBO::Bind() const
{
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID)); //���ε�("�۾� ����")
}

void IBO::Unbind() const
{
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0)); //����ε�
}

void IBO::Delete() const
{
	GLCall(glDeleteBuffers(1, &m_RendererID));
}


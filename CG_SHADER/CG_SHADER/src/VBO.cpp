#include "pch.h"
#include "VBO.h"



VBO::VBO(const void* data, unsigned int size)
{
	
	GLCall(glGenBuffers(1, &m_RendererID)); //1. ���� ����
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID)); //2. ���ε�("�۾� ����")
	GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW));  //3. �۾� ���� ���ۿ� ������ ����
}

VBO::~VBO()
{
	GLCall(glDeleteBuffers(1, &m_RendererID));
}



void VBO::Bind() const
{
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_RendererID)); //���ε�("�۾� ����")
}

void VBO::Unbind() const
{
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0)); //����ε�
}

void VBO::Delete() const
{
	GLCall(glDeleteBuffers(1, &m_RendererID));
}

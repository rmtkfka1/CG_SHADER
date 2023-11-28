#include "pch.h"
#include "VAO.h"
#include "VBO.h"
#include "VertexBufferLayout.h"
VAO::VAO()
{
	GLCall(glGenVertexArrays(1, &m_RendererID)); //vao ����
}

VAO::~VAO()
{
	GLCall(glDeleteVertexArrays(1, &m_RendererID));

}



void VAO::AddBuffer(const VBO& vb, const VertexBufferLayout& layout)
{

	this->Bind(); //vao�� ���ε�

	vb.Bind(); //Vertex Buffer�� ���ε�

	const auto& elements = layout.GetVector();

	unsigned int offset = 0;
	for (int i = 0; i < elements.size(); i++)
	{
		const auto& element = elements[i];
		GLCall(glEnableVertexAttribArray(i)); //�������� 0���� ����������, position/normal/color�� ���� attribute�� �����, ���� attribute�� enable�ؾ���
		GLCall(glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.GetStride(), (const void*)offset)); //layout���� �����͸� ��� �о�;��ϴ����� element����ü�� ������ ���� ����. �̸� Ȱ����.
		offset += element.count * VertexBufferElement::GetSizeOfType(element.type);


	}

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

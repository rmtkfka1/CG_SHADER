#include "pch.h"
#include "Renderer.h"


void Renderer::Draw(const VAO& va, const IBO& ib, const Shader& shader) const
{
	//�׸��� ���� ������ �׸��� ���ε�
	shader.Bind();
	va.Bind();
	ib.Bind();

	//�׸���
	GLCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));
}

void Renderer::Clear() const
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

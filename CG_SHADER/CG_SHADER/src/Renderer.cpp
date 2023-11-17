#include "pch.h"
#include "Renderer.h"


void Renderer::Draw(const VAO& va, const IBO& ib, const Shader& shader) const
{
	//그리기 전에 무엇을 그릴지 바인딩
	shader.Bind();
	va.Bind();
	ib.Bind();

	//그리기
	GLCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));
}

void Renderer::Clear() const
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

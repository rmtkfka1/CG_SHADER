#include "pch.h"
#include "rect18.h"

void rect18::Init()
{

	_vao.Gen();

	float vertex[] =
	{
		-5.0f,5.0f,0,    1.0f,0,0,  //0
		-5.0f,-5.0f,0,   0,1.0f,0,  // 1
		5.0f,-5.0f,0,    0,0.5f,1.0f,  //2
		5.0f,5.0f,0,   0.5f,0.5f,0.2f  //3
	};

	VertexBufferLayout layout;

	_vbo.Gen(vertex, sizeof(vertex));
	layout.Push<float>(3);
	layout.Push<float>(3);

	_vao.AddBuffer(_vbo, layout);

	unsigned int index[] =
	{
		0,1,2,
		0,2,3
	};

	_ibo.Gen(index, 6);

}

void rect18::Update()
{



}

void rect18::Render()
{
	_vao.Bind();
	glDrawElements(GL_TRIANGLES,6, GL_UNSIGNED_INT, 0);
}

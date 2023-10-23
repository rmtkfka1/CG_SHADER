#include "pch.h"
#include "Body.h"

void Body::Init()
{



	float vertex[] =
	{
		-5.0f,2.0f,-5.0f,   0.0f, 0.4f, 0.4f,
		-5.0f,2.0f, 5.0f, 	0.0f, 0, 0.0f,
		5.0f,2.0f,5.0f,   	0.0f, 0.3f, 0.0f,
		5.0f,2.0f,-5.0f,  	1.0f, 0.0f, 0.0f,

		//¹ØÅë
		-5.0f,-2.0f,-5.0f,	0.0f, 0.0f, 1.0f,
		-5.0f,-2.0f, 5.0f,	1.0f, 1.0f, 0.5f,
		5.0f,-2.0f, 5.0f,  	0.5f, 1.0f, 1.0f,
		5.0f,-2.0f,-5.0f, 	0.2f, 0.7f, 0.2f,
	};

	unsigned int index[] =
	{
		//À­¸é
		0, 1, 2,
		0, 2, 3,

		//¹Ø¸é
		4, 6, 5,
		4, 7, 6,

		//µÞ¸é
		0, 3, 7,
		0, 7, 4,

		//¾Õ¸é
		1, 5, 6,
		1, 6, 2,

		//¿Þ¸é
		1, 0, 5,
		0, 4, 5,

		//¿À¸¥¸é
		2, 6, 7,
		2, 7, 3,

	};

	VertexBufferLayout layout;

	vao.Gen();
	vbo.Gen(vertex, sizeof(vertex));

	layout.Push<float>(3);
	layout.Push<float>(3);

	vao.AddBuffer(vbo, layout);

	ibo.Gen(index,36);


}

void Body::Update()
{





}

void Body::Render()
{
	auto v = ObjectManager::GetInstance()->Get_Shader();

	vao.Bind();
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

}

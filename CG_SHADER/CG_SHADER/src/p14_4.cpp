#include "pch.h"
#include "p14_4.h"

p14_4::p14_4()
{
}

p14_4::~p14_4()
{
}

void p14_4::Init()
{




}

void p14_4::Update()
{

	float vertex[] =
	{
		0,0.5f,0,1.0f,0,0,
		-0.25f,0,-0.25f,0,1.0f,0,
		0,0,0.4f,0.5f,0,0,
		0.4f,0,0,0.2f,0,0
	};

	VertexBufferLayout layout;
	if (KeyManager::GetInstance()->GetbuttonDown('7'))
	{
		unsigned int indices[] =
		{
			0, 1, 2,  // ABC
		};

		m_vao.Gen();
		m_vbo.Gen(vertex, sizeof(vertex));
		layout.Push<float>(3);
		layout.Push<float>(3);
		m_vao.AddBuffer(m_vbo, layout);
		m_ibo.Gen(indices, 3);

		m_counting = 3;
	}

	else if (KeyManager::GetInstance()->GetbuttonDown('8'))
	{
		unsigned int indices[] =
		{
			0, 2, 3,  // ACD
		};

		m_vao.Gen();
		m_vbo.Gen(vertex, sizeof(vertex));
		layout.Push<float>(3);
		layout.Push<float>(3);
		m_vao.AddBuffer(m_vbo, layout);
		m_ibo.Gen(indices, 3);

		m_counting = 3;
	}

	else if (KeyManager::GetInstance()->GetbuttonDown('9'))
	{
		unsigned int indices[] =
		{
			
			1,3,2
		};

		m_vao.Gen();
		m_vbo.Gen(vertex, sizeof(vertex));
		layout.Push<float>(3);
		layout.Push<float>(3);
		m_vao.AddBuffer(m_vbo, layout);
		m_ibo.Gen(indices, 3);

		m_counting = 3;
	}

	else if (KeyManager::GetInstance()->GetbuttonDown('0'))
	{

		unsigned int indices[] =
		{
			0, 1, 2,  // ABC
			0, 2, 3,  // ACD
			0, 3, 1,  // ADB
			1, 3, 2   // BDC
		};

		m_vao.Gen();
		m_vbo.Gen(vertex, sizeof(vertex));
		layout.Push<float>(3);
		layout.Push<float>(3);
		m_vao.AddBuffer(m_vbo, layout);
		m_ibo.Gen(indices, 12);

		m_counting = 12;
	}

	else if (KeyManager::GetInstance()->GetbuttonDown('t'))
	{
		unsigned int indices[] =
		{
			0, 1, 2,  // ABC
			0, 2, 3,  // ACD
			0, 3, 1,  // ADB
			1, 3, 2   // BDC
		};


		vector<vec3> v;
		for (int i = 0; i < 4; ++i)
		{
			vec3 temp;
			temp.x=  static_cast<int>(indices[3*i]);
			temp.y = static_cast<int>(indices[3 * i+1]);
			temp.z = static_cast<int>(indices[3 * i+2]);
			v.push_back(temp);
		}

		srand(time(nullptr));
		int num = rand() % 4; //0 1 2 3
		vec3 temp = v[num];
		v.erase(v.begin() + num);
		int num2 = rand() % 3;//0 1 2 
		vec3 temp2 = v[num2];

		unsigned int indices2[] =
		{
			temp.x,temp.y,temp.z,
			temp2.x,temp2.y,temp2.z,
		};

		m_vao.Gen();
		m_vbo.Gen(vertex, sizeof(vertex));
		layout.Push<float>(3);
		layout.Push<float>(3);
		m_vao.AddBuffer(m_vbo, layout);
		m_ibo.Gen(indices2, 6);

		m_counting = 6;
	}


}

void p14_4::Render()
{

	glDrawElements(GL_TRIANGLES, m_counting, GL_UNSIGNED_INT, 0);

}

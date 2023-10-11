#include "pch.h"
#include "p14.h"
#include "p14_world.h"

p14::p14()
{

}

p14::~p14()
{
}

void p14::Init(vec3 center, float size)
{
	m_center = center;
	m_size = size;

	float vertex[] =
	{
	 m_center.x - m_size,  m_center.y + m_size,   m_center.z - m_size, 1.0f, 0.0f, 0.0f,
	 // 정점 1
	 m_center.x - m_size,  m_center.y + m_size,   m_center.z + m_size, 0.0f, 1.0f, 0.0f,
	 // 정점 2
	 m_center.x + m_size,  m_center.y + size,    m_center.z + size,  0.0f, 0.0f, 1.0f,
	 // 정점 3
	 m_center.x + m_size,  m_center.y + size,    m_center.z - size,  1.0f, 0.5f, 0.0f,
	 // 정점 4
	 m_center.x - m_size,  m_center.y - size,    m_center.z - size,  0.5f, 0.5f, 1.0f,
	 // 정점 5
	 m_center.x - m_size,  m_center.y - size,    m_center.z + size,  1.0f, 1.0f, 0.5f,
	 // 정점 6
	 m_center.x + m_size,  m_center.y - size,    m_center.z + size,  0.5f, 1.0f, 1.0f,
	 // 정점 7
	 m_center.x + m_size,  m_center.y - size,    m_center.z - size,  0.2f, 0.7f, 0.2f,
	};

	unsigned int indices[] =
	{
		0, 1, 2,
		0, 2, 3,
		4, 5, 6,
		4, 6, 7,
		0, 3, 7,
		0, 7, 4,
		1, 5, 6,
		1, 6, 2,
		0, 1, 5,
		0, 5, 4,
		2, 6, 7,
		2, 7, 3,
	};


	VertexBufferLayout layout;

	m_vao.Gen();
	m_vbo.Gen(vertex, sizeof(vertex));
	layout.Push<float>(3);
	layout.Push<float>(3);
	m_vao.AddBuffer(m_vbo, layout);
	m_ibo.Gen(indices, 36);

}

void p14::Update()
{
	auto &t =ObjectManager::GetInstance()->Get_P14_world();

	float vertex[] =
	{
	 m_center.x - m_size,  m_center.y + m_size,   m_center.z - m_size, 1.0f, 0.0f, 0.0f,
	 // 정점 1
	 m_center.x - m_size,  m_center.y + m_size,   m_center.z + m_size, 0.0f, 1.0f, 0.0f,
	 // 정점 2
	 m_center.x + m_size,  m_center.y + m_size,    m_center.z + m_size,  0.0f, 0.0f, 1.0f,
	 // 정점 3
	 m_center.x + m_size,  m_center.y + m_size,    m_center.z - m_size,  1.0f, 0.5f, 0.0f,
	 // 정점 4
	 m_center.x - m_size,  m_center.y - m_size,    m_center.z - m_size,  0.5f, 0.5f, 1.0f,
	 // 정점 5
	 m_center.x - m_size,  m_center.y - m_size,    m_center.z + m_size,  1.0f, 1.0f, 0.5f,
	 // 정점 6
	 m_center.x + m_size,  m_center.y - m_size,    m_center.z + m_size,  0.5f, 1.0f, 1.0f,
	 // 정점 7
	 m_center.x + m_size,  m_center.y - m_size,    m_center.z - m_size,  0.2f, 0.7f, 0.2f,
	};

	VertexBufferLayout layout;


	if (KeyManager::GetInstance()->GetbuttonDown('1'))
	{

		unsigned int indices[] =
		{
			//윗면
			4, 6, 5,
			4, 7, 6,
		};

		m_vao.Gen();
		m_vbo.Gen(vertex, sizeof(vertex));
		layout.Push<float>(3);
		layout.Push<float>(3);
		m_vao.AddBuffer(m_vbo, layout);
		m_ibo.Gen(indices, 6);

		m_counting = 6;
		m_draw = true;
		t[0]->changesakak();
	}

	else if (KeyManager::GetInstance()->GetbuttonDown('2'))
	{

		unsigned int indices[] =
		{
			//윗면
			0, 1, 2,
			0, 2, 3,
		};

		m_vao.Gen();
		m_vbo.Gen(vertex, sizeof(vertex));
		layout.Push<float>(3);
		layout.Push<float>(3);
		m_vao.AddBuffer(m_vbo, layout);
		m_ibo.Gen(indices, 6);

		m_counting = 6;
		m_draw = true;
		t[0]->changesakak();
	}

	else if (KeyManager::GetInstance()->GetbuttonDown('3'))
	{

		unsigned int indices[] =
		{
			
			0, 1, 5,
			0, 5, 4,
		};

		m_vao.Gen();
		m_vbo.Gen(vertex, sizeof(vertex));
		layout.Push<float>(3);
		layout.Push<float>(3);
		m_vao.AddBuffer(m_vbo, layout);
		m_ibo.Gen(indices, 6);

		m_counting = 6;
		m_draw = true;
		t[0]->changesakak();
	}

	else if (KeyManager::GetInstance()->GetbuttonDown('4'))
	{

		unsigned int indices[] =
		{

			2, 6, 7,
			2, 7, 3,
		};

		m_vao.Gen();
		m_vbo.Gen(vertex, sizeof(vertex));
		layout.Push<float>(3);
		layout.Push<float>(3);
		m_vao.AddBuffer(m_vbo, layout);
		m_ibo.Gen(indices, 6);

		m_counting = 6;
		m_draw = true;
		t[0]->changesakak();
	}

	else if (KeyManager::GetInstance()->GetbuttonDown('5'))
	{

		unsigned int indices[] =
		{
			0, 1, 2,
			0, 2, 3,
			4, 6, 5,
			4, 7, 6,
		};

		m_vao.Gen();
		m_vbo.Gen(vertex, sizeof(vertex));
		layout.Push<float>(3);
		layout.Push<float>(3);
		m_vao.AddBuffer(m_vbo, layout);
		m_ibo.Gen(indices, 12);

		m_counting = 12;
		m_draw = true;
		t[0]->changesakak();
	}

	else if (KeyManager::GetInstance()->GetbuttonDown('6'))
	{

		unsigned int indices[] =
		{
			//윗면
			0, 1, 2,
			0, 2, 3,

			//밑면
			4, 6, 5,
			4, 7, 6,

			//뒷면
			0, 3, 7,
			0, 7, 4,

			//앞면
			1, 5, 6,
			1, 6, 2,

			//왼면
			0, 1, 5,
			0, 5, 4,

			//오른면
			2, 6, 7,
			2, 7, 3,
		};

		m_vao.Gen();
		m_vbo.Gen(vertex, sizeof(vertex));
		layout.Push<float>(3);
		layout.Push<float>(3);
		m_vao.AddBuffer(m_vbo, layout);
		m_ibo.Gen(indices, 36);

		m_counting = 36;
		m_draw = true;
		t[0]->changesakak();
	}
	else if (KeyManager::GetInstance()->GetbuttonDown('c'))
	{

		vector<pair<vec3, vec3>> v;
		{
			vec3 temp1 = { static_cast<int>(0),static_cast<int>(1),static_cast<int>(2) };
			vec3 temp2 = { static_cast<int>(0),static_cast<int>(2),static_cast<int>(3) };
			v.push_back({ temp1,temp2 });
		}
		{
			vec3 temp1 = { static_cast<int>(4),static_cast<int>(6),static_cast<int>(5) };
			vec3 temp2 = { static_cast<int>(4),static_cast<int>(7),static_cast<int>(6) };
			v.push_back({ temp1,temp2 });
		}
		{
			vec3 temp1 = { static_cast<int>(0),static_cast<int>(3),static_cast<int>(7) };
			vec3 temp2 = { static_cast<int>(0),static_cast<int>(7),static_cast<int>(4) };
			v.push_back({ temp1,temp2 });
		}
		{
			vec3 temp1 = { static_cast<int>(1),static_cast<int>(5),static_cast<int>(6) };
			vec3 temp2 = { static_cast<int>(1),static_cast<int>(6),static_cast<int>(2) };
			v.push_back({ temp1,temp2 });
		}
		{
			vec3 temp1 = { static_cast<int>(0),static_cast<int>(1),static_cast<int>(5) };
			vec3 temp2 = { static_cast<int>(0),static_cast<int>(5),static_cast<int>(4) };
			v.push_back({ temp1,temp2 });
		}
		{
			vec3 temp1 = { static_cast<int>(2),static_cast<int>(6),static_cast<int>(7) };
			vec3 temp2 = { static_cast<int>(2),static_cast<int>(7),static_cast<int>(3) };
			v.push_back({ temp1,temp2 });
		}

		srand(time(nullptr));
		int num = rand() % 6;
		vec3 v1 = v[num].first;
		vec3 v2 = v[num].second;
		v.erase(v.begin() + num);

		int num2 = rand() % 5;
		vec3 v3 = v[num2].first;
		vec3 v4 = v[num2].second;


		unsigned int indices[] =
		{
			v1.x,v1.y,v1.z,
			v2.x,v2.y, v2.z,
			v3.x,v3.y,v3.z,
			v4.x,v4.y,v4.z
		};


		m_vao.Gen();
		m_vbo.Gen(vertex, sizeof(vertex));
		layout.Push<float>(3);
		layout.Push<float>(3);
		m_vao.AddBuffer(m_vbo, layout);

		m_ibo.Gen(indices, 12);

		m_counting = 12;

		v.clear();
		m_draw = true;
		t[0]->changesakak();
	}

	

}

void p14::Render()
{
	if (m_draw)
	{
		m_vao.Bind();
		glDrawElements(GL_TRIANGLES, m_counting, GL_UNSIGNED_INT, 0);
	}
}

#include "pch.h"
#include "p13.h"


p13::p13()
{
	
}

p13::~p13()
{

}

void p13::Init()
{
	m_center = { 0,0 };
	m_size = { 0.4f,0.2f };

	m_position = new float[12];

	float position[12] =
	{
		m_center.x - m_size.x , m_center.y + m_size.y , 0,  //0
		m_center.x - m_size.x , m_center.y - m_size.y , 0,  //1
		m_center.x + m_size.x , m_center.y - m_size.y , 0,  //2
		m_center.x + m_size.x , m_center.y + m_size.y , 0,  //3
	};

	float color[9]
	{
		1.0f,0,0,
		1.0f,0,0,
		1.0f,0,0
	};

	memcpy(m_position, position, 12 * sizeof(float));

	m_vao.Gen();
	m_vbo.Gen(m_position, 12 * sizeof(float));
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
	glEnableVertexAttribArray(0);

	m_vbo2.Gen(color, 9 * sizeof(float));
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
	glEnableVertexAttribArray(1);

}



void p13::Update()
{
	Pos mouse_pos = MouseManager::GetInstance()->GetMousePos();
	int num = checkbox();
	bool click = MouseManager::GetInstance()->Getboolclick();

	if (click)
	{
		if (num == 1) // 1��и� �۾�
		{
			m_position[0] = mouse_pos.x;
			m_position[1] = mouse_pos.y;
		}

		else if (num == 2) // 2��и� �۾�
		{
			m_position[9] = mouse_pos.x;
			m_position[10] = mouse_pos.y;
		}

		else if (num == 3) //3��и� �۾�
		{
			m_position[3] = mouse_pos.x;
			m_position[4] = mouse_pos.y;
		}
		else if (num == 4) //4��и� �۾�
		{
			m_position[6] = mouse_pos.x;
			m_position[7] = mouse_pos.y;
		}
		else if(num==0)
		{
		
			Pos diff = MouseManager::GetInstance()->GetDiff();

			m_position[0] += diff.x;
			m_position[3] += diff.x;
			m_position[6] += diff.x;
			m_position[9] += diff.x;

			m_position[1] += diff.y;
			m_position[4] += diff.y;
			m_position[7] += diff.y;
			m_position[10] += diff.y;

		}
	}

	m_vao.Bind();
	m_vbo.Gen(m_position, 12 * sizeof(float));
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
	glEnableVertexAttribArray(0);


}

void p13::Render()
{

	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
}



int p13::checkbox()
{
	Pos mouse_pos = MouseManager::GetInstance()->GetMousePos();

	float size = 0.1f; //�ٿ���ڽ� ũ������

	// 1��и�
	//////////////////////////////////////////////////////////////////



	float Top = { m_position[1] + size };
	float Left = { m_position[0] - size };
	float RIGHT = { m_position[0] + size };
	float Bottom = { m_position[1] - size };

	if (Left < mouse_pos.x && mouse_pos.x < RIGHT && mouse_pos.y < Top && mouse_pos.y > Bottom)
	{
		return 1;
	}


	// 3��и� 
	//////////////////////////////////////////////////////////////////


	Top = { m_position[4] + size };
	Left = { m_position[3] - size };
	RIGHT = { m_position[3] + size };
	Bottom = { m_position[4] - size };

	if (Left < mouse_pos.x && mouse_pos.x < RIGHT && mouse_pos.y < Top && mouse_pos.y > Bottom)
	{
		return 3;
	}



	// 4��и� 
	////////////////////////////////////////////////////////////////////



	Top = { m_position[7] + size };
	Left = { m_position[6] - size };
	RIGHT = { m_position[6] + size };
	Bottom = { m_position[7] - size };

	if (Left < mouse_pos.x && mouse_pos.x < RIGHT && mouse_pos.y < Top && mouse_pos.y > Bottom)
	{
		return 4;
	}



	// 2��и�  
	//////////////////////////////////////////////////////////////////



	Top = { m_position[10] + size };
	Left = { m_position[9] - size };
	RIGHT = { m_position[9] + size };
	Bottom = { m_position[10] - size };

	if (Left < mouse_pos.x && mouse_pos.x < RIGHT && mouse_pos.y < Top && mouse_pos.y > Bottom)
	{
		return 2;
	}

	//

	 Top = { m_position[1] + size };
	 Left = { m_position[0] - size };
	 RIGHT = { m_position[6] + size };
	 Bottom = { m_position[4] - size };
	 if (Left < mouse_pos.x && mouse_pos.x < RIGHT && mouse_pos.y < Top && mouse_pos.y > Bottom)
	 {
		 return 0;
	 }

}

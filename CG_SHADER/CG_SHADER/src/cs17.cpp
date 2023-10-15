#include "pch.h"
#include "cs17.h"

void cs17::Init()
{
	line.Init();
	cube.Init(vec3(0, 0, 0), 0.1f, 0);
	spiral.Init();

	c1.x = -0.5f;
	c1.y = 0.4f;
	c1.z = 0;

	c2.x = 0.5f;
	c2.y = 0.4f;
	c2.z = 0;
}

void cs17::Update()
{
	if (start_zigzag)
	{
		zigzag();
	}

	if (start_t_animation)
	{
		t_animation();
	}
}

void cs17::Render()
{
	line.Render();

	auto &v =ObjectManager::GetInstance()->Get_Shader();

	{
		auto s1 = glm::scale(glm::mat4(1.0f), glm::vec3(c1.m_size, c1.m_size, c1.m_size)); // 원점 중심에대한신축
		auto s2 = glm::scale(glm::mat4(1.0f), glm::vec3(c1.m_size2, c1.m_size2, c1.m_size2)); // 자기 중심에대한신축
		auto r1 = glm::rotate(glm::mat4(1.0f), glm::radians(c1.dx), glm::vec3(1.0f, 0, 0)); //공전
		auto r2 = glm::rotate(glm::mat4(1.0f), glm::radians(c1.dy), glm::vec3(0, 1.0f, 0)); //공전
		auto r3 = glm::rotate(glm::mat4(1.0f), glm::radians(c1.dz), glm::vec3(1.0f, 0.8f, -1.0f)); //공전
		auto trans = glm::translate(glm::mat4(1.0f), glm::vec3(c1.x, c1.y, c1.z));
		auto result = s1 * r3 * r1 * r2 * trans * s2;
		v[0]->SetUniformMat4f("u_model", result);
		cube.Render();
	}

	{
		auto s1 = glm::scale(glm::mat4(1.0f), glm::vec3(c2.m_size, c2.m_size, c2.m_size)); // 원점 중심에대한신축
		auto s2 = glm::scale(glm::mat4(1.0f), glm::vec3(c2.m_size2, c2.m_size2, c2.m_size2)); // 자기 중심에대한신축
		auto r1 = glm::rotate(glm::mat4(1.0f), glm::radians(c2.dx), glm::vec3(1.0f, 0, 0));//공전
		auto r2 = glm::rotate(glm::mat4(1.0f), glm::radians(c2.dy), glm::vec3(0, 1.0f, 0)); //공전
		auto r3 = glm::rotate(glm::mat4(1.0f), glm::radians(c2.dz), glm::vec3(1.0f, 0.8f, -1.0f)); //공전
		auto trans = glm::translate(glm::mat4(1.0f), glm::vec3(c2.x, c2.y, c1.z));
		auto result = s1 * r3 * r1 * r2 * trans * s2;
		v[0]->SetUniformMat4f("u_model", result);
		cl.Render();
	}



	{

		if (start_zigzag)
		{
			auto r3 = glm::rotate(glm::mat4(1.0f), glm::radians(69.0f), glm::vec3(1.0f, 0.8f, -1.0f));
			auto trans = glm::translate(glm::mat4(1.0f), glm::vec3(-0.1f, 0, 0));
			auto result = r3 * trans;

			v[0]->SetUniformMat4f("u_model", result);
			spiral.Render();
		}
	}




}

void cs17::key_call_back(unsigned char key, int x, int y)
{
	cs17::GetInstance()->update_key(key ,x ,y);
}

void cs17::update_key(unsigned char key, int x, int y)
{

	if (key == 'x')
	{
		c1.dx += 3.0f;
		c2.dx += 3.0f;
	}
	if (key == 'y')
	{

		c1.dy += 3.0f;
		c2.dy += 3.0f;
	}
	if (key == 'z')
	{
		c1.dz += 3.0f;
		c2.dz += 3.0f;
	}

	//자기중심에 대한신축
	if (key == '1')
	{

		c1.m_size2 += 0.1f;
		c2.m_size2 += 0.1f;
	}

	if (key == '2')
	{
	
		c1.m_size2 -= 0.1f;
		c2.m_size2 -= 0.1f;
	}

	//원점에대한신축
	if (key == '3')
	{

		c1.m_size += 0.1f;
		c2.m_size += 0.1f;
	}

	if (key == '4')
	{
		c1.m_size -= 0.1f;
		c2.m_size -= 0.1f;
	}


	if (key == 'r')
	{
		start_zigzag = true;
	}


	if (key == 's')
	{
		reset();
	}
	
	if (key == 't')
	{
		start_t_animation = true;
	}


	

	glutPostRedisplay();
}

void cs17::zigzag()
{


	if (!init_zigzag)
	{
		reset();

		c1.x = 0;
		c1.y = 0;
		c1.z = 0;
		
		c2.x = 0.1f;
		c2.y = 0;
		c2.z = 0;

		init_zigzag = true;
	}


	c1.dz = 69.0f;
	c1.x += radius * cos(degreesToRadians(radian));
	c1.y += radius * sin(degreesToRadians(radian));


	c2.dz = 69.0f;
	c2.x += radius * cos(degreesToRadians(radian));
	c2.y += radius * sin(degreesToRadians(radian));

	radius += 0.00007f;
	radian += 4.0f;


	if (radian > 4000)
	{
		init_zigzag = false;
		start_zigzag = false;
		radius = 0;
		radian = 0;
		reset();
		glutPostRedisplay();
		return;
	}

	glutPostRedisplay();

}

void cs17::t_animation()
{

	if (!init_t)
	{
		//현재값을 임시저장함 (되돌아가야함)
		temp.dx = c1.dx;
		temp.dy = c1.dy;
		temp.dz = c1.dz;
		temp.x = c1.x;
		temp.y = c1.y;
		temp.z = c1.z;
		init_t = true;
	}
	

	//원점에 진입한순간 을 체크함
	if (abs(0 - c1.dx) < 2.0f && abs(0 - c1.dy) < 2.0f && abs(0 - c1.dz) < 2.0f && abs(0 - c1.x) < 0.01f
		&& abs(0 - c1.y) < 0.01f && abs(0 - c1.z) < 0.01f)
	{
		stap = true;
		next_step = true;
	}


	if (next_step)
	{
		if (abs(temp.dx - c1.dx) < 2.0f && abs(temp.dy - c1.dy) < 2.0f && abs(temp.dz - c1.dz) < 2.0f && abs(temp.x - c1.x) < 0.01f
			&& abs(temp.y - c1.y) < 0.01f && abs(temp.z - c1.z) < 0.01f)
		{
			stap = false;
			next_step = false;
			init_t = false;
			start_t_animation = false;
			return;
		}
	}


	if (stap == false)
	{
		if (c1.dx >= 0)
		{
			c1.dx -= 1.0f;
		}
		else
		{
			c1.dx += 1.0f;
		}

		if (c1.dy >= 0)
		{
			c1.dy -= 1.0f;
		}
		else
		{
			c1.dy += 1.0f;
		}
		if (c1.dz >= 0)
		{
			c1.dz -= 1.0f;
		}
		else
		{
			c1.dz += 1.0f;
		}

		if (c1.x >= 0)
		{
			c1.x -= 0.001f;
		}
		else
		{
			c1.x += 0.001f;
		}

		if (c1.y >= 0)
		{
			c1.y -= 0.001f;
		}
		else
		{
			c1.y += 0.001f;
		}
		if (c1.z >= 0)
		{
			c1.z -= 0.001f;
		}
		else
		{
			c1.z += 0.001f;
		}
	}

	

	if (next_step)
	{
		if (temp.dx >= c1.dx)
		{
			c1.dx += 1.0f;
		}
		else
		{
			c1.dx -= 1.0f;
		}

		if (temp.dy >= c1.dy)
		{
			c1.dy += 1.0f;
		}
		else
		{
			c1.dy -= 1.0f;
		}

		if (temp.dz >= c1.dz)
		{
			c1.dz += 1.0f;
		}
		else
		{
			c1.dz -= 1.0f;
		}


		if (temp.x > c1.x)
		{
			c1.x += 0.001f;
		}
		else
		{
			c1.x -= 0.001f;
		}

		if (temp.y > c1.y)
		{
			c1.y += 0.001f;
		}
		else
		{
			c1.y -= 0.001f;
		}

		if (temp.z > c1.z)
		{
			c1.z += 0.001f;
		}
		else
		{
			c1.z -= 0.001f;
		}
	}






}

void cs17::reset()
{

	 c1.m_size = 1.0f; //원점에대한 신축
	 c1.m_size2 = 1.0f; //자기중심에대한 신축
	 c1.dx = 0;
	 c1.dy = 0;
	 c1.dz = 0;
	
	 c1.x = -0.5f;
	 c1.y = 0.4f;
	 c1.z = 0;


	 c2.m_size = 1.0f; //원점에대한 신축
	 c2.m_size2 = 1.0f; //자기중심에대한 신축
	 c2.dx = 0;
	 c2.dy = 0;
	 c2.dz = 0;

	 c2.x = 0.5f;
	 c2.y = 0.4f;
	 c2.z = 0;

}

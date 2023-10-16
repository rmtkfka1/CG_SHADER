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


	if (start_j_animation)
	{
		j_animation();
	}

	if (start_k_animation)
	{
		k_animation();
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

		/*if (c1.dx > 360.0f)
		{
			c1.dx = 0;
		}
		if (c2.dx > 360.0f)
		{
			c2.dx = 0;
		}*/
	}
	if (key == 'y')
	{

		c1.dy += 3.0f;
		c2.dy += 3.0f;

	/*	if (c1.dy > 360.0f)
		{
			c1.dy = 0;
		}
		if (c2.dy > 360.0f)
		{
			c2.dy = 0;
		}*/
	}
	if (key == 'z')
	{
		c1.dz += 3.0f;
		c2.dz += 3.0f;


	/*	if (c1.dz > 360.0f)
		{
			c1.dz = 0;
		}
		if (c2.dz > 360.0f)
		{
			c2.dz = 0;
		}*/
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
		if (start_zigzag)
		{
			return;
		}

		start_zigzag = true;
	}


	if (key == 's')
	{
		reset();
	}
	
	if (key == 't')
	{
		if (start_t_animation)
		{
			return;
		}
		start_t_animation = true;
	}

	if (key == 'j')
	{

		if (start_j_animation)
		{
			return;
		}

		start_j_animation = true;
	}
	if (key == 'k')
	{
		if (start_k_animation)
		{
			return;
		}

		start_k_animation = true;
	}

	


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
	if (!start_t_animation)
	{
		return;
	}

	if (finish && finish2)
	{
		finish = false;
		finish2 = false;
		start_t_animation = false;
	}

	
	t_cube_animation();

	t_cl_animation();
	

}

void cs17::t_cube_animation()
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

void cs17::t_cl_animation()
{

	if (!init_t2)
	{
		//현재값을 임시저장함 (되돌아가야함)
		temp2.dx = c2.dx;
		temp2.dy = c2.dy;
		temp2.dz = c2.dz;
		temp2.x = c2.x;
		temp2.y = c2.y;
		temp2.z = c2.z;
		init_t2 = true;
	}

	//원점에 진입한순간 을 체크함
	if (abs(0 - c2.dx) < 2.0f && abs(0 - c2.dy) < 2.0f && abs(0 - c2.dz) < 2.0f && abs(0 - c2.x) < 0.01f
		&& abs(0 - c2.y) < 0.01f && abs(0 - c2.z) < 0.01f)
	{
		stap2 = true;
		next_step2 = true;
	}


	if (next_step2)
	{
		if (abs(temp2.dx - c2.dx) < 2.0f && abs(temp2.dy - c2.dy) < 2.0f && abs(temp2.dz - c2.dz) < 2.0f && abs(temp2.x - c2.x) < 0.01f
			&& abs(temp2.y - c2.y) < 0.01f && abs(temp2.z - c2.z) < 0.01f)
		{
			stap2 = false;
			next_step2 = false;
			init_t2 = false;
			finish2 = true;
			return;
		}
	}


	if (stap2 == false)
	{
		if (c2.dx >= 0)
		{
			c2.dx -= 1.0f;
		}
		else
		{
			c2.dx += 1.0f;
		}

		if (c2.dy >= 0)
		{
			c2.dy -= 1.0f;
		}
		else
		{
			c2.dy += 1.0f;
		}
		if (c2.dz >= 0)
		{
			c2.dz -= 1.0f;
		}
		else
		{
			c2.dz += 1.0f;
		}

		if (c2.x >= 0)
		{
			c2.x -= 0.001f;
		}
		else
		{
			c2.x += 0.001f;
		}

		if (c2.y >= 0)
		{
			c2.y -= 0.001f;
		}
		else
		{
			c2.y += 0.001f;
		}
		if (c2.z >= 0)
		{
			c2.z -= 0.001f;
		}
		else
		{
			c2.z += 0.001f;
		}
	}



	if (next_step2)
	{
		if (temp2.dx >= c2.dx)
		{
			c2.dx += 1.0f;
		}
		else
		{
			c2.dx -= 1.0f;
		}

		if (temp2.dy >= c2.dy)
		{
			c2.dy += 1.0f;
		}
		else
		{
			c2.dy -= 1.0f;
		}

		if (temp2.dz >= c2.dz)
		{
			c2.dz += 1.0f;
		}
		else
		{
			c2.dz -= 1.0f;
		}


		if (temp2.x > c2.x)
		{
			c2.x += 0.001f;
		}
		else
		{
			c2.x -= 0.001f;
		}

		if (temp2.y > c2.y)
		{
			c2.y += 0.001f;
		}
		else
		{
			c2.y -= 0.001f;
		}

		if (temp2.z > c2.z)
		{
			c2.z += 0.001f;
		}
		else
		{
			c2.z -= 0.001f;
		}
	}
}

void cs17::j_animation()
{

	if (j_init == false)
	{
		j_temp1.x = c1.x;
		j_temp1.y = c1.y;
		j_temp1.z = c1.z;

		j_temp2.x = c2.x;
		j_temp2.y = c2.y;
		j_temp2.z = c2.z;

		j_init = true;
	}

	static int frameCount = 0;

	if (frameCount < 100)
	{

		float t = static_cast<float>(frameCount) / 100;
		c1.x = (1 - t) * c1.x + t * j_temp2.x;
		c1.y = (1 - t) * c1.y + t * j_temp2.y;
		c1.z = (1 - t) * c1.z + t * j_temp2.z;


		c2.x = (1 - t) * c2.x + t * j_temp1.x;
		c2.y = (1 - t) * c2.y + t * j_temp1.y;
		c2.z = (1 - t) * c2.z + t * j_temp1.z;

		frameCount++;
		if (frameCount == 100)
		{
			j_init = false;
			frameCount = 0;
			start_j_animation = false;
		}
		
	}

}
void cs17::k_animation()
{
	static int frameCount = 0;
	if (k_init == false)
	{
		k_temp1.x = c1.x;
		k_temp1.y = c1.y;
		k_temp1.z = c1.z;

		k_temp2.x = c2.x;
		k_temp2.y = c2.y;
		k_temp2.z = c2.z;
		k_init = true;
	}


	float t = static_cast<float>(frameCount) / 100;

	c1.x = (1 - t) * c1.x + t * k_temp2.x;
	c1.y = (1 - t) * c1.y + t * k_temp2.y;
	c1.z = (1 - t) * c1.z + t * k_temp2.z;


	c2.x = (1 - t) * c2.x + t * k_temp1.x;
	c2.y = (1 - t) * c2.y + t * k_temp1.y;
	c2.z = (1 - t) * c2.z + t * k_temp1.z;


	c1.dx += 3.6f;
	c1.dy += 3.6f;
	c1.dz += 3.6f;
	c2.dx += 3.6f;
	c2.dy += 3.6f;
	c2.dz += 3.6f;

	frameCount++;
	if (frameCount == 100)
	{
		k_init = false;
		frameCount = 0;
		start_k_animation = false;
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

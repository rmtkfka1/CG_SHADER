#include "pch.h"
#include "cs18.h"

void cs18::Init()
{
	
	
	rect.Init();
	line.Init();


	glEnable(GL_DEPTH_TEST);


}

void cs18::Update()
{
	
	dt =TimeManager::GetInstance()->GetDeltaTime();
	camera_speed += 0.1f * dt; //사실은 스피드가 아니라 라디안개념

	keyhandle();

	t_animation();
	y_animation();
	f_animation();
	s_animation();
	b_animation();
}

void cs18::Render()
{

	auto& v = ObjectManager::GetInstance()->Get_Shader();
	////////////////////////////////////////////////////////
	auto simple = glm::mat4(1.0f);
	v[0]->SetUniformMat4f("u_model", simple);
	line.Render();
	//////////////////////////////////////////////////////////

	//왼쪽
	{
		auto rotate = glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(0, 1.0f, 0));
		auto trans = glm::translate(glm::mat4(1.0f), glm::vec3(-5.0f, 0, 0));
		//자전을 위한 로테이트 변수추가
		auto rotate_y = glm::rotate(glm::mat4(1.0f), glm::radians(y_degree), glm::vec3(0, 1.0f, 0));
		auto trans_anim = glm::translate(glm::mat4(1.0f), glm::vec3(0, s_dt, 0));
		auto result = rotate_y * trans_anim * trans * rotate;
		v[0]->SetUniformMat4f("u_model", result);
		rect.Render();
	}
	//////////////////////////////////////////////////////////
	//오른쪽
	{
		auto rotate = glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(0, 1.0f, 0));
		auto trans = glm::translate(glm::mat4(1.0f), glm::vec3(5.0f, 0, 0));
		//자전을 위한 로테이트 변수추가
		auto rotate_y = glm::rotate(glm::mat4(1.0f), glm::radians(y_degree), glm::vec3(0, 1.0f, 0));
		//뚜껑위로 여는거
		auto trans_anim = glm::translate(glm::mat4(1.0f), glm::vec3(0, s_dt, 0));

		auto result =  rotate_y*trans_anim *trans * rotate;
		v[0]->SetUniformMat4f("u_model", result);
		rect.Render();
	}
	//////////////////////////////////////////////////////////
	//앞면
	{
	
		auto trans = glm::translate(glm::mat4(1.0f), glm::vec3(0,-5.0f, 5.0f));
		auto trans2 = glm::translate(glm::mat4(1.0f), glm::vec3(0,5.0f, 0));
		//공전을 위한 로테이트 변수추가
		auto rotate_y = glm::rotate(glm::mat4(1.0f), glm::radians(y_degree), glm::vec3(0, 1.0f, 0));
		// 앞면 뚜겅열어삐애니메이션 변수추가
		auto rotate_anim = glm::rotate(glm::mat4(1.0f), glm::radians(f_degree), glm::vec3(1.0f, 0, 0));
		auto result = rotate_y * trans * rotate_anim * trans2;
		v[0]->SetUniformMat4f("u_model", result);
		rect.Render();
	}

	////////////////////////////////////////////////////////////
    //뒷면
	{
		auto trans = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, -5.0f));
		//자전을 위한 로테이트 변수추가
		auto rotate_y = glm::rotate(glm::mat4(1.0f), glm::radians(y_degree), glm::vec3(0, 1.0f, 0));

		//animation 을 위한 변수추가
		auto scale = glm::scale(glm::mat4(1.0f), glm::vec3(b_dt, b_dt, b_dt));
		auto result = rotate_y  *trans * scale;

		v[0]->SetUniformMat4f("u_model", result);
		rect.Render();
	}
	//아래면
	{
		auto rotate = glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(1.0f, 0, 0));
		auto trans = glm::translate(glm::mat4(1.0f), glm::vec3(0, -5.0f, 0));

		//자전을 위한 로테이트 변수추가
		auto rotate_y = glm::rotate(glm::mat4(1.0f), glm::radians(y_degree), glm::vec3(0, 1.0, 0));

		auto result =trans * rotate_y *rotate;
		v[0]->SetUniformMat4f("u_model", result);
		rect.Render();
	}
	//윗면
	{
		auto rotate = glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(1.0f, 0, 0));
		auto trans = glm::translate(glm::mat4(1.0f), glm::vec3(0, 5.0f, 0));
		//애니메이션을 위한 로테이트 하기위한 변수추가
		auto rotate_anim = glm::rotate(glm::mat4(1.0f), glm::radians(t_degree), glm::vec3(1.0f, 0, 0));

		//자전을 위한 로테이트 변수추가
		auto rotate_y = glm::rotate(glm::mat4(1.0f), glm::radians(y_degree), glm::vec3(0, 1.0, 0));

		auto result = trans * rotate_y* rotate_anim  *rotate;
		v[0]->SetUniformMat4f("u_model", result);
		rect.Render();
	}


	///카메라 셋팅
	float angle = camera_speed;
	auto x =  sinf(angle) * 30.0f;
	auto z =  cosf(angle) * 30.0f;

	glm::mat4 view = glm::mat4(1.0f);
	glm::vec3 cameraPos = glm::vec3(x, 20.0f,z); //--- 카메라 위치
	glm::vec3 cameraDirection = glm::vec3(0.0f, 0.0f, 0.0f); //--- 카메라 바라보는 방향
	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f); //--- 카메라 위쪽 방향
	view = glm::lookAt(cameraPos, cameraDirection, cameraUp);
	v[0]->SetUniformMat4f("u_view", view);

	//프로젝션
	v[0]->SetUniformMat4f("u_proj",matrix::GetInstance()->GetProjection());

}

void cs18::keyhandle()
{
	if (KeyManager::GetInstance()->GetbuttonDown(KeyType::T))
	{
		start_t_anim = !start_t_anim;
	}

	if (KeyManager::GetInstance()->GetbuttonDown(KeyType::Y))
	{
		start_y_anim = !start_y_anim;
	}

	if (KeyManager::GetInstance()->GetbuttonDown(KeyType::F))
	{
		start_f_anim = !start_f_anim;
	}
	if (KeyManager::GetInstance()->GetbuttonDown(KeyType::S))
	{
		start_s_anim = !start_s_anim;
	}
	if (KeyManager::GetInstance()->GetbuttonDown(KeyType::B))
	{
		start_b_anim = !start_b_anim;
	}
}

void cs18::y_animation()
{
	if (start_y_anim == false)
	{
		return;
	}

	y_degree += 100.0f * dt;
}

void cs18::t_animation()
{

	if (start_t_anim == false)
	{
		return;
	}

	if (t_degree > 360.0f)
	{
		t_degree = 0;
		start_t_anim = false;
	}
	
	t_degree += 100.0f * dt;
}

void cs18::f_animation()
{

	if (start_f_anim == false)
	{
		return;
	}

	if (f_open)
	{

		f_degree += 100.0f * dt;

		if (f_degree > 90.0f)
		{
			f_open = false;
			start_f_anim = false;
		}

	}

	if (!f_open)
	{
		f_degree -= 100.0f * dt;
		
		if (f_degree < 0)
		{
			f_open = true;
			start_f_anim = false;
		}
	}
}

void cs18::s_animation()
{
	if (start_s_anim == false)
	{
		return;
	}

	if (s_open)
	{
		s_dt += 5.0f * dt;

		if (s_dt > 10.0f)
		{
			s_open = false;
			start_s_anim = false;
		}
	}

	if (!s_open)
	{
		s_dt -= 5.0f * dt;

		if (s_dt < 0)
		{
			s_open = true;
			start_s_anim = false;
		}
	}
	

	
}

void cs18::b_animation()
{
	if (start_b_anim == false)
	{
		return;
	}

	

	if (b_open)
	{
		b_dt -= 0.5f * dt;

		if (b_dt < 0)
		{
			b_open = false;
			start_b_anim = false;
		}
	}

	if (!b_open)
	{
		b_dt += 0.5f * dt;

		if (b_dt > 1.0f)
		{
			b_open = true;
			start_b_anim = false;
		}
	}


}

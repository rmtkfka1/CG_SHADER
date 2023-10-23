#include "pch.h"
#include "ex20.h"

#include "Body.h"
#include "Line.h"
#include "Bottom.h"

void ex20::Init()
{
	line = new Line;
	line->Init();

	body = new Body;
	body->Init();

	bottom = new Bottom;
	bottom->Init();

}

void ex20::Update()
{

	dt =TimeManager::GetInstance()->GetDeltaTime();
	HandleKey();
	b_animation();
	v_animation();
	m_animation();
	n_animation();
	x_animation();
	animation_1();
	animation_2();
	animation_e();
	animation_r();
	t_animation();
}

void ex20::Render()
{
	auto v = ObjectManager::GetInstance()->Get_Shader();

	v[0]->SetUniformMat4f("u_model", matrix::GetInstance()->GetSimple());
	line->Render();




	//////////////////////////////////////////
	bottom->Render();

	//몸체그리기
	v[0]->SetUniformMat4f("u_model", matrix::GetInstance()->GetTranslation(0.0f+b_dx, 2.0f, 0));
	body->Render();


	//위에 작은 몸체그리기
	{
		auto rotate = matrix::GetInstance()->GetRotate(m_dx, 0, 1.0f, 0);
		auto trans = matrix::GetInstance()->GetTranslation(0.0f+ b_dx, 5.0f, 0);
		auto scale = matrix::GetInstance()->GetScale(0.5f, 0.5f, 0.5f);
		auto result = trans * scale * rotate;
		v[0]->SetUniformMat4f("u_model", result);
		body->Render();

	}

	//왼쪽 포신 만들기 
	{
		auto trans2 = matrix::GetInstance()->GetTranslation(dx_e, 0, 0);
		auto rotate = matrix::GetInstance()->GetRotate(-dx_1, 0, 1.0f, 0);
		auto trans = matrix::GetInstance()->GetTranslation(-3.5f+ b_dx, 0.0f, 3.0f);
		auto scale = matrix::GetInstance()->GetScale(0.2f, 1.0f, 1.0f); // 즉 포신의 크기는 x:2 , y:3, z:10
		auto result =  trans2* trans* rotate * scale;
		v[0]->SetUniformMat4f("u_model", result);
		body->Render();
	}
	//오른쪽 포신 만들기 
	{
		auto trans2 = matrix::GetInstance()->GetTranslation(-dx_e, 0, 0);
		auto rotate = matrix::GetInstance()->GetRotate(dx_1, 0, 1.0f, 0);
		auto trans = matrix::GetInstance()->GetTranslation(3.5f+ b_dx, 0.0f, 3.0f);
		auto scale = matrix::GetInstance()->GetScale(0.2f, 1.0f, 1.0f); // 즉 포신의 크기는 x:2 , y:3, z:10
		auto result = trans2 *trans *rotate * scale;
		v[0]->SetUniformMat4f("u_model", result);
		body->Render();
	}

	//왼쪽 눈깔 만들기
	{

		auto rotate_t = matrix::GetInstance()->GetRotate(t_dx, 1.0f, 0, 0);
		auto m_rotate = matrix::GetInstance()->GetRotate(m_dx, 0, 1.0f, 0);
		auto trans = matrix::GetInstance()->GetTranslation(-1.0f+ b_dx, 6.0f, 0);
		auto rotate = matrix::GetInstance()->GetRotate(90.0f, 1.0f, 0, 0);
		auto sclae = matrix::GetInstance()->GetScale(0.1f, 0.3f, 0.1f);
		v[0]->SetUniformMat4f("u_model", trans* m_rotate * rotate_t * sclae * rotate);
		body->Render();
	}

	//오른쪽 눈깔 만들기
	{

		auto rotate_t = matrix::GetInstance()->GetRotate(-t_dx, 1.0f, 0, 0);
		auto m_rotate = matrix::GetInstance()->GetRotate(m_dx, 0, 1.0f, 0);
		auto trans = matrix::GetInstance()->GetTranslation(1.0f+ b_dx, 6.0f, 0);
		auto rotate = matrix::GetInstance()->GetRotate(90.0f, 1.0f, 0, 0);
		auto sclae = matrix::GetInstance()->GetScale(0.1f, 0.3f, 0.1f);
		v[0]->SetUniformMat4f("u_model", trans * m_rotate * rotate_t * sclae * rotate);
		body->Render();
	}




	//////////////////////////////////////////////
	/*카메라, 투영 설정*/





	if (camera_bingle == false)
	{

		if (camera_auto_rotate)
		{

			camera_rotate_dx = sinf(camera_angle) * 100.0f;
			camera_rotate_dz = cosf(camera_angle) * 100.0f;

			glm::mat4 view = glm::mat4(1.0f);
			glm::vec3 cameraPos = glm::vec3(camera_rotate_dx, camera_dy, camera_rotate_dz); //--- 카메라 위치
			glm::vec3 cameraDirection = glm::vec3(0.0f, 0.0f, 0.0f); //--- 카메라 바라보는 방향
			glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f); //--- 카메라 위쪽 방향
			view = glm::lookAt(cameraPos, cameraDirection, cameraUp);
			camera_angle += 1.0f * dt;
			v[0]->SetUniformMat4f("u_view", view);

		}

		else
		{

			if (move_xy)
			{



				v[0]->SetUniformMat4f("u_view",
					matrix::GetInstance()->GetCamera(glm::vec3(camera_dx, camera_dy, camera_dz), glm::vec3(0, 0, 0)));


			}

			else
			{
				camera_rotate_dx = sinf(camera_angle) * 100.0f;
				camera_rotate_dz = cosf(camera_angle) * 100.0f;
				glm::mat4 view = glm::mat4(1.0f);
				glm::vec3 cameraPos = glm::vec3(camera_rotate_dx, camera_dy, camera_rotate_dz); //--- 카메라 위치
				glm::vec3 cameraDirection = glm::vec3(0.0f, 0.0f, 0.0f); //--- 카메라 바라보는 방향
				glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f); //--- 카메라 위쪽 방향
				view = glm::lookAt(cameraPos, cameraDirection, cameraUp);
				v[0]->SetUniformMat4f("u_view", view);

			}

		}
	}

	else
	{

		camera_revolve_dx =  camera_dx +sinf(camera_angle2) * 100.0f;
		camera_revolve_dz =  camera_dz +cosf(camera_angle2) * 100.0f;
		glm::mat4 view = glm::mat4(1.0f);
		glm::vec3 cameraPos = glm::vec3(camera_dx, camera_dy, camera_dz); //--- 카메라 위치
		glm::vec3 cameraDirection = glm::vec3(camera_revolve_dx, 0, camera_revolve_dz); //--- 카메라 바라보는 방향
		glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f); //--- 카메라 위쪽 방향
		view = glm::lookAt(cameraPos, cameraDirection, cameraUp);
		v[0]->SetUniformMat4f("u_view", view);

	}




	

	v[0]->SetUniformMat4f("u_proj",
	matrix::GetInstance()->GetProjection());

	glEnable(GL_DEPTH);

}

void ex20::HandleKey()
{


	if (KeyManager::GetInstance()->Getbutton(KeyType::A))
	{
		camera_auto_rotate = false;
		move_xy = true;
		camera_dx -= 20.0f * dt;
		camera_bingle = false;
	}

	if (KeyManager::GetInstance()->Getbutton(KeyType::D))
	{
		camera_auto_rotate = false;
		move_xy = true;
		camera_dx += 20.0f * dt;
		camera_bingle = false;
	}

	if (KeyManager::GetInstance()->Getbutton(KeyType::W))
	{
		camera_auto_rotate = false;
		move_xy = true;
		camera_dz -= 20.0f * dt;
		camera_bingle = false;
	}

	if (KeyManager::GetInstance()->Getbutton(KeyType::S))
	{
		camera_auto_rotate = false;
		move_xy = true;
		camera_dz += 20.0f * dt;
		camera_bingle = false;
	}

	if (KeyManager::GetInstance()->Getbutton(KeyType::F))
	{
		camera_auto_rotate = false;
		move_xy = false;
		camera_angle += 1.0f * dt;
		camera_bingle = false;
	}

	if (KeyManager::GetInstance()->Getbutton(KeyType::G))
	{
		camera_auto_rotate = false;
		move_xy = false;
		camera_angle -= 1.0f * dt;
		camera_bingle = false;

	}

	if (KeyManager::GetInstance()->GetbuttonDown(KeyType::Z))
	{
		camera_auto_rotate = !camera_auto_rotate;
	}

	if (KeyManager::GetInstance()->GetbuttonDown(KeyType::B))
	{
		b_anim = !b_anim;
	}

	if (KeyManager::GetInstance()->GetbuttonDown(KeyType::V))
	{
		v_anim = !v_anim;
	}

	if (KeyManager::GetInstance()->GetbuttonDown(KeyType::M))
	{
		m_anim = !m_anim;
	}

	if (KeyManager::GetInstance()->GetbuttonDown(KeyType::N))
	{
		n_anim = !n_anim;
	}

	if (KeyManager::GetInstance()->GetbuttonDown(KeyType::X))
	{
		camera_bingle = !camera_bingle;
	}

	if (KeyManager::GetInstance()->GetbuttonDown(KeyType::ONE))
	{
		anim_1 = !anim_1;
	}

	if (KeyManager::GetInstance()->GetbuttonDown(KeyType::TWO))
	{
		anim_2 = !anim_2;
	}

	if (KeyManager::GetInstance()->GetbuttonDown(KeyType::E))
	{
		anim_e = !anim_e;
	}

	if (KeyManager::GetInstance()->GetbuttonDown(KeyType::R))
	{

		anim_r = !anim_r;

	}
	if (KeyManager::GetInstance()->GetbuttonDown(KeyType::T))
	{
		t_anim = !t_anim;
	}


	if (KeyManager::GetInstance()->GetbuttonDown(KeyType::THREE))
	{
		v_anim = false;
		b_anim = false;
		n_anim = false;
		m_anim = false;
		anim_1 = false;

		anim_2 = false;
		anim_e = false;

		anim_r = false;
		t_anim = false;
		camera_bingle = false;
		camera_auto_rotate = false;
	}

	if (KeyManager::GetInstance()->GetbuttonDown(KeyType::FOUR))
	{
		b_dx = 0;
		v_anim = false;
		b_anim = false;
		m_dx = 0;
		n_anim = false;
		m_anim = false;
		m_animation();
		n_animation();
		dx_1 = 0;
		anim_1 = false;

		anim_2 = false;
		dx_e = 0;
		anim_e = false;

		anim_r = false;
		t_anim = false;
		t_dx = 0;
		camera_bingle = false;
		x_animation();
		camera_revolve_dx;
		camera_revolve_dz;
		camera_angle2 = 260.0f;
		camera_auto_rotate = false;
		move_xy = true;
		camera_angle = 0.0f;
		camera_rotate_dx;
		camera_rotate_dz;
		camera_dx = 0.0f;
		camera_dy = 50.0f;
		camera_dz = 100.0f;
	}


}

void ex20::b_animation()
{
	if (!b_anim)
	{
		return;
	}

	b_dx += 10.0f * dt;
}

void ex20::v_animation()
{

	if (!v_anim)
	{
		return;
	}

	b_dx -= 10.0f * dt;
}

void ex20::m_animation()
{
	if(m_anim==false)
	{
		return;
	}

	m_dx += 100.0f * dt;
}

void ex20::n_animation()
{
	if (n_anim == false)
	{
		return;
	}

	m_dx -= 100.0f * dt;
}

void ex20::animation_1() //팔벌리기
{
	if (!anim_1)
	{
		return;
	}


	//만약 이동거리가 존재한다면 그만큼 먼저 보간을해준다.
	if (dx_e >= 0)
	{
		dx_e -= 10.0f * dt;

		
	}

	if (abs(dx_e) < 0.2f)
	{
		start_1 = true;
	}

	dx_1 += 100.0f * dt;

	if (start_1)
	{
		if (dx_1 >= 90.0f)
		{
			anim_1 = false;
			start_1 = false;
			return;
		}
	}
}

void ex20::animation_2() //팔오므리기
{

	if (!anim_2)
	{
		return;
	}


	//만약 이동거리가 존재한다면 그만큼 먼저 보간을해준다.
	if (dx_e >= 0)
	{
		dx_e -= 40.0f * dt;

	}

	if (abs(dx_e) < 0.2f)
	{
		start_1 = true;
	}

	dx_1 -= 100.0f * dt;

	if (start_1)
	{
		if (dx_1 <= 0)
		{
			anim_2 = false;
			start_1 = false;
			return;
		}
	}
	
}

void ex20::animation_e()
{
	if (!anim_e)
	{
		return;
	}

	if (dx_1 > 0)
	{
		dx_1 -= 40.0f * dt;
	}

	if (abs(dx_1) < 1.0f)
	{
		start_e = true;
	}


	if (start_e)
	{
		dx_e += 10.0f * dt;

		if (dx_e > 3.5f)
		{
			start_e = false;
			anim_e = false;
			return;
		}
	}


}

void ex20::animation_r()
{
	if (!anim_r)
	{
		return;
	}

	if (dx_1 > 0)
	{
		dx_1 -= 30.0f * dt;
	}

	if (abs(dx_1) < 1.0f)
	{
		start_e = true;
	}

	if (start_e)
	{
		dx_e -= 10.0f * dt;

		if (dx_e < 0)
		{
			start_e = false;
			anim_r = false;
			return;
		}
	}




}

void ex20::t_animation()
{
	if (!t_anim)
	{
		return;
	}

	static int count = 0; 

	if (count % 2 == 0)
	{
		t_dx += 50.0f * dt;

		if (t_dx > 90.0f)
		{
			count++;
		}
	}

	else
	{

		t_dx -= 50.0f * dt;

		if (t_dx < 0)
		{
			count++;
		}

	}
}



void ex20::x_animation()
{

	if (camera_bingle == false)
	{
		return;
	}

	camera_angle2 += 1.0f * dt;

}

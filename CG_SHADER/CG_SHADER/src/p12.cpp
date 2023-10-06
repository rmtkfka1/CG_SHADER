#include "pch.h"
#include "p12.h"

std::random_device rd;
std::mt19937 dre(rd());
std::uniform_real_distribution<float> uid(-0.9f, 0.9f);
std::uniform_real_distribution<float> uuid(-1.0f, 1.0f);

p12::p12()
{
}

p12::~p12()
{

	for (int i = 0; i < v_shape.size(); ++i)
	{
		delete[] v_shape[i]->Position;
		delete[] v_shape[i]->Color;

		delete v_shape[i];
	}

	v_shape.clear();
}

void p12::Init()
{
	make_dot();
	make_line();
	make_triangle();
	make_rectangle();
	make_okak();
};

void p12::Update()
{

	update_Pos();
	play_animation();

}

void p12::Render()
{

	for (int i = 0; i < v_shape.size(); ++i)
	{
		v_shape[i]->vao.Bind();
		
		if (v_shape[i]->Type == Type::dot)
		{
			glPointSize(10);
			glDrawArrays(GL_POINTS, 0, 1);
		}

		if (v_shape[i]->Type == Type::line)
		{
			glLineWidth(5);
			glDrawArrays(GL_LINES, 0, 2);
		}

		if (v_shape[i]->Type == Type::triangle)
		{
			glDrawArrays(GL_TRIANGLES, 0, 3);
		}

		if (v_shape[i]->Type == Type::rectangle)
		{
			glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
		}

		if (v_shape[i]->Type == Type::okak)
		{
			glDrawArrays(GL_TRIANGLE_FAN, 0, 7);
		}
	}

}

void p12::update_collusion(Shape* shape)
{
	Pos mouse_pos = MouseManager::GetInstance()->GetMousePos();
	float Top;
	float Left;
	float RIGHT;
	float Bottom;

	float Top2;
	float Left2;
	float RIGHT2;
	float Bottom2;

	if (shape->Type == Type::dot)
	{
		Top = { shape->Position[1] + 0.02f };
		Left = { shape->Position[0] - 0.02f };
		RIGHT = { shape->Position[0] + 0.02f };
		Bottom = { shape->Position[1] - 0.02f };
	}

	else if (shape->Type == Type::line)
	{
		Top = { shape->Position[1] + 0.04f };
		Left = { shape->Position[0] - 0.04f };
		RIGHT = { shape->Position[3] + 0.04f };
		Bottom = { shape->Position[4] - 0.04f };
	}

	else if (shape->Type == Type::triangle)
	{
		Top = { shape->Position[1]  };
		Left = { shape->Position[3]  };
		RIGHT = { shape->Position[6] };
		Bottom = { shape->Position[4] };
	}

	else if (shape->Type == Type::rectangle)
	{
		Top = { shape->Position[1] };
		Left = { shape->Position[0] };
		RIGHT = { shape->Position[6] };
		Bottom = { shape->Position[7] };
	}


	else if (shape->Type == Type::okak)
	{
		Top = { shape->Position[4] };
		Left = { shape->Position[6] };
		RIGHT = { shape->Position[15] };
		Bottom = { shape->Position[10] };
	}

	/////////////////////////////////////////////////////////////////////////////////////
	for (int i = 0; i < v_shape.size(); ++i)
	{
		if (shape == v_shape[i])
		{
			continue;
		}

		if (v_shape[i]->Type == Type::dot)
		{
			Top2 = v_shape[i]->Position[1] + 0.02f;
			Left2 = v_shape[i]->Position[0] - 0.02f;
			RIGHT2 = v_shape[i]->Position[0] + 0.02f;
			Bottom2 = v_shape[i]->Position[1] - 0.02f;
		}

		else if (v_shape[i]->Type == Type::line)
		{
			Top2      =  v_shape[i]->Position[1] + 0.02f ;
			Left2     =	  v_shape[i]->Position[0] - 0.02f ;
			RIGHT2    =	  v_shape[i]->Position[3] + 0.02f;
			Bottom2   =	  v_shape[i]->Position[4] - 0.02f;
		}


		else if (v_shape[i]->Type == Type::triangle)
		{
			Top2 = { v_shape[i]->Position[1] };
			Left2 = { v_shape[i]->Position[3] };
			RIGHT2 = { v_shape[i]->Position[6] };
			Bottom2 = { v_shape[i]->Position[4] };

		}

		else if (v_shape[i]->Type == Type::rectangle)
		{
			Top2 = { v_shape[i]->Position[1] };
			Left2 = { v_shape[i]->Position[0] };
			RIGHT2 = { v_shape[i]->Position[6] };
			Bottom2 = { v_shape[i]->Position[7] };

		}
		
		else if (v_shape[i]->Type == Type::okak)
		{
			Top2 = { v_shape[i]->Position[4] };
			Left2 = { v_shape[i]->Position[6] };
			RIGHT2 = { v_shape[i]->Position[15] };
			Bottom2 = { v_shape[i]->Position[10] };
		}

		if (Left < RIGHT2 && RIGHT > Left2 &&
			Top > Bottom2 && Bottom < Top2)
		{

			int counting =(shape->Count + v_shape[i]->Count)% 6;

			if (counting == 0)
			{
				counting = 1;
			}
			
			if (counting == 1) //점다시 생성
			{
				delete[] shape->Position;
				shape->Type = Type::dot;
				shape->Count = 1;
				shape->Position = new float[3];

				shape->Position[0] = mouse_pos.x;
				shape->Position[1] = mouse_pos.y;
				shape->Position[2] = 0;
				
				shape->vao.Bind();
				shape->vbo.Gen(shape->Position, 3 * sizeof(float));
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
				glEnableVertexAttribArray(0);

			}

			else if (counting == 2) //선 다시생성
			{
			
				shape->Size = 0.1f;
				delete[] shape->Position;
				shape->Type = Type::line;
				shape->Count = 2;
				shape->Position = new float[6];

				shape->Position[0] = mouse_pos.x - shape->Size;
				shape->Position[1] = mouse_pos.y;
				shape->Position[2] = 0;

				shape->Position[3] = mouse_pos.x + shape->Size;
				shape->Position[4] = mouse_pos.y;
				shape->Position[5] = 0;

				shape->vao.Bind();
				shape->vbo.Gen(shape->Position, 6 * sizeof(float));
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
				glEnableVertexAttribArray(0);
			}

			else if (counting == 3) //삼각형 다시생성
			{
				shape->Size = 0.1f;
				delete[] shape->Position;
				shape->Type = Type::triangle;
				shape->Count = 3;
				shape->Position = new float[9];

				shape->Center.x = mouse_pos.x;
				shape->Center.y = mouse_pos.y;

				shape->Position[0] = shape->Center.x;
				shape->Position[1] = shape->Center.y + shape->Size;
				shape->Position[2] = 0;

				shape->Position[3] = shape->Center.x - shape->Size;
				shape->Position[4] = shape->Center.y - shape->Size;
				shape->Position[5] = 0;

				shape->Position[6] = shape->Center.x + shape->Size;
				shape->Position[7] = shape->Center.y - shape->Size;
				shape->Position[8] = 0;

				shape->vao.Bind();
				shape->vbo.Gen(shape->Position, 9 * sizeof(float));
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
				glEnableVertexAttribArray(0);

			}

			else if (counting == 4) //사각형 다시생성
			{
				shape->Size = 0.1f;
				delete[] shape->Position;
				shape->Type = Type::rectangle;
				shape->Count = 4;
				shape->Position = new float[12];
				shape->Center.x = mouse_pos.x;
				shape->Center.y = mouse_pos.y;

				shape->Position[0] = shape->Center.x - shape->Size;
				shape->Position[1] = shape->Center.y + shape->Size;
				shape->Position[2] = 0;

				shape->Position[3] = shape->Center.x - shape->Size;
				shape->Position[4] = shape->Center.y - shape->Size;
				shape->Position[5] = 0;

				shape->Position[6] = shape->Center.x + shape->Size;
				shape->Position[7] = shape->Center.y - shape->Size;
				shape->Position[8] = 0;

				shape->Position[9] = shape->Center.x + shape->Size;
				shape->Position[10] = shape->Center.y + shape->Size;
				shape->Position[11] = 0;

				shape->vao.Bind();
				shape->vbo.Gen(shape->Position, 12 * sizeof(float));
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
				glEnableVertexAttribArray(0);
			}

			else if (counting == 5)
			{
				shape->Size = 0.1f;
				delete[] shape->Position;
				shape->Type = Type::okak;
				shape->Count = 5;
				shape->Position = new float[21];


				shape->Center.x = mouse_pos.x;
				shape->Center.y = mouse_pos.y;

				shape->Position[0] = shape->Center.x;
				shape->Position[1] = shape->Center.y;
				shape->Position[2] = 0;

				//1
				shape->Position[3] = shape->Center.x;
				shape->Position[4] = shape->Center.y + shape->Size;
				shape->Position[5] = 0;

				//2
				shape->Position[6] = shape->Center.x - shape->Size;
				shape->Position[7] = shape->Center.y;
				shape->Position[8] = 0;

				//3
				shape->Position[9] = shape->Center.x - shape->Size / 2;
				shape->Position[10] = shape->Center.y - shape->Size;
				shape->Position[11] = 0;

				//4
				shape->Position[12] = shape->Center.x + shape->Size / 2;
				shape->Position[13] = shape->Center.y - shape->Size;
				shape->Position[14] = 0;

				//5
				shape->Position[15] = shape->Center.x + shape->Size;
				shape->Position[16] = shape->Center.y;
				shape->Position[17] = 0;

				//1
				shape->Position[18] = shape->Center.x;
				shape->Position[19] = shape->Center.y + shape->Size;
				shape->Position[20] = 0;

				shape->vao.Bind();
				shape->vbo.Gen(shape->Position, 21 * sizeof(float));
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
				glEnableVertexAttribArray(0);
			}
			
			delete v_shape[i]->Position;
			delete v_shape[i]->Color;
			delete v_shape[i];
			v_shape[i] = nullptr;
			v_shape.erase(std::remove(v_shape.begin(), v_shape.end(), nullptr), v_shape.end());

			shape->animation = true;
			return;
		}
	}
}


void p12::update_Pos()
{

	Pos mouse_pos = MouseManager::GetInstance()->GetMousePos();
	bool click = MouseManager::GetInstance()->Getboolclick();


	if (click)
	{
		for (int i = 0; i < v_shape.size(); ++i)
		{
			/*if (v_shape[i]->animation)
			{
				continue;
			}*/

			if (v_shape[i]->Type == Type::dot)
			{
				float size = 0.04f;

				float Top = { v_shape[i]->Position[1] + size };
				float Left = { v_shape[i]->Position[0] - size };
				float RIGHT = { v_shape[i]->Position[0] + size };
				float Bottom = { v_shape[i]->Position[1] - size };

				if (Left < mouse_pos.x && mouse_pos.x < RIGHT && mouse_pos.y < Top && mouse_pos.y > Bottom)
				{
					v_shape[i]->Position[0] = mouse_pos.x;
					v_shape[i]->Position[1] = mouse_pos.y;

					v_shape[i]->vao.Bind();
					v_shape[i]->vbo.Gen(v_shape[i]->Position, 3 * sizeof(float));
					glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
					glEnableVertexAttribArray(0);

					update_collusion(v_shape[i]);
				}
			}

			else if (v_shape[i]->Type == Type::line)
			{
				float size = 0.04f;

				float Top =     { v_shape[i]->Position[1] + size };
				float Left =    { v_shape[i]->Position[0] - size };
				float RIGHT =   { v_shape[i]->Position[3] + size };
				float Bottom =  { v_shape[i]->Position[4] - size };

				if (Left < mouse_pos.x && mouse_pos.x < RIGHT && mouse_pos.y < Top && mouse_pos.y > Bottom)
				{
					v_shape[i]->Position[0] = mouse_pos.x - v_shape[i]->Size;
					v_shape[i]->Position[1] = mouse_pos.y;

					v_shape[i]->Position[3] = mouse_pos.x + v_shape[i]->Size;
					v_shape[i]->Position[4] = mouse_pos.y;

					v_shape[i]->vao.Bind();
					v_shape[i]->vbo.Gen(v_shape[i]->Position, 6 * sizeof(float));
					glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
					glEnableVertexAttribArray(0);
			
					update_collusion(v_shape[i]);
				}
			}

			else if (v_shape[i]->Type == Type::triangle)
			{
				

				float Top = { v_shape[i]->Position[1] };
				float Left = { v_shape[i]->Position[3] };
				float RIGHT = { v_shape[i]->Position[6] };
				float Bottom = { v_shape[i]->Position[4] };

				if (Left < mouse_pos.x && mouse_pos.x < RIGHT && mouse_pos.y < Top && mouse_pos.y > Bottom)
				{
					v_shape[i]->Center.x = mouse_pos.x;
					v_shape[i]->Center.y = mouse_pos.y;

					v_shape[i]->Position[0] = v_shape[i]->Center.x;
					v_shape[i]->Position[1] = v_shape[i]->Center.y + v_shape[i]->Size;
					v_shape[i]->Position[2] = 0;

					v_shape[i]->Position[3] = v_shape[i]->Center.x - v_shape[i]->Size;
					v_shape[i]->Position[4] = v_shape[i]->Center.y - v_shape[i]->Size;
					v_shape[i]->Position[5] = 0;

					v_shape[i]->Position[6] = v_shape[i]->Center.x + v_shape[i]->Size;
					v_shape[i]->Position[7] = v_shape[i]->Center.y - v_shape[i]->Size;
					v_shape[i]->Position[8] = 0;

					v_shape[i]->vao.Bind();
					v_shape[i]->vbo.Gen(v_shape[i]->Position, 9 * sizeof(float));
					glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
					glEnableVertexAttribArray(0);
			
					update_collusion(v_shape[i]);
				}
			}

			else if (v_shape[i]->Type == Type::rectangle)
			{
				

				float Top = { v_shape[i]->Position[1] };
				float Left = { v_shape[i]->Position[0] };
				float RIGHT = { v_shape[i]->Position[6] };
				float Bottom = { v_shape[i]->Position[7] };

				if (Left < mouse_pos.x && mouse_pos.x < RIGHT && mouse_pos.y < Top && mouse_pos.y > Bottom)
				{
					v_shape[i]->Center.x = mouse_pos.x;
					v_shape[i]->Center.y = mouse_pos.y;

					v_shape[i]->Position[0] = v_shape[i]->Center.x - v_shape[i]->Size;
					v_shape[i]->Position[1] = v_shape[i]->Center.y + v_shape[i]->Size;
					v_shape[i]->Position[2] = 0;

					v_shape[i]->Position[3] = v_shape[i]->Center.x - v_shape[i]->Size;
					v_shape[i]->Position[4] = v_shape[i]->Center.y - v_shape[i]->Size;
					v_shape[i]->Position[5] = 0;

					v_shape[i]->Position[6] = v_shape[i]->Center.x + v_shape[i]->Size;
					v_shape[i]->Position[7] = v_shape[i]->Center.y - v_shape[i]->Size;
					v_shape[i]->Position[8] = 0;

					v_shape[i]->Position[9] = v_shape[i]->Center.x + v_shape[i]->Size;
					v_shape[i]->Position[10] = v_shape[i]->Center.y + v_shape[i]->Size;
					v_shape[i]->Position[11] = 0;

					v_shape[i]->vao.Bind();
					v_shape[i]->vbo.Gen(v_shape[i]->Position, 12 * sizeof(float));
					glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
					glEnableVertexAttribArray(0);
			
					update_collusion(v_shape[i]);
				}
			}

			else if (v_shape[i]->Type == Type::okak)
			{

				float Top = { v_shape[i]->Position[4] };
				float Left = { v_shape[i]->Position[6] };
				float RIGHT = { v_shape[i]->Position[15] };
				float Bottom = { v_shape[i]->Position[10] };

				if (Left < mouse_pos.x && mouse_pos.x < RIGHT && mouse_pos.y < Top && mouse_pos.y > Bottom)
				{
					v_shape[i]->Center.x = mouse_pos.x;
					v_shape[i]->Center.y = mouse_pos.y;

					v_shape[i]->Position[0] = v_shape[i]->Center.x;
					v_shape[i]->Position[1] = v_shape[i]->Center.y;
					v_shape[i]->Position[2] = 0;

					//1
					v_shape[i]->Position[3] = v_shape[i]->Center.x;
					v_shape[i]->Position[4] = v_shape[i]->Center.y + v_shape[i]->Size;
					v_shape[i]->Position[5] = 0;

					//2
					v_shape[i]->Position[6] = v_shape[i]->Center.x - v_shape[i]->Size;
					v_shape[i]->Position[7] = v_shape[i]->Center.y;
					v_shape[i]->Position[8] = 0;

					//3
					v_shape[i]->Position[9] = v_shape[i]->Center.x - v_shape[i]->Size / 2;
					v_shape[i]->Position[10] = v_shape[i]->Center.y - v_shape[i]->Size;
					v_shape[i]->Position[11] = 0;

					//4
					v_shape[i]->Position[12] = v_shape[i]->Center.x + v_shape[i]->Size / 2;
					v_shape[i]->Position[13] = v_shape[i]->Center.y - v_shape[i]->Size;
					v_shape[i]->Position[14] = 0;

					//5
					v_shape[i]->Position[15] = v_shape[i]->Center.x + v_shape[i]->Size;
					v_shape[i]->Position[16] = v_shape[i]->Center.y;
					v_shape[i]->Position[17] = 0;

					//1
					v_shape[i]->Position[18] = v_shape[i]->Center.x;
					v_shape[i]->Position[19] = v_shape[i]->Center.y + v_shape[i]->Size;
					v_shape[i]->Position[20] = 0;

					v_shape[i]->vao.Bind();
					v_shape[i]->vbo.Gen(v_shape[i]->Position, 21 * sizeof(float));
					glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
					glEnableVertexAttribArray(0);
				
					update_collusion(v_shape[i]);
				}
			}
		}
	}

}

Pos p12::reflection_vector(Pos P, Pos N)
{
	// P + 2N ( -P 내적 N) 
	Pos result;
	result.x = P.x + 2 * N.x * ((-P.x * N.x + -P.y * N.y));
	result.y = P.y + 2 * N.y * ((-P.x * N.x + -P.y * N.y));

	return result;
}




void p12::play_animation()
{

	Pos Top = { 0,-1 };
	Pos bottom = { 0,1 };
	Pos left = { 1,0 };
	Pos right = { -1, 0 };


	for (int i = 0; i < v_shape.size(); ++i)
	{
		if (!v_shape[i]->animation)
		{
			continue;
		}

		if (v_shape[i]->Type == Type::dot)
		{
			v_shape[i]->Position[0] += v_shape[i]->going_vector.x;
			v_shape[i]->Position[1] += v_shape[i]->going_vector.y;
			v_shape[i]->Position[2] = 0;

			if (v_shape[i]->Position[0] + v_shape[i]->going_vector.x > 1.0f)
			{
				v_shape[i]->going_vector = reflection_vector(v_shape[i]->going_vector, right);
			}

			else if (v_shape[i]->Position[0] + v_shape[i]->going_vector.x < -1.0f)
			{
				v_shape[i]->going_vector = reflection_vector(v_shape[i]->going_vector, left);
			}

			else if (v_shape[i]->Position[1] + v_shape[i]->going_vector.y > 1.0f)
			{
				v_shape[i]->going_vector = reflection_vector(v_shape[i]->going_vector, Top);
			}

			else if (v_shape[i]->Position[1] + v_shape[i]->going_vector.y < -1.0f)
			{
				v_shape[i]->going_vector = reflection_vector(v_shape[i]->going_vector, bottom);
			}

			v_shape[i]->vao.Bind();
			v_shape[i]->vbo.Gen(v_shape[i]->Position, 3 * sizeof(float));
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
			glEnableVertexAttribArray(0);

		}


		else if (v_shape[i]->Type == Type::triangle)
		{
			v_shape[i]->Position[0] += v_shape[i]->going_vector.x;
			v_shape[i]->Position[1] += v_shape[i]->going_vector.y;
			v_shape[i]->Position[2] = 0;

			v_shape[i]->Position[3] += v_shape[i]->going_vector.x;
			v_shape[i]->Position[4] += v_shape[i]->going_vector.y;
			v_shape[i]->Position[5] = 0;

			v_shape[i]->Position[6] += v_shape[i]->going_vector.x;
			v_shape[i]->Position[7] += v_shape[i]->going_vector.y;
			v_shape[i]->Position[8] = 0;

			if (v_shape[i]->Position[6] + v_shape[i]->going_vector.x > 1.0f)
			{
				v_shape[i]->going_vector = reflection_vector(v_shape[i]->going_vector, right);
			}

			else if (v_shape[i]->Position[3] + v_shape[i]->going_vector.x < -1.0f)
			{
				v_shape[i]->going_vector = reflection_vector(v_shape[i]->going_vector, left);
			}

			else if (v_shape[i]->Position[1] + v_shape[i]->going_vector.y > 1.0f)
			{
				v_shape[i]->going_vector = reflection_vector(v_shape[i]->going_vector, Top);
			}

			else if (v_shape[i]->Position[4] + v_shape[i]->going_vector.y < -1.0f)
			{
				v_shape[i]->going_vector = reflection_vector(v_shape[i]->going_vector, bottom);
			}

			v_shape[i]->vao.Bind();
			v_shape[i]->vbo.Gen(v_shape[i]->Position, 9 * sizeof(float));
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
			glEnableVertexAttribArray(0);
		}


		else if (v_shape[i]->Type == Type::line)
		{
			v_shape[i]->Position[0] += v_shape[i]->going_vector.x;
			v_shape[i]->Position[1] += v_shape[i]->going_vector.y;
			v_shape[i]->Position[2] = 0;

			v_shape[i]->Position[3] += v_shape[i]->going_vector.x;
			v_shape[i]->Position[4] += v_shape[i]->going_vector.y;
			v_shape[i]->Position[5] = 0;


			if (v_shape[i]->Position[3] + v_shape[i]->going_vector.x > 1.0f)
			{
				v_shape[i]->going_vector = reflection_vector(v_shape[i]->going_vector, right);
			}

			else if (v_shape[i]->Position[0] + v_shape[i]->going_vector.x < -1.0f)
			{
				v_shape[i]->going_vector = reflection_vector(v_shape[i]->going_vector, left);
			}

			else if (v_shape[i]->Position[1] + v_shape[i]->going_vector.y > 1.0f)
			{
				v_shape[i]->going_vector = reflection_vector(v_shape[i]->going_vector, Top);
			}

			else if (v_shape[i]->Position[1] + v_shape[i]->going_vector.y < -1.0f)
			{
				v_shape[i]->going_vector = reflection_vector(v_shape[i]->going_vector, bottom);
			}

			v_shape[i]->vao.Bind();
			v_shape[i]->vbo.Gen(v_shape[i]->Position, 6 * sizeof(float));
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
			glEnableVertexAttribArray(0);
		}


		else if (v_shape[i]->Type == Type::rectangle)
		{
			v_shape[i]->Position[0] += v_shape[i]->going_vector.x;
			v_shape[i]->Position[1] += v_shape[i]->going_vector.y;
			v_shape[i]->Position[2] = 0;

			v_shape[i]->Position[3] += v_shape[i]->going_vector.x;
			v_shape[i]->Position[4] += v_shape[i]->going_vector.y;
			v_shape[i]->Position[5] = 0;

			v_shape[i]->Position[6] += v_shape[i]->going_vector.x;
			v_shape[i]->Position[7] += v_shape[i]->going_vector.y;
			v_shape[i]->Position[8] = 0;

			v_shape[i]->Position[9] += v_shape[i]->going_vector.x;
			v_shape[i]->Position[10] += v_shape[i]->going_vector.y;
			v_shape[i]->Position[11] = 0;


			if (v_shape[i]->Position[6] + v_shape[i]->going_vector.x > 1.0f)
			{
				v_shape[i]->going_vector = reflection_vector(v_shape[i]->going_vector, right);
			}

			else if (v_shape[i]->Position[0] + v_shape[i]->going_vector.x < -1.0f)
			{
				v_shape[i]->going_vector = reflection_vector(v_shape[i]->going_vector, left);
			}

			else if (v_shape[i]->Position[1] + v_shape[i]->going_vector.y > 1.0f)
			{
				v_shape[i]->going_vector = reflection_vector(v_shape[i]->going_vector, Top);
			}

			else if (v_shape[i]->Position[7] + v_shape[i]->going_vector.y < -1.0f)
			{
				v_shape[i]->going_vector = reflection_vector(v_shape[i]->going_vector, bottom);
			}

			v_shape[i]->vao.Bind();
			v_shape[i]->vbo.Gen(v_shape[i]->Position, 12 * sizeof(float));
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
			glEnableVertexAttribArray(0);
		}


		else if (v_shape[i]->Type == Type::okak)
		{
			//0
			v_shape[i]->Position[0] += v_shape[i]->going_vector.x;
			v_shape[i]->Position[1] += v_shape[i]->going_vector.y;
			v_shape[i]->Position[2] = 0;
			//1
			v_shape[i]->Position[3] += v_shape[i]->going_vector.x;
			v_shape[i]->Position[4] += v_shape[i]->going_vector.y;
			v_shape[i]->Position[5] = 0;
			//2
			v_shape[i]->Position[6] += v_shape[i]->going_vector.x;
			v_shape[i]->Position[7] += v_shape[i]->going_vector.y;
			v_shape[i]->Position[8] = 0;
			//3
			v_shape[i]->Position[9] += v_shape[i]->going_vector.x;
			v_shape[i]->Position[10] += v_shape[i]->going_vector.y;
			v_shape[i]->Position[11] = 0;
			//4
			v_shape[i]->Position[12] += v_shape[i]->going_vector.x;
			v_shape[i]->Position[13] += v_shape[i]->going_vector.y;
			v_shape[i]->Position[14] = 0;
			//5
			v_shape[i]->Position[15] += v_shape[i]->going_vector.x;
			v_shape[i]->Position[16] += v_shape[i]->going_vector.y;
			v_shape[i]->Position[17] = 0;
			//6
			v_shape[i]->Position[18] += v_shape[i]->going_vector.x;
			v_shape[i]->Position[19] += v_shape[i]->going_vector.y;
			v_shape[i]->Position[20] = 0;


			if (v_shape[i]->Position[15] + v_shape[i]->going_vector.x > 1.0f)
			{
				v_shape[i]->going_vector = reflection_vector(v_shape[i]->going_vector, right);
			}

			else if (v_shape[i]->Position[6] + v_shape[i]->going_vector.x < -1.0f)
			{
				v_shape[i]->going_vector = reflection_vector(v_shape[i]->going_vector, left);
			}

			else if (v_shape[i]->Position[4] + v_shape[i]->going_vector.y > 1.0f)
			{
				v_shape[i]->going_vector = reflection_vector(v_shape[i]->going_vector, Top);
			}

			else if (v_shape[i]->Position[13] + v_shape[i]->going_vector.y < -1.0f)
			{
				v_shape[i]->going_vector = reflection_vector(v_shape[i]->going_vector, bottom);
			}

			v_shape[i]->vao.Bind();
			v_shape[i]->vbo.Gen(v_shape[i]->Position, 21 * sizeof(float));
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
			glEnableVertexAttribArray(0);
		}


	}


}




void p12::make_dot()
{

	for (int i = 0; i < 3; ++i)
	{
		Shape* dot = new Shape;
		dot->Center = { uid(dre),uid(dre) };
		dot->Count = 1;
		dot->Size = 0.1f;
		dot->Type = Type::dot;

		dot->Position = new float[3];
		dot->Position[0] = dot->Center.x;
		dot->Position[1] = dot->Center.y;
		dot->Position[2] = 0;

		dot->Color = new float[9];

		float color1 = uuid(dre);
		float color2 = uuid(dre);
		float color3 = uuid(dre);

		float temp[9] =
		{
			color1,color2,color3,
			color1,color2,color3,
			color1,color2,color3,
		};

		///정점

		dot->vao.Gen();
		dot->vbo.Gen(dot->Position, 3 * sizeof(float));
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
		glEnableVertexAttribArray(0);

		///색깔
		memcpy(dot->Color, temp, 9 * sizeof(float));

		dot->vbo2.Gen(dot->Color, 9 * sizeof(float));
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
		glEnableVertexAttribArray(1);

		v_shape.push_back(dot);
	}
}

void p12::make_line()
{
	for (int i = 0; i < 3; ++i)
	{
		Shape* line = new Shape;
		line->Center = { uid(dre),uid(dre) };
		line->Count = 2;
		line->Size = 0.1f;
		line->Type = Type::line;

		line->Position = new float[6];
		line->Position[0] = line->Center.x - line->Size;
		line->Position[1] = line->Center.y ;
		line->Position[2] = 0;

		line->Position[3] = line->Center.x + line->Size;
		line->Position[4] = line->Center.y ;
		line->Position[5] = 0;

		line->Color = new float[9];

		float color1 = uuid(dre);
		float color2 = uuid(dre);
		float color3 = uuid(dre);

		float temp[9] =
		{
			color1,color2,color3,
			color1,color2,color3,
			color1,color2,color3,
		};

		//정점

		line->vao.Gen();
		line->vbo.Gen(line->Position, 6 * sizeof(float));
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
		glEnableVertexAttribArray(0);

		//색깔 
		memcpy(line->Color, temp, 9 * sizeof(float));

		line->vbo2.Gen(line->Color, 9 * sizeof(float));
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
		glEnableVertexAttribArray(1);

		v_shape.push_back(line);
	}
}

void p12::make_triangle()
{

	for (int i = 0; i < 3; ++i)
	{
		Shape* tri = new Shape;
		tri->Center = { uid(dre),uid(dre) };
		tri->Count = 3;
		tri->Size = 0.1f;
		tri->Type = Type::triangle;

		tri->Position = new float[9];

		tri->Position[0] = tri->Center.x;
		tri->Position[1] = tri->Center.y + tri->Size;
		tri->Position[2] = 0;

		tri->Position[3] = tri->Center.x - tri->Size;
		tri->Position[4] = tri->Center.y - tri->Size;
		tri->Position[5] = 0;

		tri->Position[6] = tri->Center.x + tri->Size;
		tri->Position[7] = tri->Center.y - tri->Size;
		tri->Position[8] = 0;

	

	

		tri->Color = new float[9];

		float color1 = uuid(dre);
		float color2 = uuid(dre);
		float color3 = uuid(dre);

		float temp[9] =
		{
			color1,color2,color3,
			color1,color2,color3,
			color1,color2,color3,
		};

		//정점

		tri->vao.Gen();
		tri->vbo.Gen(tri->Position, 9 * sizeof(float));
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
		glEnableVertexAttribArray(0);

		//색깔 
		memcpy(tri->Color, temp, 9 * sizeof(float));

		tri->vbo2.Gen(tri->Color, 9 * sizeof(float));
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
		glEnableVertexAttribArray(1);

		v_shape.push_back(tri);
	}

}

void p12::make_rectangle()
{

	for (int i = 0; i < 3; ++i)
	{
		Shape* rec = new Shape;
		rec->Center = { uid(dre),uid(dre) };
		rec->Count = 4;
		rec->Size = 0.1f;
		rec->Type = Type::rectangle;

		rec->Position = new float[12];

		rec->Position[0] = rec->Center.x - rec->Size;
		rec->Position[1] = rec->Center.y + rec->Size;
		rec->Position[2] = 0;

		rec->Position[3] = rec->Center.x - rec->Size;
		rec->Position[4] = rec->Center.y - rec->Size;
		rec->Position[5] = 0;

		rec->Position[6] = rec->Center.x + rec->Size;
		rec->Position[7] = rec->Center.y - rec->Size;
		rec->Position[8] = 0;

		rec->Position[9] = rec->Center.x + rec->Size;
		rec->Position[10] = rec->Center.y + rec->Size;
		rec->Position[11] = 0;


		rec->Color = new float[9];

		float color1 = uuid(dre);
		float color2 = uuid(dre);
		float color3 = uuid(dre);

		float temp[9] =
		{
			color1,color2,color3,
			color1,color2,color3,
			color1,color2,color3,
		};

		//정점

		rec->vao.Gen();
		rec->vbo.Gen(rec->Position, 12 * sizeof(float));
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
		glEnableVertexAttribArray(0);

		//색깔 
		memcpy(rec->Color, temp, 9 * sizeof(float));

		rec->vbo2.Gen(rec->Color, 9 * sizeof(float));
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
		glEnableVertexAttribArray(1);

		v_shape.push_back(rec);
	}

}

void p12::make_okak()
{
	for (int i = 0; i < 3; ++i)
	{
		Shape* okak = new Shape;
		okak->Center = { uid(dre),uid(dre) };
		okak->Count = 5;
		okak->Size = 0.1f;
		okak->Type = Type::okak;

		okak->Position = new float[21];

		//0
		okak->Position[0] = okak->Center.x;
		okak->Position[1] = okak->Center.y;
		okak->Position[2] = 0;

		//1
		okak->Position[3] = okak->Center.x;
		okak->Position[4] = okak->Center.y + okak->Size;
		okak->Position[5] = 0;

		//2
		okak->Position[6] = okak->Center.x - okak->Size;
		okak->Position[7] = okak->Center.y;
		okak->Position[8] = 0;

		//3
		okak->Position[9] = okak->Center.x - okak->Size/2;
		okak->Position[10] = okak->Center.y- okak->Size;
		okak->Position[11] = 0;

		//4
		okak->Position[12] = okak->Center.x + okak->Size/2 ;
		okak->Position[13] = okak->Center.y - okak->Size;
		okak->Position[14] = 0;

		//5
		okak->Position[15] = okak->Center.x + okak->Size ;
		okak->Position[16] = okak->Center.y ;
		okak->Position[17] = 0;

		//1
		okak->Position[18] = okak->Center.x;
		okak->Position[19] = okak->Center.y + okak->Size;
		okak->Position[20] = 0;

		okak->Color = new float[9];

		float color1 = uuid(dre);
		float color2 = uuid(dre);
		float color3 = uuid(dre);

		float temp[9] =
		{
			color1,color2,color3,
			color1,color2,color3,
			color1,color2,color3,
		};

		//정점

		okak->vao.Gen();
		okak->vbo.Gen(okak->Position, 21 * sizeof(float));
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
		glEnableVertexAttribArray(0);

		//색깔 
		memcpy(okak->Color, temp, 9 * sizeof(float));

		okak->vbo2.Gen(okak->Color, 9 * sizeof(float));
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
		glEnableVertexAttribArray(1);

		v_shape.push_back(okak);
	}
}

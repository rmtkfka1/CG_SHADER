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

void p12::make_dot()
{

	for (int i = 0; i < 3; ++i)
	{
		Shape* dot = new Shape;
		dot->Center = { uid(dre),uid(dre) };
		dot->Count = 1;
		dot->Size = 0.0f;
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

		///����

		dot->vao.Gen();
		dot->vbo.Gen(dot->Position, 3 * sizeof(float));
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
		glEnableVertexAttribArray(0);

		///����
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
		line->Position[0] = line->Center.x- line->Size;
		line->Position[1] = line->Center.y- line->Size;
		line->Position[2] = 0;

		line->Position[3] = line->Center.x+ line->Size;
		line->Position[4] = line->Center.y+ line->Size;
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

		//����

		line->vao.Gen();
		line->vbo.Gen(line->Position, 6 * sizeof(float));
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
		glEnableVertexAttribArray(0);

		//���� 
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

		tri->Position[3] = tri->Center.x + tri->Size;
		tri->Position[4] = tri->Center.y - tri->Size;
		tri->Position[5] = 0;

		tri->Position[6] = tri->Center.x - tri->Size;
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

		//����

		tri->vao.Gen();
		tri->vbo.Gen(tri->Position, 9 * sizeof(float));
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
		glEnableVertexAttribArray(0);

		//���� 
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

		//����

		rec->vao.Gen();
		rec->vbo.Gen(rec->Position, 12 * sizeof(float));
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
		glEnableVertexAttribArray(0);

		//���� 
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
		okak->Count = 4;
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

		//����

		okak->vao.Gen();
		okak->vbo.Gen(okak->Position, 21 * sizeof(float));
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
		glEnableVertexAttribArray(0);

		//���� 
		memcpy(okak->Color, temp, 9 * sizeof(float));

		okak->vbo2.Gen(okak->Color, 9 * sizeof(float));
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
		glEnableVertexAttribArray(1);

		v_shape.push_back(okak);
	}
}

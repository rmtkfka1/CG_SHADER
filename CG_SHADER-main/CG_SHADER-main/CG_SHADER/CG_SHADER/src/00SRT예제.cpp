#include "pch.h"

vector<Shader> v;
VAO vao;
VBO vbo;
IBO ibo;

float dx = 0;
float dy = 0;

float degree_x = 0;
float degree_x2 = 0;
float degree_x3 = 0;
float degree_x4 = 0;
int mode = 0;

auto t1 = glm::translate(glm::mat4(1.0f), glm::vec3(dx, dy, 0));
auto t2 = glm::translate(glm::mat4(1.0f), glm::vec3(-dx, -dy, 0));
auto r1 = glm::rotate(glm::mat4(1.0f), glm::radians(degree_x), glm::vec3(0, 1.0f, 0));
auto r2 = glm::rotate(glm::mat4(1.0f), glm::radians(degree_x2), glm::vec3(0, 1.0f, 0));
auto r3 = glm::rotate(glm::mat4(1.0f), glm::radians(-degree_x), glm::vec3(0, 1.0f, 0));
auto r4 = glm::rotate(glm::mat4(1.0f), glm::radians(-degree_x2), glm::vec3(0, 1.0f, 0));

void draw()
{
	
	glClearColor(1.0f,1.0f,1.0f,1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	t1 = glm::translate(glm::mat4(1.0f), glm::vec3(dx, dy, 0));
	r1 = glm::rotate(glm::mat4(1.0f), glm::radians(degree_x), glm::vec3(1.0f, 0, 0)); //공전
	r2 = glm::rotate(glm::mat4(1.0f), glm::radians(degree_x2), glm::vec3(1.0f, 0, 0)); //자전
	r3 = glm::rotate(glm::mat4(1.0f), glm::radians(degree_x3), glm::vec3(0, 1.0f, 0)); //공전
	r4 = glm::rotate(glm::mat4(1.0f), glm::radians(degree_x4), glm::vec3(0, 1.0f, 0)); //자전

	glm::mat4 result = glm::mat4(1.0f);

	
	result = r3*r1*t1*r2*r4; //원점에서 회전시킴(자전먼저) --> 이동 시킴 ->  공전시킴  
	

	v[0].SetUniformMat4f("u_model", result); 

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	glutSwapBuffers();
}	

void make()
{
	float position[] =
	{
		0,0.2f,0,
		-0.1f,-0.2f,0,
		0.1f,-0.2f,0
	};

	unsigned int index[] =
	{
		0,1,2,
	};

	VertexBufferLayout layout;

	vao.Gen();
	vbo.Gen(position,sizeof(position));
	layout.Push<float>(3);
	vao.AddBuffer(vbo, layout);
	ibo.Gen(index, 6);


	
}


void key(unsigned char key, int x, int y)
{


	if (key == 'w')
	{
		dy += 0.01f;
	}
	else if (key == 'a')
	{
		dx -= 0.01f;
	}
	else if (key == 'd')
	{
		dx += 0.01f;
	}
	else if (key == 's')
	{
		dy -= 0.01f;
	}
	else if (key == '1')
	{
		degree_x += 3.0f;
	}

	else if (key == '2')
	{
		degree_x2 += 3.0f;
	}

	else if (key == '3')
	{
		degree_x3 += 3.0f;
	}

	else if (key == '4')
	{
		degree_x4 += 3.0f;
	}

	glutPostRedisplay();
}


int main(int argc, char **argv)
{
	Core::GetInstance()->Init(argc, argv, 800, 800);

	Core::GetInstance()->Render(draw);
	Core::GetInstance()->Keyboard(key);

	Shader shader("res/shader/Shader2.vs", "res/shader/Shader2.fs");
	shader.Bind();
	make();
	
	v.push_back(shader);

	glm::mat4 result = glm::mat4(1.0f);
	v[0].SetUniformMat4f("u_model", result);  // Update the transformation matrix in your shader
	while (1)
	{
		glutMainLoopEvent();

	}





}




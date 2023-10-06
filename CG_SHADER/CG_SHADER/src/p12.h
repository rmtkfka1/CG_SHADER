#pragma once

enum class Type
{
	dot,
	line,
	triangle,
	rectangle,
	okak,
};

struct Shape
{
	Pos Center;
	float Size;
	float* Position; //�����ǰ�
	float* Color; //����
	VAO vao; 
	VBO vbo; //����
	VBO vbo2; //���� 
	Type Type; //��� 
	int Count;  //�������� 
};

class p12 
{


public:
	p12();
	~p12();

	void Init();
	void Update(); //�浹������ �ִϸ��̼� ������ �����ؾߵ� 
	void Render();
	
private:

	void make_dot();
	void make_line();
	void make_triangle();
	void make_rectangle();
	void make_okak();

	vector<Shape*> v_shape;


};


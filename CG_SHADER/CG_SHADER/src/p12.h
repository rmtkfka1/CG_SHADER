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
	float* Position; //포지션값
	float* Color; //색상값
	VAO vao; 
	VBO vbo; //정점
	VBO vbo2; //색상 
	Type Type; //모양 
	int Count;  //정점개수 
};

class p12 
{


public:
	p12();
	~p12();

	void Init();
	void Update(); //충돌로직과 애니메이션 로직을 구현해야됨 
	void Render();
	
private:

	void make_dot();
	void make_line();
	void make_triangle();
	void make_rectangle();
	void make_okak();

	vector<Shape*> v_shape;


};


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
	bool animation = false;
	Pos going_vector = { ((float)rand() / RAND_MAX) * (0.014f) - 0.005f,((float)rand() / RAND_MAX) * (0.014f) - 0.005f};
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


	void update_collusion(Shape* shape);
	void update_Pos();

	Pos reflection_vector(Pos P, Pos N);
	void play_animation();
	void make_dot();
	void make_line();
	void make_triangle();
	void make_rectangle();
	void make_okak();

	vector<Shape*> v_shape;


};


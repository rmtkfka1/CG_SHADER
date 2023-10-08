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
	bool animation = false;
	Pos going_vector = { ((float)rand() / RAND_MAX) * (0.014f) - 0.005f,((float)rand() / RAND_MAX) * (0.014f) - 0.005f};
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
	bool hey; //애니매이션 클릭 끄고 키기

};


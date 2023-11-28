#pragma once

class Core
{
public:

	static Core* GetInstance()
	{
		static Core mg;
		return &mg;
	}


private:
	Core();
	~Core();

public:

	void Init(int argc, char** argv,int x, int y);// argc,argv,������x,������y
	void Render(void (*funcptr)(void));// �׸��� 
	void Reshape(void (*funcptr)(int, int));
	void Keyboard(void (*funcptr)(unsigned char, int, int)); //Ű�Է� 
	void mousein(void (*funcptr)(int button, int state, int x, int y)); //���콺�Է�
	void mouse_move(void (*funcptr)(int x, int y));


	vec2 convert(int x, int y,int WINDOW_WIDTH, int WINDOW_HEIGHT);




};

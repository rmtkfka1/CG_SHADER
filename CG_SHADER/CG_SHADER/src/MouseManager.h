#pragma once







class MouseManager
{


public:
	static MouseManager* GetInstance()
	{
		static MouseManager MM;
		return &MM;
	}

	void Update();

	Pos GetMousePos() { return m_pos; }
	bool Getboolclick() { return m_click; }

private:

	static void MouseCallBack(int button ,int state , int x, int y);
	static void MousemoveCallBack(int x, int y);

	static Pos m_pos;
	static bool m_click;


};


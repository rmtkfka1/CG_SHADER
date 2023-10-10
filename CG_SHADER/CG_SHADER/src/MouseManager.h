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

<<<<<<< HEAD
	Pos& GetMousePos() const { return m_pos; }
	bool& Getboolclick() const { return m_click; }
=======
	Pos& GetDiff() const { return m_diff; }
	Pos& GetMousePos() const { return m_pos; }
	bool& Getboolclick() const { return m_click; }

>>>>>>> 1c0dca82b24112ca3d9f4281b601d6d242cf4be7

private:

	static void MouseCallBack(int button ,int state , int x, int y);
	static void MousemoveCallBack(int x, int y);

	static Pos m_pos;
	static bool m_click;
	static Pos m_diff;
	static Pos m_beforePos;

};


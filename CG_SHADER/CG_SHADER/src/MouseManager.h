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


	vec2& GetMousePos() const { return m_pos; }
	bool& Getboolclick() const { return m_click; }

	vec2& GetDiff() const { return m_diff; }



private:

	static void MouseCallBack(int button ,int state , int x, int y);
	static void MousemoveCallBack(int x, int y);

	static vec2 m_pos;
	static bool m_click;
	static vec2 m_diff;
	static vec2 m_beforePos;

};


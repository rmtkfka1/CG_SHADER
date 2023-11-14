#pragma once

class MouseManager
{


public:
	static MouseManager* GetInstance()
	{
		static MouseManager MM;
		return &MM;
	}

	void Init();


	vec2 GetMousePos() { return m_pos; }
	bool Getboolclick() { return m_click; }

	vec2 GetDiff() { return m_diff; }

	float GetXChange();
	float GetYChange();

private:

	static void MouseCallBack(int button ,int state , int x, int y);
	static void MousemoveCallBack(int x, int y);
	static void MousemoveCallBack2(int x, int y);


	 vec2 m_pos;
	 bool m_click;
	 vec2 m_diff;
	 vec2 m_beforePos;

	 float m_LastX, m_LastY; //이전 프레임의 마우스 X,Y위치 저장
	 float m_XChange, m_YChange; //이번 프레임에서 현재 프레임까지 마우스 이동량 dX, dY 저장
	 bool m_MouseFirstMoved; //마우스가 처음 움직이기 시작했는지 여부

};


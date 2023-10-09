#pragma once

class p13;

class ObjectManger
{

public:
	static ObjectManger* GetInstance()
	{
		static ObjectManger mg;
		return &mg;
	}


public:

	vector<p13*>& GetTri() { return v_p13; } //�ܺ� CPP,������Ͽ��� ���Ͱ�������//
	vector<Shader*>& GetShader() { return v_shader; } //�ܺ� CPP,������Ͽ��� ���Ͱ�������//

private:

	vector<p13*> v_p13;
	vector<Shader*> v_shader;


};